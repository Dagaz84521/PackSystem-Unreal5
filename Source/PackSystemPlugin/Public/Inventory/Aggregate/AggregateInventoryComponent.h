#pragma once

#include "CoreMinimal.h"
#include "Core/InventoryComponent.h"
#include "Core/InventoryQuantityOperationResult.h"
#include "AggregateInventoryComponent.generated.h"

/**
 * 聚合型背包组件。
 *
 * 相容的无实例物品会聚合到同一个 Entry 中；有独立动态实例的物品始终使用
 * 独立 Entry。该组件没有堆叠上限，也不存在槽位交换。
 */
UCLASS(ClassGroup = (Inventory), meta = (BlueprintSpawnableComponent))
class PACKSYSTEMPLUGIN_API UAggregateInventoryComponent : public UInventoryComponent
{
	GENERATED_BODY()

public:
	/** 创建聚合型背包组件。 */
	UAggregateInventoryComponent();

	/** 将一个完整的物品 Payload 添加到背包。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Aggregate")
	FInventoryQuantityOperationResult AddItem(const FInventoryItemPayload& Payload);

	/** 根据 Payload 的 Definition 和动态状态查找相容 Entry，并提取指定数量。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Aggregate")
	FInventoryQuantityOperationResult ExtractMatchingItem(
		const FInventoryItemPayload& ItemToMatch,
		int64 Quantity = 1);

	/** 从指定 Entry 中提取指定数量。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Aggregate")
	FInventoryQuantityOperationResult ExtractItemFromEntry(
		const FInventoryEntryHandle& EntryHandle,
		int64 Quantity = 1);

	/** 查找第一个可与指定 Payload 聚合的 Entry。 */
	FInventoryEntryHandle FindCompatibleEntry(const FInventoryItemPayload& ItemToMatch) const;

	/** 安全地计算数量之和，并阻止 int64 溢出。 */
	static bool TryAddQuantity(int64 CurrentQuantity, int64 AddedQuantity, int64& OutQuantity);
};
