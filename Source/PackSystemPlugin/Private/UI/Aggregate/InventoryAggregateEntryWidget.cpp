// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Aggregate/InventoryAggregateEntryWidget.h"

void UInventoryAggregateEntryWidget::SetViewData(const FInventoryAggregateEntryViewData& NewViewData)
{
	ViewData = NewViewData;
	RefreshView();
}
