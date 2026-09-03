// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/Slotted/InventorySlottedEntryViewData.h"
#include "InventorySlottedEntryWidget.generated.h"

/**
 * 
 */
UCLASS()
class PACKSYSTEMPLUGIN_API UInventorySlottedEntryWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	/** 使用显示快照刷新当前 Widget。 */
	UFUNCTION(BlueprintCallable)
	void SetViewData(const FInventorySlottedEntryViewData& NewViewData);
	
	UFUNCTION(BlueprintImplementableEvent)
	void RefreshView();

private:
	UPROPERTY(BlueprintReadOnly, Category = "Inventory|View", meta = (AllowPrivateAccess = "true"))
	FInventorySlottedEntryViewData ViewData;
};
