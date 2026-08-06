#pragma once

#include "CoreMinimal.h"
#include "Strategy/InventoryStorageStrategy.h"
#include "SlottedStorageStrategy.generated.h"

UCLASS(DisplayName = "Slotted Inventory")
class PACKSYSTEMPLUGIN_API USlottedStorageStrategy : public UInventoryStorageStrategy
{
	GENERATED_BODY()

public:
	virtual int32 GetInitialEntryCount() const override { return SlotCount; }
	virtual FInventoryOperationPlan BuildAddPlan(const UInventoryComponent& Inventory, const FInventoryAddRequest& Request) const override;
	virtual FInventoryOperationPlan BuildRemoveMatchingPlan(const UInventoryComponent& Inventory, const UInventoryItemInstance* ItemInstance, int64 Quantity) const override;
	virtual FInventoryOperationPlan BuildRemoveFromEntryPlan(const UInventoryComponent& Inventory, const FInventoryEntryHandle& EntryHandle, int64 Quantity) const override;
	virtual FInventoryOperationPlan BuildMovePlan(const UInventoryComponent& Inventory, const FInventoryEntryHandle& SourceEntry, const FInventoryEntryHandle& TargetEntry, int64 Quantity) const override;
	virtual FInventoryOperationPlan BuildSwapPlan(const UInventoryComponent& Inventory, const FInventoryEntryHandle& FirstEntry, const FInventoryEntryHandle& SecondEntry) const override;
	virtual FInventoryOperationPlan BuildClearPlan(const UInventoryComponent& Inventory) const override;

	UFUNCTION(BlueprintPure, Category = "Inventory|Strategy")
	int32 GetSlotCount() const { return SlotCount; }

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory|Strategy", meta = (AllowPrivateAccess = true, ClampMin = "1", UIMin = "1"))
	int32 SlotCount = 20;
};
