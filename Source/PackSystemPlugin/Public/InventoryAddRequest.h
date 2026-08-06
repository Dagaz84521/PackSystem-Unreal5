#pragma once

#include "CoreMinimal.h"
#include "InventoryEntryArray.h"
#include "Item/InventoryItemInstance.h"
#include "InventoryAddRequest.generated.h"

/** 添加意图；无效 TargetEntry 表示自动放置，有效 TargetEntry 表示只尝试该位置。 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryAddRequest
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	TObjectPtr<UInventoryItemInstance> InventoryItemInstance = nullptr;
	
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int64 Quantity = 0;
	
	/** 无效 Handle 表示自动放置。 */
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	FInventoryEntryHandle TargetEntry;
};
