// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItemInstance.generated.h"

class UInventoryItemDefinition;
class UInventoryItemFragment;

/**
 * 背包中物品的运行时实例。
 * 实例引用一个静态 UInventoryItemDefinition，并只保存会在游戏过程中变化的数据，例如实例标签和当前堆叠数量。
 */
UCLASS(BlueprintType)
class PACKSYSTEMPLUGIN_API UInventoryItemInstance : public UObject, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	/** 返回“定义标签 + 实例标签”的合集。 */
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

	/** 返回该实例使用的静态物品定义。 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Instance")
	UInventoryItemDefinition* GetItemDefinition() const { return ItemDefinition; }

	/** 从物品定义中查找指定类型的 Fragment。 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Instance", meta = (DeterminesOutputType = "FragmentClass"))
	UInventoryItemFragment* FindFragmentByClass(TSubclassOf<UInventoryItemFragment> FragmentClass) const;

	/** 为当前实例添加一个运行时标签。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Instance")
	void AddInstanceTag(FGameplayTag Tag);

	/** 从当前实例移除一个运行时标签。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Instance")
	void RemoveInstanceTag(FGameplayTag Tag);
	
	/** 由 UInventoryItemDefinition 在创建实例时调用。 */
	void Initialize(UInventoryItemDefinition* InItemDefinition);
	
	/** 判断两个是否可以叠加 */
	static bool IsMatching(const UInventoryItemInstance* InstanceA, const UInventoryItemInstance* InstanceB);

	/**
	 * 复制当前运行时实例。
	 * 拆分物品堆时使用，使拆出的物品与原物品堆不共享可变的运行时状态。
	 */
	UInventoryItemInstance* DuplicateInstance(UObject* Outer = nullptr) const;

private:
	/** 当前实例引用的静态定义。 */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Inventory|Instance", meta = (AllowPrivateAccess = true))
	TObjectPtr<UInventoryItemDefinition> ItemDefinition;

	/** 仅属于当前实例、可在运行时变化的标签。 */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Inventory|Instance", meta = (AllowPrivateAccess = true))
	FGameplayTagContainer InstanceTags;
	
	/*TODO: 动态变化的Fragments*/
	
};
