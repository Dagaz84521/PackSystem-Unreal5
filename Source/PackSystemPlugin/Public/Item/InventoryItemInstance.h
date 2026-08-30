// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItemInstance.generated.h"

/**
 * 物品可选的运行时动态状态。
 *
 * 物品类型由 FInventoryItemPayload 中的 UInventoryItemDefinition 表示；该对象只保存
 * 耐久度、随机词条、运行时标签等会在游戏过程中变化的数据。
 */
UCLASS(BlueprintType)
class PACKSYSTEMPLUGIN_API UInventoryItemInstance : public UObject, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	/** 返回当前实例拥有的动态标签。 */
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

	/** 为当前实例添加一个运行时标签。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Instance")
	void AddInstanceTag(FGameplayTag Tag);

	/** 从当前实例移除一个运行时标签。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Instance")
	void RemoveInstanceTag(FGameplayTag Tag);
	
	/** 判断两个动态实例是否具有相同的可堆叠状态。 */
	static bool IsMatching(const UInventoryItemInstance* InstanceA, const UInventoryItemInstance* InstanceB);

	/**
	 * 显式复制当前动态状态。
	 * 当前有实例物品的数量固定为 1，普通堆叠拆分不会调用该函数。
	 */
	UInventoryItemInstance* DuplicateInstance(UObject* Outer = nullptr) const;

private:
	/** 仅属于当前实例、可在运行时变化的标签。 */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Inventory|Instance", meta = (AllowPrivateAccess = true))
	FGameplayTagContainer InstanceTags;
	
	/*TODO: 动态变化的Fragments*/
	
};
