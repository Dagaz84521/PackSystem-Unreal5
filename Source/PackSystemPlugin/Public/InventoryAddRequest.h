#pragma once

#include "CoreMinimal.h"
#include "InventoryEntryArray.h"
#include "Item/InventoryItemInstance.h"
#include "InventoryAddRequest.generated.h"

USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryAddRequest
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	TObjectPtr<UInventoryItemInstance> InventoryItemInstance = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int64 Quantity = 0;
	
	/** Invalid handle means automatic placement. */
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	FInventoryEntryHandle TargetEntry;
};
