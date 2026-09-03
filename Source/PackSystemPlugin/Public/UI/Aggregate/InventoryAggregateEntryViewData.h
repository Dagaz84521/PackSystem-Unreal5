#pragma once
#include "CoreMinimal.h"
#include "Core/InventoryEntryArray.h"
#include "InventoryAggregateEntryViewData.generated.h"

USTRUCT(BlueprintType)
struct FInventoryAggregateEntryViewData
{
	GENERATED_BODY()

	/** 用于识别该 UI 项对应哪个 Entry。 */
	UPROPERTY(BlueprintReadOnly)
	FInventoryEntryHandle EntryHandle;

	/** UI 显示名称。 */
	UPROPERTY(BlueprintReadOnly)
	FText DisplayName;

	/** UI 显示说明。 */
	UPROPERTY(BlueprintReadOnly)
	FText Description;

	/** 当前物品数量。 */
	UPROPERTY(BlueprintReadOnly)
	int64 Quantity = 0;

	/** UI 图标。 */
	UPROPERTY(BlueprintReadOnly)
	TSoftObjectPtr<UTexture2D> Icon;
	
	FInventoryAggregateEntryViewData() = default;
	
	FInventoryAggregateEntryViewData(const FInventoryEntryHandle& EntryHandle, 
		const FText& DisplayName, const FText& Description, int64 Quantity, TSoftObjectPtr<UTexture2D> Icon = nullptr)
			: EntryHandle(EntryHandle), DisplayName(DisplayName), Description(Description), Quantity(Quantity), Icon(Icon){};
};
