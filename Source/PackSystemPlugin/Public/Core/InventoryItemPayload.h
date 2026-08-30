#pragma once

#include "CoreMinimal.h"
#include "InventoryItemPayload.generated.h"

class UInventoryItemDefinition;
class UInventoryItemInstance;

/**
 * 可以脱离 Inventory Entry 独立存在的物品堆数据。
 *
 * Definition 和 Quantity 构成所有物品的基础表示；只有需要动态状态的物品才携带
 * ItemInstance。Payload 可用于添加、提取、容器转移、鼠标暂存等流程。
 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryItemPayload
{
	GENERATED_BODY()

	FInventoryItemPayload() = default;

	FInventoryItemPayload(
		UInventoryItemDefinition* InItemDefinition,
		int64 InQuantity,
		UInventoryItemInstance* InItemInstance = nullptr);

	/** 当前物品堆对应的静态物品定义。 */
	UPROPERTY(BlueprintReadWrite, Category = "Inventory|Payload")
	TObjectPtr<UInventoryItemDefinition> ItemDefinition = nullptr;

	/** 可选的运行时动态状态；普通材料等无状态物品保持为空。 */
	UPROPERTY(BlueprintReadWrite, Category = "Inventory|Payload")
	TObjectPtr<UInventoryItemInstance> ItemInstance = nullptr;

	/** 当前物品堆包含的物品数量。 */
	UPROPERTY(BlueprintReadWrite, Category = "Inventory|Payload", meta = (ClampMin = "0"))
	int64 Quantity = 0;

	/** 返回该 Payload 是否为空。 */
	bool IsEmpty() const;

	/** 返回该 Payload 是否包含有效物品和正数数量。 */
	bool IsValid() const;

	/** 返回该 Payload 是否满足“有效物品堆或完全为空”的数据约束。 */
	bool IsWellFormed() const;

	/** 将该 Payload 重置为空。 */
	void Reset();

	bool operator==(const FInventoryItemPayload& Other) const
	{
		return ItemDefinition == Other.ItemDefinition
			&& ItemInstance == Other.ItemInstance
			&& Quantity == Other.Quantity;
	}

	bool operator!=(const FInventoryItemPayload& Other) const
	{
		return !(*this == Other);
	}
};
