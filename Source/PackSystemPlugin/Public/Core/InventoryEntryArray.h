#pragma once

#include "CoreMinimal.h"
#include "Core/InventoryEntry.h"
#include "InventoryEntryArray.generated.h"

class UInventoryComponent;

USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryEntryArray
{
	GENERATED_BODY()

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Inventory")
	TArray<FInventoryEntry> ItemEntries;

	/** 运行时反向引用；组件注册时会重新设置该字段。 */
	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<UInventoryComponent> InventoryComponent;
};

/** 对指定背包组件所拥有 Entry 的稳定引用。 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryEntryHandle
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Inventory")
	int32 EntryID = INDEX_NONE;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Inventory")
	TObjectPtr<UInventoryComponent> ParentInventory = nullptr;

	FInventoryEntryHandle() = default;

	FInventoryEntryHandle(const FInventoryEntry& Other, UInventoryComponent* Inventory)
		: EntryID(Other.EntryID)
		, ParentInventory(Inventory)
	{
	}

	FInventoryEntryHandle(const int32 InEntryID, UInventoryComponent* Inventory)
		: EntryID(InEntryID)
		, ParentInventory(Inventory)
	{
	}

	bool operator==(const FInventoryEntryHandle& Other) const
	{
		return EntryID == Other.EntryID && ParentInventory == Other.ParentInventory;
	}

	bool operator!=(const FInventoryEntryHandle& Other) const
	{
		return !(*this == Other);
	}

	bool operator==(const FInventoryEntry& Other) const
	{
		return EntryID == Other.EntryID;
	}

	bool operator!=(const FInventoryEntry& Other) const
	{
		return !(*this == Other);
	}

	bool IsSet() const
	{
		return EntryID != INDEX_NONE && ParentInventory != nullptr;
	}
	
	bool IsValid() const
	{
		return EntryID != INDEX_NONE;
	}

	friend uint32 GetTypeHash(const FInventoryEntryHandle& Handle)
	{
		return HashCombine(GetTypeHash(Handle.EntryID), GetTypeHash(Handle.ParentInventory.Get()));
	}
};
