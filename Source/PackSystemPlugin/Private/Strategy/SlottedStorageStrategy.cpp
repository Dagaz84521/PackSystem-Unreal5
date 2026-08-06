#include "Strategy/SlottedStorageStrategy.h"

#include "InventoryBlueprintLibrary.h"
#include "InventoryComponent.h"
#include "InventoryOperationTags.h"
#include "Item/InventoryItemDefinition.h"
#include "Item/InventoryItemInstance.h"

namespace
{
	// Slotted Strategy 同样只生成 Mutation；真正写入、实例复制与事件广播由 Component 完成。
	FInventoryOperationPlan MakeFailedPlan(const int64 RequestedQuantity, const FGameplayTag Reason)
	{
		FInventoryOperationPlan Plan;
		Plan.RequestedQuantity = FMath::Max<int64>(0, RequestedQuantity);
		Plan.RemainingQuantity = Plan.RequestedQuantity;
		Plan.FailureReason = Reason;
		return Plan;
	}

	FInventoryEntryMutation MakeUpdateMutation(
		const FInventoryEntryHandle& Handle,
		const FInventoryEntry& Entry,
		const FInventoryEntryState& DesiredState,
		const bool bDuplicateItem = false)
	{
		FInventoryEntryMutation Mutation;
		Mutation.Type = EInventoryEntryMutationType::Update;
		Mutation.TargetEntry = Handle;
		Mutation.ExpectedState = FInventoryEntryState(Entry.ItemInstance, Entry.Quantity);
		Mutation.DesiredState = DesiredState;
		Mutation.bDuplicateItemInstance = bDuplicateItem;
		return Mutation;
	}

	int64 GetMaxStackSize(const UInventoryItemInstance* ItemInstance)
	{
		// Slot 的容量来自物品定义，并强制至少为 1，避免产生“存在但永远放不进去”的物品。
		const UInventoryItemDefinition* Definition = IsValid(ItemInstance)
			? ItemInstance->GetItemDefinition()
			: nullptr;
		return IsValid(Definition) ? FMath::Max(1, Definition->GetMaxStackSize()) : 0;
	}
}

FInventoryOperationPlan USlottedStorageStrategy::BuildAddPlan(
	const UInventoryComponent& Inventory,
	const FInventoryAddRequest& Request) const
{
	if (!IsValid(Request.InventoryItemInstance))
	{
		return MakeFailedPlan(Request.Quantity, InventoryOperationTags::InvalidItem);
	}
	if (Request.Quantity <= 0)
	{
		return MakeFailedPlan(Request.Quantity, InventoryOperationTags::InvalidQuantity);
	}

	const int64 MaxStackSize = GetMaxStackSize(Request.InventoryItemInstance);
	if (MaxStackSize <= 0)
	{
		return MakeFailedPlan(Request.Quantity, InventoryOperationTags::InvalidItem);
	}

	FInventoryOperationPlan Plan;
	Plan.RequestedQuantity = Request.Quantity;
	int64 Remaining = Request.Quantity;

	// 该局部规划器同时处理“填空格”和“补兼容堆叠”，并持续扣减 Remaining。
	auto PlanIntoEntry = [&](const FInventoryEntryHandle& Handle, const FInventoryEntry& Entry)
	{
		if (Remaining <= 0)
		{
			return;
		}
		if (Entry.IsEmpty())
		{
			const int64 Added = FMath::Min(Remaining, MaxStackSize);
			Plan.Mutations.Add(MakeUpdateMutation(
				Handle,
				Entry,
				FInventoryEntryState(Request.InventoryItemInstance, Added),
				true));
			Remaining -= Added;
			return;
		}
		if (!UInventoryBlueprintLibrary::CanStackItems(Entry.ItemInstance, Request.InventoryItemInstance))
		{
			return;
		}
		const int64 Capacity = FMath::Max<int64>(0, MaxStackSize - Entry.Quantity);
		const int64 Added = FMath::Min(Remaining, Capacity);
		if (Added > 0)
		{
			Plan.Mutations.Add(MakeUpdateMutation(
				Handle,
				Entry,
				FInventoryEntryState(Entry.ItemInstance, Entry.Quantity + Added)));
			Remaining -= Added;
		}
	};

	if (Request.TargetEntry.IsValid())
	{
		FInventoryEntry Target;
		if (!Inventory.GetEntry(Request.TargetEntry, Target))
		{
			return MakeFailedPlan(Request.Quantity, InventoryOperationTags::InvalidHandle);
		}
		if (!Target.IsEmpty()
			&& !UInventoryBlueprintLibrary::CanStackItems(Target.ItemInstance, Request.InventoryItemInstance))
		{
			return MakeFailedPlan(Request.Quantity, InventoryOperationTags::IncompatibleItem);
		}
		PlanIntoEntry(Request.TargetEntry, Target);
	}
	else
	{
		const TArray<FInventoryEntryHandle> Handles = Inventory.GetAllEntryHandles();
		// 两遍扫描是有意的：先补满已有堆叠，减少背包碎片，再按稳定格序占用空格。
		for (const FInventoryEntryHandle& Handle : Handles)
		{
			FInventoryEntry Entry;
			if (Inventory.GetEntry(Handle, Entry) && !Entry.IsEmpty())
			{
				PlanIntoEntry(Handle, Entry);
			}
		}
		for (const FInventoryEntryHandle& Handle : Handles)
		{
			if (Remaining == 0)
			{
				break;
			}
			FInventoryEntry Entry;
			if (Inventory.GetEntry(Handle, Entry) && Entry.IsEmpty())
			{
				PlanIntoEntry(Handle, Entry);
			}
		}
	}

	Plan.PlannedQuantity = Request.Quantity - Remaining;
	Plan.RemainingQuantity = Remaining;
	if (Remaining > 0)
	{
		Plan.FailureReason = InventoryOperationTags::NoCapacity;
	}
	return Plan;
}

