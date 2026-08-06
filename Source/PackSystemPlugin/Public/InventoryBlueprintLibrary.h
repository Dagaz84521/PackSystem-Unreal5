#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InventoryBlueprintLibrary.generated.h"

class UInventoryItemInstance;

/**
 * Stateless helper functions shared by inventory Blueprints.
 */
UCLASS()
class PACKSYSTEMPLUGIN_API UInventoryBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Returns whether two item instances can be stored in the same stack. */
	UFUNCTION(BlueprintPure, Category = "Inventory|Item", meta = (DisplayName = "Can Stack Items"))
	static bool CanStackItems(const UInventoryItemInstance* ItemA, const UInventoryItemInstance* ItemB);
};
