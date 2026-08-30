#pragma once

#include "CoreMinimal.h"
#include "Core/InventoryItemPayload.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Core/InventoryEntryArray.h"
#include "InventoryBlueprintLibrary.generated.h"

struct FInventoryEntryHandle;

/**
 * Stateless helper functions shared by inventory Blueprints.
 */
UCLASS()
class PACKSYSTEMPLUGIN_API UInventoryBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 返回两个 Payload 是否可以保存在同一个物品堆中。 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Item", meta = (DisplayName = "Can Stack Items"))
	static bool IsMatching(const FInventoryItemPayload& ItemA, const FInventoryItemPayload& ItemB);
	
	/** 判断两个 EntryHandle 是否指向同一个背包中的同一个 Entry。 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Entry",
		meta = (
			DisplayName = "Equal (Inventory Entry Handle)",
			CompactNodeTitle = "==",
			Keywords = "== equal"
		))
	static bool AreEntryHandlesEqual(
		const FInventoryEntryHandle& A,
		const FInventoryEntryHandle& B);
};
