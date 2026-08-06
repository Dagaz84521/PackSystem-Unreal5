#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InventoryEntryArray.h"
#include "InventoryAddPlan.generated.h"

class UInventoryItemInstance;

/** 一条添加计划准备对库存 Entry 执行的操作。 */
UENUM(BlueprintType)
enum class EInventoryAddPlanOperation : uint8
{
	NewEntry,
	ExistingEntry
};

/**
 * 添加计划中的单条 Entry 变更。
 *
 * CreateEntry 操作忽略 TargetEntry，并使用 ItemInstance 与 Quantity 创建新条目；
 * IncreaseQuantity 操作则把 Quantity 增加到 TargetEntry。
 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryAddPlanChange
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Add Plan")
	EInventoryAddPlanOperation Operation = EInventoryAddPlanOperation::NewEntry;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Add Plan")
	FInventoryEntryHandle TargetEntry;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Add Plan")
	TObjectPtr<UInventoryItemInstance> ItemInstance = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Add Plan", meta = (ClampMin = "1"))
	int64 Quantity = 0;
	
	FInventoryAddPlanChange() = default;
	
	FInventoryAddPlanChange(const EInventoryAddPlanOperation Operation, 
		const FInventoryEntryHandle& TargetEntry, 
		UInventoryItemInstance* ItemInstance, 
		const int64 Quantity)
	{
		this->Operation = Operation;
		this->TargetEntry = TargetEntry;
		this->ItemInstance = ItemInstance;
		this->Quantity = Quantity;
	}
};

/**
 * Storage Strategy 根据当前库存快照计算出的添加计划。
 * 该结构只描述建议执行的变更，不直接修改库存，也不代表变更已经成功。
 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryAddPlan
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Add Plan")
	int64 RequestedQuantity = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Add Plan")
	int64 PlannedQuantity = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Add Plan")
	int64 RemainingQuantity = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Add Plan")
	TArray<FInventoryAddPlanChange> Changes;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Add Plan")
	FGameplayTag FailureReason;
};
