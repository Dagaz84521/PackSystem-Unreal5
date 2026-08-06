#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
	EntryArray.InventoryComponent = this;

	for (int32 Index = EntryArray.ItemEntries.Num();
		 Index < InitialEntryCount;
		 ++Index)
	{
		CreateInventoryEntry();
	}
}

bool UInventoryComponent::IsValidEntryHandle(FInventoryEntryHandle EntryHandle) const
{
	for (const auto& Handle : AllEntryHandles)
	{
		if (Handle == EntryHandle)
			return true;
	}
	return false;
}

FInventoryEntry UInventoryComponent::FindEntryFromHandle(const FInventoryEntryHandle& EntryHandle) const
{
	check(IsValidEntryHandle(EntryHandle));
	for (auto& Handle : EntryArray.ItemEntries)
	{
		if (Handle.EntryID == EntryHandle.EntryID)
			return Handle;
	}
	return EntryArray.ItemEntries[0];
}

TArray<FInventoryEntryHandle> UInventoryComponent::GetAllEntries() const
{
	return AllEntryHandles;
}

void UInventoryComponent::CreateInventoryEntry()
{
	FInventoryEntry NewEntry;
	NewEntry.Owner = this;

	EntryArray.ItemEntries.Add(NewEntry);
	AllEntryHandles.Emplace(NewEntry.EntryID, this);
}

void UInventoryComponent::RemoveInventoryEntry(FInventoryEntryHandle EntryHandle)
{
	if (!IsValidEntryHandle(EntryHandle))
	{
		return;
	}

	EntryArray.ItemEntries.RemoveAll(
		[&EntryHandle](const FInventoryEntry& Entry)
		{
			return Entry.EntryID == EntryHandle.EntryID;
		});

	AllEntryHandles.RemoveSingle(EntryHandle);
}

bool UInventoryComponent::PlaceItemIntoEntry(UInventoryItemInstance* ItemInstance, FInventoryEntryHandle EntryHandle)
{
	if (ItemInstance == nullptr || !AcceptsItem(ItemInstance, EntryHandle))
	{
		return false;
	}

	FInventoryEntry& Entry = FindEntryFromHandle(EntryHandle);
	Entry.ItemInstance = ItemInstance;
	return true;
}

bool UInventoryComponent::AcceptsItem(UInventoryItemInstance* ItemInstance, FInventoryEntryHandle EntryHandle)
{
	if (!IsValidEntryHandle(EntryHandle))
	{
		return false;
	}

	const FInventoryEntry& Entry = FindEntryFromHandle(EntryHandle);
	return Entry.ItemInstance == nullptr;
}

bool UInventoryComponent::LootItem(UInventoryItemInstance* ItemInstance)
{
	if (ItemInstance == nullptr)
	{
		return false;
	}

	for (const FInventoryEntryHandle& EntryHandle : AllEntryHandles)
	{
		if (AcceptsItem(ItemInstance, EntryHandle))
		{
			return PlaceItemIntoEntry(ItemInstance, EntryHandle);
		}
	}

	return false;
}
