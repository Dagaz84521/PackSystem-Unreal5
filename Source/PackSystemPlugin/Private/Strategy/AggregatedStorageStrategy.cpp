// Fill out your copyright notice in the Description page of Project Settings.


#include "Strategy/AggregatedStorageStrategy.h"

#include "InventoryBlueprintLibrary.h"
#include "Item/InventoryItemDefinition.h"

FInventoryAddPlan UAggregatedStorageStrategy::BuildAddPlan(const UInventoryComponent& Inventory,
	const FInventoryAddRequest& Request) const
{
	UInventoryItemInstance* ItemInstance = Request.InventoryItemInstance;
	int64 Quantity = Request.Quantity;
	FInventoryEntryHandle EntryCanStack = GetCanStackEntryHandle(Inventory, ItemInstance);
	FInventoryAddPlan AddPlan;
	if (EntryCanStack.EntryID != INDEX_NONE) // 如果可以堆叠，那么就堆叠
	{
		AddPlan.RequestedQuantity = Quantity;
		AddPlan.PlannedQuantity = Quantity;
		AddPlan.RemainingQuantity = 0;
		FInventoryAddPlanChange Change(EInventoryAddPlanOperation::ExistingEntry, EntryCanStack, ItemInstance, Quantity);
		AddPlan.Changes.Add(Change);
	}
	else
	{
		AddPlan.RequestedQuantity = Quantity;
		AddPlan.PlannedQuantity = Quantity;
		AddPlan.RemainingQuantity = 0;
		FInventoryAddPlanChange Change(EInventoryAddPlanOperation::NewEntry, EntryCanStack, ItemInstance, Quantity);
		AddPlan.Changes.Add(Change);
	}
	return AddPlan;
}

FInventoryEntryHandle UAggregatedStorageStrategy::GetCanStackEntryHandle(const UInventoryComponent& Inventory,
	const UInventoryItemInstance* ItemToStack) const
{
	for (auto EntryHandle : Inventory.GetAllEntries())
	{
		FInventoryEntry Entry = Inventory.FindEntryFromHandle(EntryHandle);
		if (UInventoryBlueprintLibrary::CanStackItems(Entry.ItemInstance, ItemToStack))
			return EntryHandle;
	}
	return FInventoryEntryHandle();
}
