// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Slotted/SlottedInventoryComponent.h"

#include "Core/InventoryBlueprintLibrary.h"
#include "Item/InventoryItemDefinition.h"

void USlottedInventoryComponent::OnRegister()
{
	Super::OnRegister();
	EnsureSlotsInitialized();
}

int32 USlottedInventoryComponent::GetSlotCount() const
{
	return FMath::Max(0, SlotCount);
}

FInventoryEntryHandle USlottedInventoryComponent::GetSlotHandle(int32 SlotIndex) const
{
	if (SlotIndex < 0 || SlotIndex >= GetSlotCount())
	{
		return {};
	}

	if (!EntryArray.ItemEntries.IsValidIndex(SlotIndex))
	{
		return {};
	}

	return MakeEntryHandle(EntryArray.ItemEntries[SlotIndex].EntryID);
}

bool USlottedInventoryComponent::IsSlotEmpty(const FInventoryEntryHandle& SlotHandle) const
{
	const FInventoryEntry* Entry = FindEntry(SlotHandle);
	return Entry != nullptr && Entry->IsEmpty();
}

void USlottedInventoryComponent::EnsureSlotsInitialized()
{
	SlotCount = FMath::Max(0, SlotCount);

	// 缩容规则尚未定义。已有格子多于配置值时保留全部格子，避免静默删除物品。
	if (EntryArray.ItemEntries.Num() > SlotCount)
	{
		SlotCount = EntryArray.ItemEntries.Num();
		return;
	}

	// 空 Payload 表示一个已存在但尚未存放物品的固定格子。
	while (EntryArray.ItemEntries.Num() < SlotCount)
	{
		if (!CreateEntry(FInventoryItemPayload()).IsSet())
		{
			ensureMsgf(false, TEXT("Failed to initialize inventory slot for %s"), *GetPathName());
			break;
		}
	}
}

FInventoryQuantityOperationResult USlottedInventoryComponent::ExtractItemFromSlot(
	const FInventoryEntryHandle& SlotHandle,
	int64 Quantity)
{
	FInventoryEntry Entry;
	FInventoryQuantityOperationResult Result;
	if (SlotHandle.IsValid() && Quantity > 0 && GetEntry(SlotHandle, Entry))
	{
		if (!Entry.Payload.IsValid())
		{
			return Result;
		}
		if (Entry.Payload.Quantity < Quantity)
		{
			return Result;
		}
		if (Entry.Payload.Quantity == Quantity)
		{
			// 提取全部物品
			FInventoryItemPayload ExtractedPayload = Entry.Payload;
			ClearEntry(SlotHandle);
			Result.Set(EInventoryQuantityOperationStatus::Succeeded, Quantity, ExtractedPayload.Quantity, ExtractedPayload, SlotHandle);
			return Result;
		}
		else
		{
			// 提取部分物品
			FInventoryItemPayload ExtractedPayload = Entry.Payload;
			ExtractedPayload.Quantity = Quantity;
			FInventoryItemPayload RemainingPayload = Entry.Payload;
			RemainingPayload.Quantity -= Quantity;
			SetEntryPayload(SlotHandle, RemainingPayload);
			Result.Set(EInventoryQuantityOperationStatus::Succeeded, Quantity, ExtractedPayload.Quantity, ExtractedPayload, SlotHandle);
			return Result;
		}
	}
	return Result;
}



FInventoryQuantityOperationResult USlottedInventoryComponent::PlaceItemAtSlot(
	const FInventoryEntryHandle& SlotHandle,
	const FInventoryItemPayload& CursorPayload)
{
	const FInventoryQuantityOperationResult FailedResult =
		MakeFailedPlacementResult(CursorPayload);

	FInventoryEntry Entry;
	if (!CursorPayload.IsValid() || !GetEntry(SlotHandle, Entry))
	{
		return FailedResult;
	}

	// Instance 物品的 Definition 会返回 1；普通堆叠物品返回配置的单格上限。
	const int64 MaxStackSize = CursorPayload.ItemDefinition->GetMaxStackSize();
	if (MaxStackSize <= 0)
	{
		return FailedResult;
	}

	if (Entry.Payload.IsEmpty())
	{
		return PlaceInEmptySlot(SlotHandle, CursorPayload, MaxStackSize);
	}

	// 非空但无效的 Payload 代表存储数据异常，不能将其当成普通物品进行交换。
	if (!Entry.Payload.IsValid())
	{
		return FailedResult;
	}

	if (UInventoryBlueprintLibrary::IsMatching(Entry.Payload, CursorPayload))
	{
		return MergeIntoSlot(
			SlotHandle,
			Entry.Payload,
			CursorPayload,
			MaxStackSize);
	}

	return SwapWithSlot(
		SlotHandle,
		Entry.Payload,
		CursorPayload,
		MaxStackSize);
}