FInventoryOperationPlan USlottedStorageStrategy::BuildRemoveMatchingPlan(
	const UInventoryComponent& Inventory,
	const UInventoryItemInstance* ItemInstance,
	const int64 Quantity) const
{
	if (!IsValid(ItemInstance))
	{
		return MakeFailedPlan(Quantity, InventoryOperationTags::InvalidItem);
	}

	FInventoryOperationPlan Plan;
	Plan.RequestedQuantity = Quantity;
	int64 Remaining = Quantity;
	for (const FInventoryEntryHandle& Handle : Inventory.GetAllEntryHandles())
	{
		FInventoryEntry Entry;
		if (!Inventory.GetEntry(Handle, Entry)
			|| !UInventoryBlueprintLibrary::CanStackItems(Entry.ItemInstance, ItemInstance))
		{
			continue;
		}

		const int64 Removed = FMath::Min(Remaining, Entry.Quantity);
		const int64 NewQuantity = Entry.Quantity - Removed;
		// Slot 数量归零时写入空状态，但 Entry 与 Handle 仍然存在。
		Plan.Mutations.Add(MakeUpdateMutation(
			Handle,
			Entry,
			NewQuantity > 0
				? FInventoryEntryState(Entry.ItemInstance, NewQuantity)
				: FInventoryEntryState()));
		Remaining -= Removed;
		if (Remaining == 0)
		{
			break;
		}
	}

	Plan.PlannedQuantity = Quantity - Remaining;
	Plan.RemainingQuantity = Remaining;
	if (Remaining > 0)
	{
		Plan.FailureReason = InventoryOperationTags::InsufficientQuantity;
	}
	return Plan;
}

FInventoryOperationPlan USlottedStorageStrategy::BuildRemoveFromEntryPlan(
	const UInventoryComponent& Inventory,
	const FInventoryEntryHandle& EntryHandle,
	const int64 Quantity) const
{
	FInventoryEntry Entry;
	if (!Inventory.GetEntry(EntryHandle, Entry))
	{
		return MakeFailedPlan(Quantity, InventoryOperationTags::InvalidHandle);
	}
	if (Entry.IsEmpty())
	{
		return MakeFailedPlan(Quantity, InventoryOperationTags::InvalidItem);
	}

	FInventoryOperationPlan Plan;
	Plan.RequestedQuantity = Quantity;
	Plan.PlannedQuantity = FMath::Min(Quantity, Entry.Quantity);
	Plan.RemainingQuantity = Quantity - Plan.PlannedQuantity;
	const int64 NewQuantity = Entry.Quantity - Plan.PlannedQuantity;
	Plan.Mutations.Add(MakeUpdateMutation(
		EntryHandle,
		Entry,
		NewQuantity > 0
			? FInventoryEntryState(Entry.ItemInstance, NewQuantity)
			: FInventoryEntryState()));
	if (Plan.RemainingQuantity > 0)
	{
		Plan.FailureReason = InventoryOperationTags::InsufficientQuantity;
	}
	return Plan;
}

