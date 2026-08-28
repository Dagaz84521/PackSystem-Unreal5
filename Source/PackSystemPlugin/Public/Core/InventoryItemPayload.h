#pragma once

#include "CoreMinimal.h"
#include "Item/InventoryItemInstance.h"
#include "InventoryItemPayload.generated.h"

/**
 * 可以脱离 Inventory Entry 独立存在的物品堆数据。
 *
 * Payload 同时保存物品实例和数量，可用于添加、提取、容器转移、鼠标暂存等流程。
 * 空 Payload 必须同时满足 ItemInstance 为空且 Quantity 为 0。
 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryItemPayload
{
	GENERATED_BODY()

	FInventoryItemPayload() = default;

	FInventoryItemPayload(UInventoryItemInstance* InItemInstance, const int64 InQuantity)
		: ItemInstance(InItemInstance)
		, Quantity(InQuantity)
	{
	}

	/** 当前物品堆对应的运行时物品实例。 */
	UPROPERTY(BlueprintReadWrite, Category = "Inventory|Payload")
	TObjectPtr<UInventoryItemInstance> ItemInstance = nullptr;

	/** 当前物品堆包含的物品数量。 */
	UPROPERTY(BlueprintReadWrite, Category = "Inventory|Payload", meta = (ClampMin = "0"))
	int64 Quantity = 0;

	/** 返回该 Payload 是否为空。 */
	bool IsEmpty() const
	{
		return ItemInstance == nullptr && Quantity == 0;
	}

	/** 返回该 Payload 是否包含有效物品和正数数量。 */
	bool IsValid() const
	{
		return ::IsValid(ItemInstance) && Quantity > 0;
	}

	/** 返回该 Payload 是否满足“有效物品堆或完全为空”的数据约束。 */
	bool IsWellFormed() const
	{
		return IsEmpty() || IsValid();
	}

	/** 将该 Payload 重置为空。 */
	void Reset()
	{
		ItemInstance = nullptr;
		Quantity = 0;
	}

	bool operator==(const FInventoryItemPayload& Other) const
	{
		return ItemInstance == Other.ItemInstance && Quantity == Other.Quantity;
	}

	bool operator!=(const FInventoryItemPayload& Other) const
	{
		return !(*this == Other);
	}
};
