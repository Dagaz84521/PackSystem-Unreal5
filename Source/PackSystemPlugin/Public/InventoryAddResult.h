#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InventoryAddResult.generated.h"

UENUM(BlueprintType)
enum class EInventoryOperationStatus : uint8
{
	Failed,
	PartialSucceeded,
	Succeeded
};

USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryAddResult
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly)
	EInventoryOperationStatus OperationStatus = EInventoryOperationStatus::Failed;
	
	UPROPERTY(BlueprintReadOnly)
	int64 RequestedQuantity = 0;
	
	UPROPERTY(BlueprintReadOnly)
	int64 AcceptedQuantity = 0;
	
	UPROPERTY(BlueprintReadOnly)
	int64 RemainingQuantity = 0;
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayTag FailureReason;
};
