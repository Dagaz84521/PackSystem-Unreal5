#pragma once

#include "CoreMinimal.h"
#include "InventoryAddRequest.h"
#include "InventoryOperationTypes.h"
#include "UObject/Object.h"
#include "InventoryStorageStrategy.generated.h"

class UInventoryComponent;
class UInventoryItemInstance;

/**
 * 存储规则的只读规划接口。
 *
 * 派生类不能直接写 Inventory；它们只根据当前快照返回 OperationPlan。
 * 所有 Plan 最终都由 UInventoryComponent 统一校验并提交。
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class PACKSYSTEMPLUGIN_API UInventoryStorageStrategy : public UObject
{
	GENERATED_BODY()

public:
	/** Slot 返回固定格子数，Aggregate 返回 0。只在首次初始化时读取。 */
	virtual int32 GetInitialEntryCount() const { return 0; }

	virtual FInventoryOperationPlan BuildAddPlan(
		const UInventoryComponent& Inventory,
		const FInventoryAddRequest& Request) const PURE_VIRTUAL(UInventoryStorageStrategy::BuildAddPlan, return {};);

	virtual FInventoryOperationPlan BuildRemoveMatchingPlan(
		const UInventoryComponent& Inventory,
		const UInventoryItemInstance* ItemInstance,
		int64 Quantity) const PURE_VIRTUAL(UInventoryStorageStrategy::BuildRemoveMatchingPlan, return {};);

	virtual FInventoryOperationPlan BuildRemoveFromEntryPlan(
		const UInventoryComponent& Inventory,
		const FInventoryEntryHandle& EntryHandle,
		int64 Quantity) const PURE_VIRTUAL(UInventoryStorageStrategy::BuildRemoveFromEntryPlan, return {};);

	virtual FInventoryOperationPlan BuildMovePlan(
		const UInventoryComponent& Inventory,
		const FInventoryEntryHandle& SourceEntry,
		const FInventoryEntryHandle& TargetEntry,
		int64 Quantity) const PURE_VIRTUAL(UInventoryStorageStrategy::BuildMovePlan, return {};);

	virtual FInventoryOperationPlan BuildSwapPlan(
		const UInventoryComponent& Inventory,
		const FInventoryEntryHandle& FirstEntry,
		const FInventoryEntryHandle& SecondEntry) const PURE_VIRTUAL(UInventoryStorageStrategy::BuildSwapPlan, return {};);

	virtual FInventoryOperationPlan BuildClearPlan(
		const UInventoryComponent& Inventory) const PURE_VIRTUAL(UInventoryStorageStrategy::BuildClearPlan, return {};);
};
