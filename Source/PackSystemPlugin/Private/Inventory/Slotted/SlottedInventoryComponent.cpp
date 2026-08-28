// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Slotted/SlottedInventoryComponent.h"

int32 USlottedInventoryComponent::GetSlotCount() const
{
	return SlotCount;
}

FInventoryEntryHandle USlottedInventoryComponent::GetSlotHandle(int32 SlotIndex) const
{
	return MakeEntryHandle(SlotIndex);
}

FInventoryQuantityOperationResult USlottedInventoryComponent::PlacePayloadInSlot(int32 SlotIndex, const FInventoryItemPayload& Payload)
{
	FInventoryEntryHandle Handle = GetSlotHandle(SlotIndex);
	// 检查逻辑

	// 如果该槽位为空，则直接放置物品
	FInventoryEntry Entry;
	if (GetEntry(Handle, Entry))
	{
		
	}
}


