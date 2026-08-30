#include "Core/InventoryBlueprintLibrary.h"

bool UInventoryBlueprintLibrary::IsMatching(
	const FInventoryItemPayload& ItemA,
	const FInventoryItemPayload& ItemB)
{
	if (!ItemA.IsValid() || !ItemB.IsValid())
	{
		return false;
	}

	if (ItemA.ItemDefinition != ItemB.ItemDefinition)
	{
		return false;
	}

	// 当前模型中，拥有独立动态状态的物品数量固定为 1，不能参与堆叠。
	return ItemA.ItemInstance == nullptr && ItemB.ItemInstance == nullptr;
}

bool UInventoryBlueprintLibrary::AreEntryHandlesEqual(const FInventoryEntryHandle& A, const FInventoryEntryHandle& B)
{
	return A == B;
}
