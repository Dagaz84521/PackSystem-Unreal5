// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Slotted/InventorySlottedEntryWidget.h"

void UInventorySlottedEntryWidget::SetViewData(const FInventorySlottedEntryViewData& NewViewData)
{
	ViewData = NewViewData;
	RefreshView();
}
