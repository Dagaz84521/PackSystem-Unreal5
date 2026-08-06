#pragma once

#include "CoreMinimal.h"
#include "InventoryEntryArray.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UInventoryItemInstance;
class UInventoryStorageStrategy;

UCLASS(BlueprintType, Blueprintable, ClassGroup = (Inventory), meta = (BlueprintSpawnableComponent))
class PACKSYSTEMPLUGIN_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	virtual bool LootItem(UInventoryItemInstance* ItemInstance);
	
	UFUNCTION(BlueprintPure, Category = "Inventory")
	virtual TArray<FInventoryEntryHandle> GetAllEntries() const;
	
	virtual FInventoryEntry FindEntryFromHandle(const FInventoryEntryHandle& EntryHandle) const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory",
	meta = (ClampMin = "1"))
	int32 InitialEntryCount = 20;
	
	virtual void BeginPlay() override;
	
	// TODO: 检查EntryHandle是否有效
	virtual bool IsValidEntryHandle(FInventoryEntryHandle EntryHandle) const;
	// TODO: 根据EntryHandle获得对应的Entry
	
	// TODO: 创建Entry
	virtual void CreateInventoryEntry();
	// TODO: 删除Entry
	virtual void RemoveInventoryEntry(FInventoryEntryHandle EntryHandle);
	// TODO: PlaceItemIntoEntry
	virtual bool PlaceItemIntoEntry(UInventoryItemInstance* ItemInstance, FInventoryEntryHandle EntryHandle);
	
	virtual bool AcceptsItem(UInventoryItemInstance* ItemInstance, FInventoryEntryHandle EntryHandle);
	
	UPROPERTY(VisibleInstanceOnly)
	FInventoryEntryArray EntryArray;
	
	TArray<FInventoryEntryHandle> AllEntryHandles;
};