FInventoryQuantityOperationResult USlottedInventoryComponent::PlaceInEmptySlot(
	const FInventoryEntryHandle& SlotHandle,
	const FInventoryItemPayload& CursorPayload,
	const int64 MaxStackSize)
{
	// 空格必须接收完整 Cursor Payload；跨多个格子的拆分由 AddItem 负责。
	if (CursorPayload.Quantity > MaxStackSize ||
		!SetEntryPayload(SlotHandle, CursorPayload))
	{
		return MakeFailedPlacementResult(CursorPayload);
	}

	FInventoryQuantityOperationResult Result;
	Result.Set(
		EInventoryQuantityOperationStatus::Succeeded,
		CursorPayload.Quantity,
		CursorPayload.Quantity,
		FInventoryItemPayload(),
		SlotHandle);
	return Result;
}

FInventoryQuantityOperationResult USlottedInventoryComponent::MergeIntoSlot(
	const FInventoryEntryHandle& SlotHandle,
	const FInventoryItemPayload& TargetPayload,
	const FInventoryItemPayload& CursorPayload,
	const int64 MaxStackSize)
{
	const int64 AvailableQuantity = MaxStackSize - TargetPayload.Quantity;
	if (AvailableQuantity <= 0)
	{
		return MakeFailedPlacementResult(CursorPayload);
	}

	// 目标只接收剩余容量允许的数量；未放入的部分继续由 Cursor 持有。
	const int64 PlacedQuantity = FMath::Min(CursorPayload.Quantity, AvailableQuantity);
	FInventoryItemPayload MergedPayload = TargetPayload;
	MergedPayload.Quantity += PlacedQuantity;
	if (!SetEntryPayload(SlotHandle, MergedPayload))
	{
		return MakeFailedPlacementResult(CursorPayload);
	}

	FInventoryItemPayload CursorPayloadAfter = CursorPayload;
	CursorPayloadAfter.Quantity -= PlacedQuantity;
	if (CursorPayloadAfter.Quantity == 0)
	{
		CursorPayloadAfter.Reset();
	}

	const EInventoryQuantityOperationStatus Status =
		PlacedQuantity == CursorPayload.Quantity
			? EInventoryQuantityOperationStatus::Succeeded
			: EInventoryQuantityOperationStatus::PartialSucceeded;

	FInventoryQuantityOperationResult Result;
	Result.Set(
		Status,
		CursorPayload.Quantity,
		PlacedQuantity,
		CursorPayloadAfter,
		SlotHandle);
	return Result;
}

FInventoryQuantityOperationResult USlottedInventoryComponent::SwapWithSlot(
	const FInventoryEntryHandle& SlotHandle,
	const FInventoryItemPayload& TargetPayload,
	const FInventoryItemPayload& CursorPayload,
	const int64 MaxStackSize)
{
	// SetEntryPayload 只复制 Payload 中的引用；目标原 Payload 转交给 Cursor，
	// 因此交换不会复制 ItemInstance。
	if (CursorPayload.Quantity > MaxStackSize ||
		!SetEntryPayload(SlotHandle, CursorPayload))
	{
		return MakeFailedPlacementResult(CursorPayload);
	}

	FInventoryQuantityOperationResult Result;
	Result.Set(
		EInventoryQuantityOperationStatus::Succeeded,
		CursorPayload.Quantity,
		CursorPayload.Quantity,
		TargetPayload,
		SlotHandle);
	return Result;
}

FInventoryQuantityOperationResult USlottedInventoryComponent::MakeFailedPlacementResult(
	const FInventoryItemPayload& CursorPayload)
{
	// 调用者始终可以用 OutputPayload 覆盖当前 Cursor，失败不会吞掉持有物品。
	FInventoryQuantityOperationResult Result;
	Result.RequestedQuantity = FMath::Max<int64>(0, CursorPayload.Quantity);
	Result.RemainingQuantity = Result.RequestedQuantity;
	Result.OutputPayload = CursorPayload;
	return Result;
}

