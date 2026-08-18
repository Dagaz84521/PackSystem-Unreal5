#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InventoryEntryArray.h"
#include "InventoryBlueprintLibrary.generated.h"

struct FInventoryEntryHandle;
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
	static bool IsMatching(const UInventoryItemInstance* ItemA, const UInventoryItemInstance* ItemB);
	
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
