#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InventoryEntryArray.h"
#include "InventoryOperationTypes.generated.h"

class UInventoryItemInstance;

UENUM(BlueprintType)
enum class EInventoryOperationStatus : uint8
{
	Failed,
	PartialSucceeded,
	Succeeded
};

USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryEntryState
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	TObjectPtr<UInventoryItemInstance> ItemInstance = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory", meta = (ClampMin = "0"))
	int64 Quantity = 0;

	FInventoryEntryState() = default;
	FInventoryEntryState(UInventoryItemInstance* InItemInstance, const int64 InQuantity)
		: ItemInstance(InItemInstance), Quantity(InQuantity)
	{
	}

	bool HasValidState() const
	{
		return (ItemInstance == nullptr && Quantity == 0)
			|| (::IsValid(ItemInstance) && Quantity > 0);
	}

	bool operator==(const FInventoryEntryState& Other) const
	{
		return ItemInstance == Other.ItemInstance && Quantity == Other.Quantity;
	}

	bool operator!=(const FInventoryEntryState& Other) const { return !(*this == Other); }
};

UENUM()
enum class EInventoryEntryMutationType : uint8
{
	Create,
	Update,
	Delete
};

USTRUCT()
struct PACKSYSTEMPLUGIN_API FInventoryEntryMutation
{
	GENERATED_BODY()

	UPROPERTY()
	EInventoryEntryMutationType Type = EInventoryEntryMutationType::Update;

	UPROPERTY()
	FInventoryEntryHandle TargetEntry;

	UPROPERTY()
	FInventoryEntryState ExpectedState;

	UPROPERTY()
	FInventoryEntryState DesiredState;

	UPROPERTY()
	bool bDuplicateItemInstance = false;
};

USTRUCT()
struct PACKSYSTEMPLUGIN_API FInventoryOperationPlan
{
	GENERATED_BODY()

	int64 RequestedQuantity = 0;
	int64 PlannedQuantity = 0;
	int64 RemainingQuantity = 0;
	FGameplayTag FailureReason;
	TArray<FInventoryEntryMutation> Mutations;
};

USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryOperationResult
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	EInventoryOperationStatus Status = EInventoryOperationStatus::Failed;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	int64 RequestedQuantity = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	int64 ProcessedQuantity = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	int64 RemainingQuantity = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	FGameplayTag FailureReason;
};

USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryEntryChange
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	FInventoryEntryHandle EntryHandle;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	FInventoryEntryState Before;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	FInventoryEntryState After;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	bool bEntryCreated = false;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	bool bEntryDeleted = false;
};

USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryChangeSet
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	TArray<FInventoryEntryChange> Changes;
};