FInventoryQuantityOperationResult USlottedInventoryComponent::AddItem(
	const FInventoryItemPayload& Payload,
	const FInventoryEntryHandle& PreferredSlot)
{
	// 默认结果表示“一个都没放入”，并原样返回 Payload；后续只覆盖实际完成的部分。
	FInventoryQuantityOperationResult Result = MakeFailedPlacementResult(Payload);
	if (!Payload.IsValid())
	{
		return Result;
	}

	const int64 MaxStackSize = Payload.ItemDefinition->GetMaxStackSize();
	if (MaxStackSize <= 0)
	{
		return Result;
	}

	FInventoryItemPayload RemainingPayload = Payload;
	int64 ChangedQuantity = 0;
	FInventoryEntryHandle FirstAffectedSlot;

	// AddItem 只修改 Entry 的 Payload，不增删 Entry，因此可以安全地复用这份 Handle 快照。
	const TArray<FInventoryEntryHandle> SlotHandles = GetAllEntryHandles();
	bool bWriteSucceeded = true;

	// Preferred 只是优先位置：不相容或无容量时继续尝试其他格子，绝不交换。
	FInventoryEntry PreferredEntry;
	if (GetEntry(PreferredSlot, PreferredEntry))
	{
		bWriteSucceeded = TryAddRemainingToSlot(
			PreferredSlot,
			MaxStackSize,
			PreferredEntry.Payload.IsEmpty()
				? EInventorySlotPlacementAction::PlaceInEmptySlot
				: EInventorySlotPlacementAction::StackOnExistingItem,
			RemainingPayload,
			ChangedQuantity,
			FirstAffectedSlot);
	}

	// 自动添加优先利用已有堆叠，减少被占用的格子数量。
	if (bWriteSucceeded && !RemainingPayload.IsEmpty())
	{
		bWriteSucceeded = TryAddRemainingAcrossSlots(
			SlotHandles,
			PreferredSlot,
			MaxStackSize,
			EInventorySlotPlacementAction::StackOnExistingItem,
			RemainingPayload,
			ChangedQuantity,
			FirstAffectedSlot);
	}

	// 第二轮才占用空格，避免在仍有相容堆叠时浪费格子。
	if (bWriteSucceeded && !RemainingPayload.IsEmpty())
	{
		TryAddRemainingAcrossSlots(
			SlotHandles,
			PreferredSlot,
			MaxStackSize,
			EInventorySlotPlacementAction::PlaceInEmptySlot,
			RemainingPayload,
			ChangedQuantity,
			FirstAffectedSlot);
	}

	// 状态只由最终放入量决定：零个失败、无剩余成功、否则为部分成功。
	const EInventoryQuantityOperationStatus Status =
		ChangedQuantity == 0
			? EInventoryQuantityOperationStatus::Failed
			: RemainingPayload.IsEmpty()
				? EInventoryQuantityOperationStatus::Succeeded
				: EInventoryQuantityOperationStatus::PartialSucceeded;
	Result.Set(
		Status,
		Payload.Quantity,
		ChangedQuantity,
		RemainingPayload,
		FirstAffectedSlot);
	return Result;
}

bool USlottedInventoryComponent::TryAddRemainingToSlot(
	const FInventoryEntryHandle& SlotHandle,
	const int64 MaxStackSize,
	const EInventorySlotPlacementAction PlacementAction,
	FInventoryItemPayload& RemainingPayload,
	int64& ChangedQuantity,
	FInventoryEntryHandle& FirstAffectedSlot)
{
	int64 PlacedQuantity = 0;
	// PlacementAction 只选择本轮允许的行为；自动添加永远不会进入交换逻辑。
	const bool bWriteSucceeded =
		PlacementAction == EInventorySlotPlacementAction::PlaceInEmptySlot
		? TryPlaceRemainingInEmptySlot(
			SlotHandle, MaxStackSize, RemainingPayload, PlacedQuantity)
		: TryMergeRemainingIntoSlot(
			SlotHandle, MaxStackSize, RemainingPayload, PlacedQuantity);

	if (PlacedQuantity > 0)
	{
		// AffectedEntry 只能保存一个 Handle，因此记录第一个真正发生变化的格子。
		ChangedQuantity += PlacedQuantity;
		if (!FirstAffectedSlot.IsSet())
		{
			FirstAffectedSlot = SlotHandle;
		}
	}
	return bWriteSucceeded;
}