FInventoryOperationPlan USlottedStorageStrategy::BuildMovePlan(
	const UInventoryComponent& Inventory,
	const FInventoryEntryHandle& SourceEntry,
	const FInventoryEntryHandle& TargetEntry,
	const int64 Quantity) const
{
	if (SourceEntry == TargetEntry)
	{
		return MakeFailedPlan(Quantity, InventoryOperationTags::NoChange);
	}

	FInventoryEntry Source;
	FInventoryEntry Target;
	if (!Inventory.GetEntry(SourceEntry, Source) || !Inventory.GetEntry(TargetEntry, Target))
	{
		return MakeFailedPlan(Quantity, InventoryOperationTags::InvalidHandle);
	}
	if (Source.IsEmpty())
	{
		return MakeFailedPlan(Quantity, InventoryOperationTags::InvalidItem);
	}

	const int64 MaxStackSize = GetMaxStackSize(Source.ItemInstance);
	if (MaxStackSize <= 0)
	{
		return MakeFailedPlan(Quantity, InventoryOperationTags::InvalidItem);
	}
	if (!Target.IsEmpty()
		&& !UInventoryBlueprintLibrary::CanStackItems(Source.ItemInstance, Target.ItemInstance))
	{
		return MakeFailedPlan(Quantity, InventoryOperationTags::IncompatibleItem);
	}

	// Move 只允许移至空格或合并兼容堆叠；不兼容物品必须显式调用 SwapEntries。
	const int64 TargetCapacity = Target.IsEmpty()
		? MaxStackSize
		: FMath::Max<int64>(0, MaxStackSize - Target.Quantity);
	const int64 Moved = FMath::Min3(Quantity, Source.Quantity, TargetCapacity);
	if (Moved <= 0)
	{
		return MakeFailedPlan(Quantity, InventoryOperationTags::NoCapacity);
	}

	FInventoryOperationPlan Plan;
	Plan.RequestedQuantity = Quantity;
	Plan.PlannedQuantity = Moved;
	Plan.RemainingQuantity = Quantity - Moved;

	const int64 SourceRemainder = Source.Quantity - Moved;
	Plan.Mutations.Add(MakeUpdateMutation(
		SourceEntry,
		Source,
		SourceRemainder > 0
			? FInventoryEntryState(Source.ItemInstance, SourceRemainder)
			: FInventoryEntryState()));

	if (Target.IsEmpty())
	{
		// 部分拆分时源堆仍持有原实例，因此目标必须复制；整堆移动则直接转移原实例。
		Plan.Mutations.Add(MakeUpdateMutation(
			TargetEntry,
			Target,
			FInventoryEntryState(Source.ItemInstance, Moved),
			SourceRemainder > 0));
	}
	else
	{
		Plan.Mutations.Add(MakeUpdateMutation(
			TargetEntry,
			Target,
			FInventoryEntryState(Target.ItemInstance, Target.Quantity + Moved)));
	}

	if (Plan.RemainingQuantity > 0)
	{
		Plan.FailureReason = TargetCapacity < FMath::Min(Quantity, Source.Quantity)
			? InventoryOperationTags::NoCapacity
			: InventoryOperationTags::InsufficientQuantity;
	}
	return Plan;
}

FInventoryOperationPlan USlottedStorageStrategy::BuildSwapPlan(
	const UInventoryComponent& Inventory,
	const FInventoryEntryHandle& FirstEntry,
	const FInventoryEntryHandle& SecondEntry) const
{
	if (FirstEntry == SecondEntry)
	{
		return MakeFailedPlan(1, InventoryOperationTags::NoChange);
	}

	FInventoryEntry First;
	FInventoryEntry Second;
	if (!Inventory.GetEntry(FirstEntry, First) || !Inventory.GetEntry(SecondEntry, Second))
	{
		return MakeFailedPlan(1, InventoryOperationTags::InvalidHandle);
	}
	const FInventoryEntryState FirstState(First.ItemInstance, First.Quantity);
	const FInventoryEntryState SecondState(Second.ItemInstance, Second.Quantity);
	if (FirstState == SecondState)
	{
		return MakeFailedPlan(1, InventoryOperationTags::NoChange);
	}

	// 两条 Update 在同一个 Plan 中提交，所以交换是全有或全无。
	FInventoryOperationPlan Plan;
	Plan.RequestedQuantity = 1;
	Plan.PlannedQuantity = 1;
	Plan.Mutations.Add(MakeUpdateMutation(FirstEntry, First, SecondState));
	Plan.Mutations.Add(MakeUpdateMutation(SecondEntry, Second, FirstState));
	return Plan;
}

FInventoryOperationPlan USlottedStorageStrategy::BuildClearPlan(const UInventoryComponent& Inventory) const
{
	// 清空只重置非空格；固定 Slot 数量及每个格子的 Handle 都保持不变。
	FInventoryOperationPlan Plan;
	for (const FInventoryEntryHandle& Handle : Inventory.GetAllEntryHandles())
	{
		FInventoryEntry Entry;
		if (!Inventory.GetEntry(Handle, Entry) || Entry.IsEmpty())
		{
			continue;
		}
		Plan.Mutations.Add(MakeUpdateMutation(Handle, Entry, FInventoryEntryState()));
		if (Entry.Quantity > MAX_int64 - Plan.RequestedQuantity)
		{
			Plan.RequestedQuantity = MAX_int64;
		}
		else
		{
			Plan.RequestedQuantity += Entry.Quantity;
		}
	}
	Plan.PlannedQuantity = Plan.RequestedQuantity;
	return Plan;
}
