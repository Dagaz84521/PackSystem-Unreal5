#pragma once

#include "CoreMinimal.h"
#include "Item/InventoryItemInstance.h"
#include "InventoryEntry.generated.h"

class UInventoryComponent;

/**
 * 背包中的一条库存记录。
 * 保存条目标识、数量以及该条目引用的运行时物品实例。
 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryEntry
{
	GENERATED_BODY()

	FInventoryEntry()
		: ItemInstance(nullptr)
		, Quantity(0)
		, EntryID(INDEX_NONE)
	{
	}

	FInventoryEntry(UInventoryItemInstance* InItemInstance, int32 InEntryID, int64 InQuantity = 1)
		: ItemInstance(InItemInstance)
		, Quantity(FMath::Max<int64>(0, InQuantity))
		, EntryID(InEntryID)
	{
	}

	/** 当前条目引用的物品实例；为空表示该条目没有物品。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TObjectPtr<UInventoryItemInstance> ItemInstance;

	/**
	 * 当前条目中的数量。
	 * 数量属于库存条目而不是物品实例，因为不同库存策略可以为同一物品设置不同的容量规则。
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (ClampMin = "0"))
	int64 Quantity = 0;

	/** 条目标识；INDEX_NONE 表示尚未分配有效标识。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	int32 EntryID;

	bool IsEmpty() const
	{
		return ItemInstance == nullptr && Quantity == 0;
	}

	bool HasValidState() const
	{
		return IsEmpty() || (::IsValid(ItemInstance) && Quantity > 0);
	}

	bool operator==(const FInventoryEntry& Other) const
	{
		return ItemInstance == Other.ItemInstance && Quantity == Other.Quantity && EntryID == Other.EntryID;
	}

	bool operator!=(const FInventoryEntry& Other) const
	{
		return !(*this == Other);
	}

protected:
	/** 拥有该条目的背包组件，不参与保存或网络复制。 */
	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<UInventoryComponent> Owner;

	friend class UInventoryComponent;
};