bool USlottedInventoryComponent::TryAddRemainingAcrossSlots(
	const TArray<FInventoryEntryHandle>& SlotHandles,
	const FInventoryEntryHandle& PreferredSlot,
	const int64 MaxStackSize,
	const EInventorySlotPlacementAction PlacementAction,
	FInventoryItemPayload& RemainingPayload,
	int64& ChangedQuantity,
	FInventoryEntryHandle& FirstAffectedSlot)
{
	for (const FInventoryEntryHandle& SlotHandle : SlotHandles)
	{
		if (RemainingPayload.IsEmpty())
		{
			return true;
		}

		// Preferred 已在主流程单独尝试，扫描阶段必须跳过，避免同一格处理两次。
		if (SlotHandle != PreferredSlot &&
			!TryAddRemainingToSlot(
				SlotHandle,
				MaxStackSize,
				PlacementAction,
				RemainingPayload,
				ChangedQuantity,
				FirstAffectedSlot))
		{
			return false;
		}
	}
	return true;
}

bool USlottedInventoryComponent::TryMergeRemainingIntoSlot(
	const FInventoryEntryHandle& SlotHandle,
	const int64 MaxStackSize,
	FInventoryItemPayload& RemainingPayload,
	int64& OutPlacedQuantity)
{
	OutPlacedQuantity = 0;
	if (RemainingPayload.IsEmpty())
	{
		return true;
	}

	FInventoryEntry Entry;
	// 无效或不相容表示“该格不适用”，扫描应继续尝试后面的格子。
	if (!GetEntry(SlotHandle, Entry) ||
		!Entry.Payload.IsValid() ||
		!UInventoryBlueprintLibrary::IsMatching(Entry.Payload, RemainingPayload))
	{
		return true;
	}

	const int64 AvailableQuantity = MaxStackSize - Entry.Payload.Quantity;
	// 已满同样只是跳过当前格，不代表整个自动添加操作失败。
	if (AvailableQuantity <= 0)
	{
		return true;
	}

	OutPlacedQuantity = FMath::Min(RemainingPayload.Quantity, AvailableQuantity);
	FInventoryItemPayload MergedPayload = Entry.Payload;
	MergedPayload.Quantity += OutPlacedQuantity;
	// 先写入目标，再扣减 Remaining；写入失败时调用者仍保留完整剩余物品。
	if (!SetEntryPayload(SlotHandle, MergedPayload))
	{
		OutPlacedQuantity = 0;
		return false;
	}

	RemainingPayload.Quantity -= OutPlacedQuantity;
	if (RemainingPayload.Quantity == 0)
	{
		RemainingPayload.Reset();
	}
	return true;
}

bool USlottedInventoryComponent::TryPlaceRemainingInEmptySlot(
	const FInventoryEntryHandle& SlotHandle,
	const int64 MaxStackSize,
	FInventoryItemPayload& RemainingPayload,
	int64& OutPlacedQuantity)
{
	OutPlacedQuantity = 0;
	if (RemainingPayload.IsEmpty())
	{
		return true;
	}

	FInventoryEntry Entry;
	if (!GetEntry(SlotHandle, Entry) || !Entry.Payload.IsEmpty())
	{
		return true;
	}

	// 一个空格最多接收一个堆叠；超出的数量留给下一空格继续处理。
	OutPlacedQuantity = FMath::Min(RemainingPayload.Quantity, MaxStackSize);
	FInventoryItemPayload SlotPayload = RemainingPayload;
	SlotPayload.Quantity = OutPlacedQuantity;
	// 同样只在写入成功后扣减 Remaining，保证失败不会吞掉物品。
	if (!SetEntryPayload(SlotHandle, SlotPayload))
	{
		OutPlacedQuantity = 0;
		return false;
	}

	RemainingPayload.Quantity -= OutPlacedQuantity;
	if (RemainingPayload.Quantity == 0)
	{
		RemainingPayload.Reset();
	}
	return true;
}
