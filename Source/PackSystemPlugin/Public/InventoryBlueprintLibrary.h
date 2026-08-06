#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InventoryBlueprintLibrary.generated.h"

class UInventoryItemInstance;

/** 不保存状态的公共辅助函数，让 C++ 与蓝图使用同一套物品判定规则。 */
UCLASS()
class PACKSYSTEMPLUGIN_API UInventoryBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 是否可放入同一堆叠；实际规则集中在 UInventoryItemInstance::CanStackWith。 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Item", meta = (DisplayName = "Can Stack Items"))
	static bool CanStackItems(const UInventoryItemInstance* ItemA, const UInventoryItemInstance* ItemB);
};
