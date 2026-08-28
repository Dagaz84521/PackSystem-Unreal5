// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/InventoryEntryViewData.h"
#include "InventoryAggregatePanelWidget.generated.h"

/** 背包界面请求使用指定 Entry 中物品时触发。 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FInventoryUseItemRequestedSignature,
	FInventoryEntryHandle,
	EntryHandle);

/**
 * 
 */
UCLASS()
class PACKSYSTEMPLUGIN_API UInventoryAggregatePanelWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	/** 清空并重新生成整个背包界面。 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inventory|UI")
	void RebuildEntries(const TArray<FInventoryEntryViewData>& Entries);

	/** 创建新的 EntryWidget。 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inventory|UI")
	void AddEntry(const FInventoryEntryViewData& EntryData);

	/** 刷新已有的 EntryWidget。 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inventory|UI")
	void UpdateEntry(const FInventoryEntryViewData& EntryData);

	/** 删除 Handle 对应的 EntryWidget。 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inventory|UI")
	void RemoveEntry(const FInventoryEntryHandle& EntryHandle);

	/** 当界面请求使用指定 Entry 中的物品时触发。 */
	UPROPERTY(BlueprintAssignable, Category = "Inventory|UI")
	FInventoryUseItemRequestedSignature OnUseItemRequested;

	/** 由蓝图界面提交使用物品请求。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void RequestUseItem(const FInventoryEntryHandle& EntryHandle);
};
