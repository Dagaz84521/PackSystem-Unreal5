#pragma once

#include "CoreMinimal.h"
#include "InventoryOperationTypes.h"
#include "UObject/Object.h"
#include "InventoryTestListener.generated.h"

UCLASS()
class UInventoryTestListener : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleInventoryChanged(const FInventoryChangeSet& ChangeSet);

	int32 CallCount = 0;
	int32 LastChangeCount = 0;
};
