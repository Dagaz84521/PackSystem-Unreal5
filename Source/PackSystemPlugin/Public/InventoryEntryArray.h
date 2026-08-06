#pragma once

#include "CoreMinimal.h"
#include "InventoryEntry.h"
#include "InventoryEntryArray.generated.h"

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
};
