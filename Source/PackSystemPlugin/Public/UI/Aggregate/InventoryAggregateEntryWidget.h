// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/InventoryEntryViewData.h"
#include "InventoryAggregateEntryWidget.generated.h"
/**
 *  
 */
UCLASS()
class PACKSYSTEMPLUGIN_API UInventoryAggregateEntryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	/** 使用显示快照刷新当前 Widget。 */
	UFUNCTION(BlueprintCallable)
	void SetViewData(const FInventoryEntryViewData& NewViewData);
	
	UFUNCTION(BlueprintImplementableEvent)
	void RefreshView();

private:
	UPROPERTY(BlueprintReadOnly, Category = "Inventory|View", meta = (AllowPrivateAccess = "true"))
	FInventoryEntryViewData ViewData;
};
