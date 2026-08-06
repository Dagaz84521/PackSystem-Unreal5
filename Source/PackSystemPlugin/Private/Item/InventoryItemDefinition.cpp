// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/InventoryItemDefinition.h"
#include "Item/InventoryItemFragment.h"
#include "Item/InventoryItemInstance.h"

void UInventoryItemDefinition::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer.AppendTags(ItemTags);
}

UInventoryItemFragment* UInventoryItemDefinition::FindFragmentByClass(
	TSubclassOf<UInventoryItemFragment> FragmentClass) const
{
	if (!FragmentClass)
	{
		return nullptr;
	}

	for (UInventoryItemFragment* Fragment : Fragments)
	{
		if (IsValid(Fragment) && Fragment->IsA(FragmentClass))
		{
			return Fragment;
		}
	}

	return nullptr;
}

UInventoryItemInstance* UInventoryItemDefinition::CreateItemInstance(UObject* Outer) const
{
	UObject* InstanceOuter = IsValid(Outer) ? Outer : GetTransientPackage();
	UInventoryItemInstance* Instance = NewObject<UInventoryItemInstance>(InstanceOuter);
	Instance->Initialize(const_cast<UInventoryItemDefinition*>(this));

	for (const UInventoryItemFragment* Fragment : Fragments)
	{
		if (IsValid(Fragment))
		{
			Fragment->OnInstanceCreated(Instance);
		}
	}

	return Instance;
}
