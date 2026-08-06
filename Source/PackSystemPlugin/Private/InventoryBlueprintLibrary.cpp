#include "InventoryBlueprintLibrary.h"

#include "Item/InventoryItemInstance.h"

bool UInventoryBlueprintLibrary::CanStackItems(
	const UInventoryItemInstance* ItemA,
	const UInventoryItemInstance* ItemB)
{
	return IsValid(ItemA)
		&& IsValid(ItemB)
		&& UInventoryItemInstance::CanStackWith(ItemA, ItemB);
}
