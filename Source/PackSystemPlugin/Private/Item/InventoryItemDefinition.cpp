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

bool UInventoryItemDefinition::RequiresItemInstance() const
{
	for (const UInventoryItemFragment* Fragment : Fragments)
	{
		if (IsValid(Fragment) && Fragment->RequiresItemInstance())
		{
			return true;
		}
	}

	return false;
}

int32 UInventoryItemDefinition::GetMaxStackSize() const
{
	return RequiresItemInstance() ? 1 : FMath::Max(1, MaxStackSize);
}

FInventoryItemPayload UInventoryItemDefinition::CreateItemPayload(
	const int64 Quantity,
	UObject* Outer) const
{
	if (Quantity <= 0)
	{
		return {};
	}

	UInventoryItemInstance* Instance = nullptr;
	if (RequiresItemInstance())
	{
		// 当前模型把 Instance 定义为单件物品的独立状态。
		if (Quantity != 1)
		{
			return {};
		}

		Instance = CreateItemInstance(Outer);
		if (!IsValid(Instance))
		{
			return {};
		}
	}

	return FInventoryItemPayload(
		const_cast<UInventoryItemDefinition*>(this),
		Quantity,
		Instance);
}

UInventoryItemInstance* UInventoryItemDefinition::CreateItemInstance(UObject* Outer) const
{
	if (!RequiresItemInstance())
	{
		return nullptr;
	}

	UObject* InstanceOuter = IsValid(Outer) ? Outer : GetTransientPackage();
	UInventoryItemInstance* Instance = NewObject<UInventoryItemInstance>(InstanceOuter);
	if (!IsValid(Instance))
	{
		return nullptr;
	}

	for (const UInventoryItemFragment* Fragment : Fragments)
	{
		if (IsValid(Fragment))
		{
			Fragment->OnInstanceCreated(Instance);
		}
	}

	return Instance;
}
