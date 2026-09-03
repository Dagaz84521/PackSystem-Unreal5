// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/InventoryUIControllerBase.h"
#include "InventoryAggregateUIController.generated.h"

struct FInventoryAggregateEntryViewData;
class UInventoryAggregatePanelWidget;
class UAggregateInventoryComponent;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class PACKSYSTEMPLUGIN_API UInventoryAggregateUIController : public UInventoryUIControllerBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void Initialize(UAggregateInventoryComponent* InInventory, UInventoryAggregatePanelWidget* InView);

	virtual void Shutdown() override;

protected:
	virtual void InventoryEntryAdded(const FInventoryEntryHandle& EntryHandle) override;
	virtual void InventoryEntryChanged(const FInventoryEntryHandle& EntryHandle) override;
	virtual void InventoryEntryRemoved(const FInventoryEntryHandle& EntryHandle) override;
	virtual void InventoryReset() override;

private:
	/** 当前绑定的 View。 */
	UPROPERTY()
	TObjectPtr<UInventoryAggregatePanelWidget> View;
	
	/** 响应界面发出的使用物品请求。 */
	UFUNCTION()
	void HandleUseItemRequested(FInventoryEntryHandle EntryHandle);
	
	void RefreshAllEntries();

	bool MakeEntryViewData(const FInventoryEntryHandle& EntryHandle, FInventoryAggregateEntryViewData& OutViewData) const;
};
