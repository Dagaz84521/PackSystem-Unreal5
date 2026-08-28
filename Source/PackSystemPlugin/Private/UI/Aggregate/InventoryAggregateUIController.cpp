// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Aggregate/InventoryAggregateUIController.h"

#include "Inventory/Aggregate/AggregateInventoryComponent.h"
#include "Fragments/IconFragment.h"
#include "Item/InventoryItemDefinition.h"
#include "Item/InventoryItemInstance.h"
#include "UI/InventoryEntryViewData.h"
#include "UI/Aggregate/InventoryAggregatePanelWidget.h"

void UInventoryAggregateUIController::Initialize(UAggregateInventoryComponent* InInventory,
	UInventoryAggregatePanelWidget* InView)
{
	Shutdown();
	
	if (!IsValid(InInventory) || !IsValid(InView))
	{
		return;
	}
	
	Inventory = InInventory;
	View = InView;
	
	Inventory->OnEntryAdded.AddDynamic(this, &UInventoryAggregateUIController::HandleEntryAdded);
	Inventory->OnEntryChanged.AddDynamic(this, &UInventoryAggregateUIController::HandleEntryChanged);
	Inventory->OnEntryRemoved.AddDynamic(this, &UInventoryAggregateUIController::HandleEntryRemoved);
	Inventory->OnInventoryReset.AddDynamic(this, &ThisClass::HandleInventoryReset);
	View->OnUseItemRequested.AddDynamic(this, &ThisClass::HandleUseItemRequested);
	
	RefreshAllEntries();
}

void UInventoryAggregateUIController::Shutdown()
{
	if (IsValid(Inventory))
	{
		Inventory->OnEntryAdded.RemoveDynamic(this, &ThisClass::HandleEntryAdded);

		Inventory->OnEntryChanged.RemoveDynamic(this, &ThisClass::HandleEntryChanged);

		Inventory->OnEntryRemoved.RemoveDynamic(this, &ThisClass::HandleEntryRemoved);

		Inventory->OnInventoryReset.RemoveDynamic(this, &ThisClass::HandleInventoryReset);
	}

	if (IsValid(View))
	{
		View->OnUseItemRequested.RemoveDynamic(this, &ThisClass::HandleUseItemRequested);
	}

	Inventory = nullptr;
	View = nullptr;
}

void UInventoryAggregateUIController::HandleEntryAdded(FInventoryEntryHandle EntryHandle)
{
	if (!IsValid(View) || !IsValid(Inventory))
	{
		return;
	}
	FInventoryEntryViewData EntryData;
	if (MakeEntryViewData(EntryHandle, EntryData))
	{
		View->AddEntry(EntryData);
	}
}

void UInventoryAggregateUIController::HandleEntryChanged(FInventoryEntryHandle EntryHandle)
{
	if (!IsValid(View) || !IsValid(Inventory))
	{
		return;
	}
	FInventoryEntryViewData EntryData;
	if (MakeEntryViewData(EntryHandle, EntryData))
	{
		View->UpdateEntry(EntryData);
	}
}

void UInventoryAggregateUIController::HandleEntryRemoved(FInventoryEntryHandle EntryHandle)
{
	if (!IsValid(View) || !IsValid(Inventory))
	{
		return;
	}
	View->RemoveEntry(EntryHandle);
}

void UInventoryAggregateUIController::HandleInventoryReset()
{
	RefreshAllEntries();
}

void UInventoryAggregateUIController::RefreshAllEntries()
{
	if (!IsValid(View))
	{
		return;
	}
	TArray<FInventoryEntryViewData> EntriesViewData;
	if (!IsValid(Inventory))
	{
		View->RebuildEntries(EntriesViewData);
		return;
	}
	const TArray<FInventoryEntryHandle>& InventoryHandles = Inventory->GetAllEntryHandles();
	EntriesViewData.Reserve(InventoryHandles.Num());
	for (const FInventoryEntryHandle& Handle : InventoryHandles)
	{
		FInventoryEntryViewData EntryData;
		if (MakeEntryViewData(Handle, EntryData))
		{
			EntriesViewData.Add(EntryData);
		}
	}
	View->RebuildEntries(EntriesViewData);
}

bool UInventoryAggregateUIController::MakeEntryViewData(const FInventoryEntryHandle& EntryHandle,
	FInventoryEntryViewData& OutViewData) const
{
	// 失败时保证输出数据为空，避免调用者使用旧数据。
	OutViewData = FInventoryEntryViewData();

	if (!IsValid(Inventory))
	{
		return false;
	}

	FInventoryEntry Entry;
	if (!Inventory->GetEntry(EntryHandle, Entry))
	{
		return false;
	}

	if (!Entry.Payload.IsValid())
	{
		return false;
	}

	UInventoryItemInstance* ItemInstance = Entry.Payload.ItemInstance;

	if (!IsValid(ItemInstance))
	{
		return false;
	}

	UInventoryItemDefinition* ItemDefinition = ItemInstance->GetItemDefinition();

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
	if (!IsValid(Inventory) || !EntryHandle.IsSet())
	{
		return;
	}

	// 原型阶段不执行物品效果，仅扣除一个数量。
	Inventory->ExtractItemFromEntry(EntryHandle, 1);
}
