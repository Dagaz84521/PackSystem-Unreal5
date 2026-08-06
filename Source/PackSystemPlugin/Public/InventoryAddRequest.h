#pragma once

#include "CoreMinimal.h"
#include "InventoryAddContext.h"
#include "Item/InventoryItemInstance.h"
#include "InstancedStruct.h"
#include "InventoryAddRequest.generated.h"

USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryAddRequest
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UInventoryItemInstance> InventoryItemInstance = nullptr;
	
	UPROPERTY(BlueprintReadWrite)
	int64 Quantity = 0;
	
	// 当前存储策略所需的附加数据，例如目标 Entry 或二维网格坐标。
	UPROPERTY(BlueprintReadWrite)
	TInstancedStruct<FInventoryAddContext> AddContext;
};
