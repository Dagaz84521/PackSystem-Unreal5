// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/InventoryItemPayload.h"
#include "GameplayTagAssetInterface.h"
#include "Engine/DataAsset.h"
#include "InventoryItemDefinition.generated.h"

class UInventoryItemFragment;
class UInventoryItemInstance;

/**
 * 物品的静态定义资产。
 *
 * 同一种物品的名称、描述、标签和 Fragment 配置只保存一份。普通物品只需要
 * Definition 和数量；任一 Fragment 声明需要动态状态时，物品才创建可选实例。
 */
UCLASS(BlueprintType)
class PACKSYSTEMPLUGIN_API UInventoryItemDefinition : public UPrimaryDataAsset, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	/** 将定义资产拥有的标签追加到输出容器。 */
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

	/** 根据类型查找第一个匹配的 Fragment，支持传入派生类。 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Definition", meta = (DeterminesOutputType = "FragmentClass"))
	UInventoryItemFragment* FindFragmentByClass(TSubclassOf<UInventoryItemFragment> FragmentClass) const;

	/** 根据当前定义创建 Payload；无状态物品不会创建 ItemInstance。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Definition", meta = (DefaultToSelf = "Outer"))
	FInventoryItemPayload CreateItemPayload(int64 Quantity, UObject* Outer) const;

	/** 当前定义是否要求每件物品携带独立的运行时实例。 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Definition")
	bool RequiresItemInstance() const;

	/** 创建并初始化运行时实例；无状态定义返回 nullptr。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Definition", meta = (DefaultToSelf = "Outer"))
	UInventoryItemInstance* CreateItemInstance(UObject* Outer) const;

	/** 返回单个物品槽允许保存的最大数量。 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Definition")
	int32 GetMaxStackSize() const;

	/** 返回物品在 UI 中显示的名称。 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Display")
	FText GetDisplayName() const { return DisplayName; }

	/** 返回物品在 UI 中显示的详细说明。 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Display")
	FText GetDescription() const { return Description; }

	/** C++ 侧的强类型 Fragment 查找辅助函数。 */
	template <typename FragmentType>
	const FragmentType* FindFragment() const
	{
		return Cast<FragmentType>(FindFragmentByClass(FragmentType::StaticClass()));
	}
	
protected:
	/** 编辑器和 UI 中显示的物品名称。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Display")
	FText DisplayName;

	/** 物品的详细说明。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Display", meta = (MultiLine = true))
	FText Description;
	
	/** 物品的模板ID */
	FGameplayTag TemplateID;

	/** 描述物品类别和特性的静态 Gameplay Tag。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Tags")
	FGameplayTagContainer ItemTags;

	/** 无实例物品在单个槽位允许保存的最大数量。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Stack", meta = (ClampMin = "1", UIMin = "1"))
	int32 MaxStackSize = 1;

	/**
	 * 组成物品定义的内联配置片段。
	 * Instanced 使数组元素成为当前 DataAsset 的子对象，而不是独立资产引用。
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "Inventory|Fragments")
	TArray<TObjectPtr<UInventoryItemFragment>> Fragments;
};
