// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/InventoryItemInstance.h"

#include "UObject/UObjectGlobals.h"

void UInventoryItemInstance::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer.AppendTags(InstanceTags);
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
bool UInventoryItemInstance::IsMatching(const UInventoryItemInstance* InstanceA,
	const UInventoryItemInstance* InstanceB)
{
	if (!IsValid(InstanceA) || !IsValid(InstanceB))
	{
		return false;
	}

	// TODO：加入动态 Fragment 后，也需要比较影响堆叠兼容性的状态。
	return InstanceA->InstanceTags == InstanceB->InstanceTags;
}

UInventoryItemInstance* UInventoryItemInstance::DuplicateInstance(UObject* Outer) const
{
	UObject* InstanceOuter = IsValid(Outer) ? Outer : GetTransientPackage();
	return DuplicateObject<UInventoryItemInstance>(this, InstanceOuter);
}
