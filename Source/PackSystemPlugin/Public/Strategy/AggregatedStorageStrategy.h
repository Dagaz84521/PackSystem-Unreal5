// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryStorageStrategy.h"
#include "AggregatedStorageStrategy.generated.h"

/**
 * 
 */
UCLASS()
class PACKSYSTEMPLUGIN_API UAggregatedStorageStrategy : public UInventoryStorageStrategy
{
	GENERATED_BODY()
public:
	virtual FInventoryAddPlan BuildAddPlan(
		const UInventoryComponent& Inventory,
		const FInventoryAddRequest& Request) const override;
	
	FInventoryEntryHandle GetCanStackEntryHandle(const UInventoryComponent& Inventory, const UInventoryItemInstance* ItemToStack) const;
};
