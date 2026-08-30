#include "Interaction/InventoryInteractionContext.h"

#include "Inventory/Slotted/SlottedInventoryComponent.h"

bool UInventoryInteractionContext::IsHoldingItem() const
{
	return HeldPayload.IsValid();
}

FInventoryItemPayload UInventoryInteractionContext::GetHeldPayload() const
{
	return HeldPayload;
}

FInventoryQuantityOperationResult UInventoryInteractionContext::TakeItemFromSlot(
	const FInventoryEntryHandle& SourceSlot,
	const int64 Quantity)
{
	FInventoryQuantityOperationResult FailedResult;
	FailedResult.RequestedQuantity = FMath::Max<int64>(0, Quantity);
	FailedResult.RemainingQuantity = FailedResult.RequestedQuantity;

	// 即使 HeldPayload 因异常而变得畸形，也不能用新物品覆盖这份尚未处理的数据。
	if (!HeldPayload.IsEmpty() || Quantity <= 0)
	{
		return FailedResult;
	}

	USlottedInventoryComponent* SourceInventory = ResolveSlottedInventory(SourceSlot);
	if (SourceInventory == nullptr)
	{
		return FailedResult;
	}

	FInventoryQuantityOperationResult Result =
		SourceInventory->ExtractItemFromSlot(SourceSlot, Quantity);
	if (Result.Status != EInventoryQuantityOperationStatus::Succeeded ||
		!Result.OutputPayload.IsValid())
	{
		return Result;
	}

	// 先记录来源再广播 Held 变化，保证事件监听者看到完整会话状态。
	OriginInventory = SourceInventory;
	OriginSlot = SourceSlot;
	SetHeldPayload(Result.OutputPayload);
	return Result;
}

FInventoryQuantityOperationResult UInventoryInteractionContext::PlaceHeldItemAtSlot(
	const FInventoryEntryHandle& TargetSlot)
{
	const FInventoryQuantityOperationResult FailedResult =
		MakeFailedCursorResult(HeldPayload);
	if (!HeldPayload.IsValid())
	{
		return FailedResult;
	}

	USlottedInventoryComponent* TargetInventory = ResolveSlottedInventory(TargetSlot);
	if (TargetInventory == nullptr)
	{
		return FailedResult;
	}

	FInventoryQuantityOperationResult Result =
		TargetInventory->PlaceItemAtSlot(TargetSlot, HeldPayload);
	if (Result.Status == EInventoryQuantityOperationStatus::Failed)
	{
		return Result;
	}

	// 完全放置后会话结束；部分合并和交换仍保留原来源作为取消时的优先位置。
	if (Result.OutputPayload.IsEmpty())
	{
		ClearOrigin();
	}
	SetHeldPayload(Result.OutputPayload);
	return Result;
}

FInventoryQuantityOperationResult UInventoryInteractionContext::CancelHeldItem()
{
	if (HeldPayload.IsEmpty())
	{
		FInventoryQuantityOperationResult Result;
		Result.Set(
			EInventoryQuantityOperationStatus::Succeeded,
			0,
			0,
			FInventoryItemPayload(),
			FInventoryEntryHandle());
		return Result;
	}

	const FInventoryQuantityOperationResult FailedResult =
		MakeFailedCursorResult(HeldPayload);
	USlottedInventoryComponent* Inventory = OriginInventory.Get();
	if (!IsValid(Inventory))
	{
		return FailedResult;
	}

	FInventoryQuantityOperationResult Result =
		Inventory->AddItem(HeldPayload, OriginSlot);
	if (Result.Status == EInventoryQuantityOperationStatus::Failed)
	{
		return Result;
	}

	if (Result.OutputPayload.IsEmpty())
	{
		ClearOrigin();
	}
	SetHeldPayload(Result.OutputPayload);
	return Result;
}

USlottedInventoryComponent* UInventoryInteractionContext::ResolveSlottedInventory(
	const FInventoryEntryHandle& SlotHandle) const
{
	USlottedInventoryComponent* Inventory =
		Cast<USlottedInventoryComponent>(SlotHandle.ParentInventory.Get());
	return IsValid(Inventory) && Inventory->IsValidEntryHandle(SlotHandle)
		? Inventory
		: nullptr;
}

void UInventoryInteractionContext::SetHeldPayload(
	const FInventoryItemPayload& NewPayload)
{
	if (HeldPayload == NewPayload)
	{
		return;
	}

	HeldPayload = NewPayload;
	OnHeldPayloadChanged.Broadcast();
}

void UInventoryInteractionContext::ClearOrigin()
{
	OriginInventory.Reset();
	OriginSlot = FInventoryEntryHandle();
}

FInventoryQuantityOperationResult UInventoryInteractionContext::MakeFailedCursorResult(
	const FInventoryItemPayload& CursorPayload)
{
	FInventoryQuantityOperationResult Result;
	Result.RequestedQuantity = FMath::Max<int64>(0, CursorPayload.Quantity);
	Result.RemainingQuantity = Result.RequestedQuantity;
	Result.OutputPayload = CursorPayload;
	return Result;
}
