// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItemFragment.generated.h"

class UInventoryItemInstance;

/**
 * 物品片段基类。
 *
 * Fragment 用于把一个物品的配置拆分成多个可复用的小模块，例如图标、重量、
 * 装备信息等。DefaultToInstanced 与 EditInlineNew 允许派生类以内联子对象的形式
 * 直接添加到 UInventoryItemDefinition 的 Fragments 数组中。
 */
UCLASS(DefaultToInstanced, BlueprintType, Blueprintable, EditInlineNew, Abstract)
class PACKSYSTEMPLUGIN_API UInventoryItemFragment : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * 当前 Fragment 是否要求每件物品拥有独立的运行时实例。
	 * 仅保存静态配置的 Fragment 保持默认 false；耐久度等动态 Fragment 应覆写为 true。
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category = "Inventory|Fragment")
	bool RequiresItemInstance() const;

	virtual bool RequiresItemInstance_Implementation() const;

	/**
	 * 当定义创建出一个运行时物品实例后调用。
	 * 派生 Fragment 可在此向实例写入初始状态；蓝图 Fragment 也可以覆写该事件。
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Inventory|Fragment")
	void OnInstanceCreated(UInventoryItemInstance* Instance) const;

	virtual void OnInstanceCreated_Implementation(UInventoryItemInstance* Instance) const;
};
