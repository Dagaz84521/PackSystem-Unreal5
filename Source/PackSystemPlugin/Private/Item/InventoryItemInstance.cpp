// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/InventoryItemInstance.h"

#include "Item/InventoryItemDefinition.h"

void UInventoryItemInstance::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	if (IsValid(ItemDefinition))
	{
		ItemDefinition->GetOwnedGameplayTags(TagContainer);
	}

	TagContainer.AppendTags(InstanceTags);
}

UInventoryItemFragment* UInventoryItemInstance::FindFragmentByClass(
	TSubclassOf<UInventoryItemFragment> FragmentClass) const
{
	return IsValid(ItemDefinition) ? ItemDefinition->FindFragmentByClass(FragmentClass) : nullptr;
}

void UInventoryItemInstance::AddInstanceTag(FGameplayTag Tag)
{
	if (Tag.IsValid())
	{
		InstanceTags.AddTag(Tag);
	}
}

void UInventoryItemInstance::RemoveInstanceTag(FGameplayTag Tag)
{
	if (Tag.IsValid())
	{
		InstanceTags.RemoveTag(Tag);
	}
}


void UInventoryItemInstance::Initialize(UInventoryItemDefinition* InItemDefinition)
{
	ItemDefinition = InItemDefinition;
}

bool UInventoryItemInstance::CanStackWith(const UInventoryItemInstance* InstanceA,
	const UInventoryItemInstance* InstanceB)
{
	if (!IsValid(InstanceA) || !IsValid(InstanceB))
	{
		return false;
	}

	// Definition 决定物品种类，InstanceTags 则区分同一定义下的运行时状态。
	// 动态 Fragment 状态加入实例后，还需要在这里扩展等价比较。
	if (InstanceA->ItemDefinition == InstanceB->ItemDefinition && InstanceA->InstanceTags == InstanceB->InstanceTags)
		return true;
	return false;
}
