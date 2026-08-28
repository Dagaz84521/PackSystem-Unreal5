#include "Inventory/Aggregate/AggregateInventoryComponent.h"

#include "Core/InventoryBlueprintLibrary.h"

UAggregateInventoryComponent::UAggregateInventoryComponent()
{
}

FInventoryQuantityOperationResult UAggregateInventoryComponent::AddItem(
	const FInventoryItemPayload& Payload)
{
	FInventoryQuantityOperationResult Result;
	Result.RequestedQuantity = FMath::Max<int64>(0, Payload.Quantity);
	Result.RemainingQuantity = Result.RequestedQuantity;

	if (!Payload.IsValid())
	{
		return Result;
	}

	// AddItem 不修改调用者传入的数据；失败时通过 OutputPayload 返回尚未加入的全部物品。
	Result.OutputPayload = Payload;

	FInventoryEntryHandle EntryHandle = FindCompatibleEntry(Payload.ItemInstance);
	if (EntryHandle.IsSet())
	{
		const FInventoryEntry* ExistingEntry = FindEntry(EntryHandle);
		if (ExistingEntry == nullptr || !ExistingEntry->Payload.IsValid())
		{
			return Result;
		}

		int64 MergedQuantity = 0;
		if (!TryAddQuantity(ExistingEntry->Payload.Quantity, Payload.Quantity, MergedQuantity))
		{
			return Result;
		}

		// 聚合时保留目标 Entry 原本的实例，仅增加它所代表的数量。
		const FInventoryItemPayload MergedPayload(
			ExistingEntry->Payload.ItemInstance,
			MergedQuantity);
		if (!SetEntryPayload(EntryHandle, MergedPayload))
		{
			return Result;
		}
	}
	else
	{
		// 新 Entry 直接接收传入实例；调用者可在成功后清空自己的临时 Payload。
		EntryHandle = CreateEntry(Payload);
		if (!EntryHandle.IsSet())
		{
			return Result;
		}
	}

	Result.Status = EInventoryQuantityOperationStatus::Succeeded;
	Result.ChangedQuantity = Payload.Quantity;
	Result.RemainingQuantity = 0;
	Result.AffectedEntry = EntryHandle;
	Result.OutputPayload.Reset();
	return Result;
}

FInventoryQuantityOperationResult UAggregateInventoryComponent::ExtractMatchingItem(
	const UInventoryItemInstance* ItemToMatch,
	const int64 Quantity)
{
	FInventoryQuantityOperationResult Result;
	Result.RequestedQuantity = FMath::Max<int64>(0, Quantity);
	Result.RemainingQuantity = Result.RequestedQuantity;

	const FInventoryEntryHandle EntryHandle = FindCompatibleEntry(ItemToMatch);
	if (!EntryHandle.IsSet())
	{
		return Result;
	}

	return ExtractItemFromEntry(EntryHandle, Quantity);
}

FInventoryQuantityOperationResult UAggregateInventoryComponent::ExtractItemFromEntry(
	const FInventoryEntryHandle& EntryHandle,
	const int64 Quantity)
{
	FInventoryQuantityOperationResult Result;
	Result.RequestedQuantity = FMath::Max<int64>(0, Quantity);
	Result.RemainingQuantity = Result.RequestedQuantity;

	if (Quantity <= 0)
	{
		return Result;
	}

	const FInventoryEntry* Entry = FindEntry(EntryHandle);
	if (Entry == nullptr || !Entry->Payload.IsValid())
	{
		return Result;
	}

	// 修改 EntryArray 前先复制原数据，避免删除 Entry 后继续使用失效指针。
	const FInventoryItemPayload OriginalPayload = Entry->Payload;
	const int64 ExtractedQuantity = FMath::Min(Quantity, OriginalPayload.Quantity);

	if (ExtractedQuantity == OriginalPayload.Quantity)
	{
		// 完整提取直接转移原实例，来源容器不再保存它。
		Result.OutputPayload = OriginalPayload;
		if (!RemoveEntry(EntryHandle))
		{
			Result.OutputPayload.Reset();
			return Result;
		}
	}
	else
	{
		// 部分提取必须复制实例，避免两个独立物品堆共享可变运行时状态。
		UInventoryItemInstance* ExtractedInstance =
			OriginalPayload.ItemInstance->DuplicateInstance(GetTransientPackage());
		if (!IsValid(ExtractedInstance))
		{
			return Result;
		}

		const FInventoryItemPayload RemainingPayload(
			OriginalPayload.ItemInstance,
			OriginalPayload.Quantity - ExtractedQuantity);
		if (!SetEntryPayload(EntryHandle, RemainingPayload))
		{
			return Result;
		}

		Result.OutputPayload = FInventoryItemPayload(ExtractedInstance, ExtractedQuantity);
	}

	Result.Status = ExtractedQuantity == Quantity
		? EInventoryQuantityOperationStatus::Succeeded
		: EInventoryQuantityOperationStatus::PartialSucceeded;
	Result.ChangedQuantity = ExtractedQuantity;
	Result.RemainingQuantity = Quantity - ExtractedQuantity;
	Result.AffectedEntry = EntryHandle;
	return Result;
}

FInventoryEntryHandle UAggregateInventoryComponent::FindCompatibleEntry(
	const UInventoryItemInstance* ItemToMatch) const
{
	if (!::IsValid(ItemToMatch))
	{
		return {};
	}

	for (const FInventoryEntry& Entry : EntryArray.ItemEntries)
	{
		if (!Entry.Payload.IsValid())
		{
			continue;
		}

		if (UInventoryBlueprintLibrary::IsMatching(ItemToMatch, Entry.Payload.ItemInstance))
		{
			return MakeEntryHandle(Entry.EntryID);
		}
	}

	return {};
}

bool UAggregateInventoryComponent::TryAddQuantity(
	const int64 CurrentQuantity,
	const int64 AddedQuantity,
	int64& OutQuantity)
{
	OutQuantity = 0;

	if (CurrentQuantity < 0 || AddedQuantity <= 0)
	{
		return false;
	}

	if (CurrentQuantity > TNumericLimits<int64>::Max() - AddedQuantity)
	{
		return false;
	}

	OutQuantity = CurrentQuantity + AddedQuantity;
	return true;
}
