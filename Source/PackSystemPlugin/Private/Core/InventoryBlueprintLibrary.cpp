#include "Core/InventoryBlueprintLibrary.h"
#include "Item/InventoryItemInstance.h"

bool UInventoryBlueprintLibrary::IsMatching(
	const UInventoryItemInstance* ItemA,
	const UInventoryItemInstance* ItemB)
{
	return IsValid(ItemA)
		&& IsValid(ItemB)
		&& UInventoryItemInstance::IsMatching(ItemA, ItemB);
}

bool UInventoryBlueprintLibrary::AreEntryHandlesEqual(const FInventoryEntryHandle& A, const FInventoryEntryHandle& B)
{
	return A == B;
}
