#pragma once

#include "CoreMinimal.h"
#include "InventoryEntry.h"
#include "InventoryEntryArray.generated.h"

/** 库存真正持久保存的数据；Handle 列表由该数组按需生成，避免双份缓存失配。 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryEntryArray
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly)
	TArray<FInventoryEntry> ItemEntries;

	UPROPERTY()
	TObjectPtr<UInventoryComponent> InventoryComponent;
};

/**
 * Entry 的稳定外部引用，由“容器 + 容器内唯一 ID”组成，不能把数组下标当作 Handle。
 * Slot 清空后 Handle 继续有效；Aggregate 删除记录后对应 Handle 立即失效。
 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryEntryHandle
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
	int32 EntryID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
	TObjectPtr<UInventoryComponent> ParentInventory;

	FInventoryEntryHandle()
		: EntryID(INDEX_NONE)
		, ParentInventory(nullptr)
	{
	}

	FInventoryEntryHandle(const FInventoryEntryHandle& Other)
		: EntryID(Other.EntryID)
		, ParentInventory(Other.ParentInventory)
	{
	}

	FInventoryEntryHandle(const FInventoryEntry& Other, UInventoryComponent* Inventory)
		: EntryID(Other.EntryID)
		, ParentInventory(Inventory)
	{
	}

	FInventoryEntryHandle(int32 InEntryID, UInventoryComponent* Inventory)
		: EntryID(InEntryID)
		, ParentInventory(Inventory)
	{
	}

	bool operator==(const FInventoryEntryHandle& Other) const
	{
		return EntryID == Other.EntryID && ParentInventory == Other.ParentInventory;
	}

	bool operator!=(const FInventoryEntryHandle& Other) const { return !(*this == Other); }
	bool operator==(const FInventoryEntry& Other) const { return EntryID == Other.EntryID; }
	bool operator!=(const FInventoryEntry& Other) const { return !(*this == Other); }

	bool IsValid() const
	{
		return EntryID != INDEX_NONE && ParentInventory != nullptr;
	}
};
