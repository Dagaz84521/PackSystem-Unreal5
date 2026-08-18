#pragma once

#include "CoreMinimal.h"
#include "InventoryItemPayload.h"
#include "InventoryEntry.generated.h"

/** 一条库存记录，包含稳定标识以及可为空的物品内容。 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryEntry
{
	GENERATED_BODY()

	FInventoryEntry() = default;

	FInventoryEntry(
		const FInventoryItemPayload& InPayload,
		const int32 InEntryID)
		: Payload(InPayload)
		, EntryID(InEntryID)
	{
	}

	/** 当前 Entry 保存的物品堆；空 Payload 表示该 Entry 未存放物品。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	FInventoryItemPayload Payload;

	/** Entry 在所属背包内的稳定标识；INDEX_NONE 表示无效。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	int32 EntryID = INDEX_NONE;

	bool operator==(const FInventoryEntry& Other) const
	{
		return Payload == Other.Payload && EntryID == Other.EntryID;
	}

	bool operator!=(const FInventoryEntry& Other) const
	{
		return !(*this == Other);
	}
};
