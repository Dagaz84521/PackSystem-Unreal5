// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Aggregate/InventoryAggregateUIController.h"

#include "Inventory/Aggregate/AggregateInventoryComponent.h"
#include "Fragments/IconFragment.h"
#include "Item/InventoryItemDefinition.h"
#include "UI/Aggregate/InventoryAggregateEntryViewData.h"
#include "UI/Aggregate/InventoryAggregatePanelWidget.h"

void UInventoryAggregateUIController::Initialize(UAggregateInventoryComponent* InInventory,
	UInventoryAggregatePanelWidget* InView)
{
	Shutdown();
	
	if (!IsValid(InInventory) || !IsValid(InView))
	{
		return;
	}
	
	View = InView;
	if (!BindInventory(InInventory))
	{
		View = nullptr;
		return;
	}

	View->OnUseItemRequested.AddDynamic(this, &ThisClass::HandleUseItemRequested);
	
	RefreshAllEntries();
}

void UInventoryAggregateUIController::Shutdown()
{
	if (IsValid(View))
	{
		View->OnUseItemRequested.RemoveDynamic(this, &ThisClass::HandleUseItemRequested);
	}

	View = nullptr;
	Super::Shutdown();
}

void UInventoryAggregateUIController::InventoryEntryAdded(
	const FInventoryEntryHandle& EntryHandle)
{
	if (!IsValid(View) || !IsValid(GetInventory()))
	{
		return;
	}
	FInventoryAggregateEntryViewData EntryData;
	if (MakeEntryViewData(EntryHandle, EntryData))
	{
		View->AddEntry(EntryData);
	}
}

void UInventoryAggregateUIController::InventoryEntryChanged(
	const FInventoryEntryHandle& EntryHandle)
{
	if (!IsValid(View) || !IsValid(GetInventory()))
	{
		return;
	}
	FInventoryAggregateEntryViewData EntryData;
	if (MakeEntryViewData(EntryHandle, EntryData))
	{
		View->UpdateEntry(EntryData);
	}
}

void UInventoryAggregateUIController::InventoryEntryRemoved(
	const FInventoryEntryHandle& EntryHandle)
{
	if (!IsValid(View) || !IsValid(GetInventory()))
	{
		return;
	}
	View->RemoveEntry(EntryHandle);
}

void UInventoryAggregateUIController::InventoryReset()
{
	RefreshAllEntries();
}

void UInventoryAggregateUIController::RefreshAllEntries()
{
	if (!IsValid(View))
	{
		return;
	}
	TArray<FInventoryAggregateEntryViewData> EntriesViewData;
	UInventoryComponent* BoundInventory = GetInventory();
	if (!IsValid(BoundInventory))
	{
		View->RebuildEntries(EntriesViewData);
		return;
	}
	const TArray<FInventoryEntryHandle>& InventoryHandles = BoundInventory->GetAllEntryHandles();
	EntriesViewData.Reserve(InventoryHandles.Num());
	for (const FInventoryEntryHandle& Handle : InventoryHandles)
	{
		FInventoryAggregateEntryViewData EntryData;
		if (MakeEntryViewData(Handle, EntryData))
		{
			EntriesViewData.Add(EntryData);
		}
	}
	View->RebuildEntries(EntriesViewData);
}

bool UInventoryAggregateUIController::MakeEntryViewData(const FInventoryEntryHandle& EntryHandle,
	FInventoryAggregateEntryViewData& OutViewData) const
{
	// 失败时保证输出数据为空，避免调用者使用旧数据。
	OutViewData = FInventoryAggregateEntryViewData();

	UInventoryComponent* BoundInventory = GetInventory();
	if (!IsValid(BoundInventory))
	{
		return false;
	}

	FInventoryEntry Entry;
	if (!BoundInventory->GetEntry(EntryHandle, Entry))
	{
		return false;
	}

	if (!Entry.Payload.IsValid())
	{
		return false;
	}

	UInventoryItemDefinition* ItemDefinition = Entry.Payload.ItemDefinition;

	if (!IsValid(ItemDefinition))
	{
		return false;
	}

	OutViewData.EntryHandle = EntryHandle;
	OutViewData.DisplayName = ItemDefinition->GetDisplayName();
	OutViewData.Description = ItemDefinition->GetDescription();
	OutViewData.Quantity = Entry.Payload.Quantity;

	// 图标是可选数据，没有 IconFragment 不会导致转换失败。
	if (const UIconFragment* IconFragment =Cast<UIconFragment>(ItemDefinition->FindFragmentByClass(UIconFragment::StaticClass())))
	{
		OutViewData.Icon = IconFragment->Icon;
	}

	return true;
}

void UInventoryAggregateUIController::HandleUseItemRequested(
	FInventoryEntryHandle EntryHandle)
{
	UAggregateInventoryComponent* AggregateInventory =
		Cast<UAggregateInventoryComponent>(GetInventory());
	if (!IsValid(AggregateInventory) || !EntryHandle.IsSet())
	{
		return;
	}

	// 原型阶段不执行物品效果，仅扣除一个数量。
	AggregateInventory->ExtractItemFromEntry(EntryHandle, 1);
}
