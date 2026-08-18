// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryEntryArray.h"
#include "InventoryItemPayload.h"
#include "UObject/Object.h"
#include "InventoryAggregateUIController.generated.h"

struct FInventoryEntryViewData;
class UInventoryAggregatePanelWidget;
class UAggregateInventoryComponent;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class PACKSYSTEMPLUGIN_API UInventoryAggregateUIController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void Initialize(UAggregateInventoryComponent* InInventory, UInventoryAggregatePanelWidget* InView);
	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void Shutdown();

private:
	/** 当前 UI 观察的背包 Model。 */
	UPROPERTY()
	TObjectPtr<UAggregateInventoryComponent> Inventory;

	/** 当前绑定的 View。 */
	UPROPERTY()
	TObjectPtr<UInventoryAggregatePanelWidget> View;
	
	UFUNCTION()
	void HandleEntryAdded(FInventoryEntryHandle EntryHandle);

	UFUNCTION()
	void HandleEntryChanged(FInventoryEntryHandle EntryHandle);

	UFUNCTION()
	void HandleEntryRemoved(FInventoryEntryHandle EntryHandle);

	UFUNCTION()
	void HandleInventoryReset();

	/** 响应界面发出的使用物品请求。 */
	UFUNCTION()
	void HandleUseItemRequested(FInventoryEntryHandle EntryHandle);
	
	void RefreshAllEntries();

	bool MakeEntryViewData(const FInventoryEntryHandle& EntryHandle, FInventoryEntryViewData& OutViewData) const;
};
