// Fill out your copyright notice in the Description page of Project Settings.


#include "MVC/Aggregate/InventoryAggregatePanelWidget.h"

void UInventoryAggregatePanelWidget::RequestUseItem(
	const FInventoryEntryHandle& EntryHandle)
{
	if (!EntryHandle.IsSet())
	{
		return;
	}

	OnUseItemRequested.Broadcast(EntryHandle);
}
