// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/InventoryItemInstance.h"

#include "Item/InventoryItemDefinition.h"
#include "UObject/UObjectGlobals.h"

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

bool UInventoryItemInstance::IsMatching(const UInventoryItemInstance* InstanceA,
	const UInventoryItemInstance* InstanceB)
{
	if (!IsValid(InstanceA) || !IsValid(InstanceB))
	{
		return false;
	}

	// ItemDefinition是否相同，且拥有相同的Tags
	// TODO：动态Fragments相同
	if (InstanceA->ItemDefinition == InstanceB->ItemDefinition && InstanceA->InstanceTags == InstanceB->InstanceTags)
		return true;
	return false;
}

UInventoryItemInstance* UInventoryItemInstance::DuplicateInstance(UObject* Outer) const
{
	UObject* InstanceOuter = IsValid(Outer) ? Outer : GetTransientPackage();
	return DuplicateObject<UInventoryItemInstance>(this, InstanceOuter);
}
