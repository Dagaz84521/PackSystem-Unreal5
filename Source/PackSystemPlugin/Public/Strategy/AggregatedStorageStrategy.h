#pragma once

#include "CoreMinimal.h"
#include "Strategy/InventoryStorageStrategy.h"
#include "AggregatedStorageStrategy.generated.h"

/**
 * 聚合存储：不存在预创建空格，相同 CanStackWith 物品共享一条动态记录。
 * MaxStackSize 在此策略中无效，唯一实际容量边界是 int64 上限。
 */
UCLASS(DisplayName = "Aggregated Inventory")
class PACKSYSTEMPLUGIN_API UAggregatedStorageStrategy : public UInventoryStorageStrategy
{
	GENERATED_BODY()

public:
	virtual FInventoryOperationPlan BuildAddPlan(const UInventoryComponent& Inventory, const FInventoryAddRequest& Request) const override;
	virtual FInventoryOperationPlan BuildRemoveMatchingPlan(const UInventoryComponent& Inventory, const UInventoryItemInstance* ItemInstance, int64 Quantity) const override;
	virtual FInventoryOperationPlan BuildRemoveFromEntryPlan(const UInventoryComponent& Inventory, const FInventoryEntryHandle& EntryHandle, int64 Quantity) const override;
	virtual FInventoryOperationPlan BuildMovePlan(const UInventoryComponent& Inventory, const FInventoryEntryHandle& SourceEntry, const FInventoryEntryHandle& TargetEntry, int64 Quantity) const override;
	virtual FInventoryOperationPlan BuildSwapPlan(const UInventoryComponent& Inventory, const FInventoryEntryHandle& FirstEntry, const FInventoryEntryHandle& SecondEntry) const override;
	virtual FInventoryOperationPlan BuildClearPlan(const UInventoryComponent& Inventory) const override;
};
