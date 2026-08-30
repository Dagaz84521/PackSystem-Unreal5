#include "UI/InventoryUIControllerBase.h"

#include "Core/InventoryComponent.h"

void UInventoryUIControllerBase::Shutdown()
{
	UnbindInventory();
}

bool UInventoryUIControllerBase::BindInventory(UInventoryComponent* InInventory)
{
	UnbindInventory();
	if (!IsValid(InInventory))
	{
		return false;
	}

	Inventory = InInventory;
	Inventory->OnEntryAdded.AddDynamic(this, &ThisClass::HandleEntryAdded);
	Inventory->OnEntryChanged.AddDynamic(this, &ThisClass::HandleEntryChanged);
	Inventory->OnEntryRemoved.AddDynamic(this, &ThisClass::HandleEntryRemoved);
	Inventory->OnInventoryReset.AddDynamic(this, &ThisClass::HandleInventoryReset);
	return true;
}

void UInventoryUIControllerBase::UnbindInventory()
{
	if (IsValid(Inventory))
	{
		Inventory->OnEntryAdded.RemoveDynamic(this, &ThisClass::HandleEntryAdded);
		Inventory->OnEntryChanged.RemoveDynamic(this, &ThisClass::HandleEntryChanged);
		Inventory->OnEntryRemoved.RemoveDynamic(this, &ThisClass::HandleEntryRemoved);
		Inventory->OnInventoryReset.RemoveDynamic(this, &ThisClass::HandleInventoryReset);
	}

	Inventory = nullptr;
}

void UInventoryUIControllerBase::InventoryEntryAdded(
	const FInventoryEntryHandle& EntryHandle)
{
}

void UInventoryUIControllerBase::InventoryEntryChanged(
	const FInventoryEntryHandle& EntryHandle)
{
}

void UInventoryUIControllerBase::InventoryEntryRemoved(
	const FInventoryEntryHandle& EntryHandle)
{
}

void UInventoryUIControllerBase::InventoryReset()
{
}

void UInventoryUIControllerBase::HandleEntryAdded(FInventoryEntryHandle EntryHandle)
{
	InventoryEntryAdded(EntryHandle);
}

void UInventoryUIControllerBase::HandleEntryChanged(FInventoryEntryHandle EntryHandle)
{
	InventoryEntryChanged(EntryHandle);
}

void UInventoryUIControllerBase::HandleEntryRemoved(FInventoryEntryHandle EntryHandle)
{
	InventoryEntryRemoved(EntryHandle);
}

void UInventoryUIControllerBase::HandleInventoryReset()
{
	InventoryReset();
}
