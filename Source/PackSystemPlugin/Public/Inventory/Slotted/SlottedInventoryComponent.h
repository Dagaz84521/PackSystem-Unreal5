// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/InventoryComponent.h"
#include "Core/InventoryQuantityOperationResult.h"
#include "SlottedInventoryComponent.generated.h"

UENUM(BlueprintType)
enum class EInventorySlotPlacementAction : uint8
{
	PlaceInEmptySlot UMETA(DisplayName = "Place In Empty Slot"),
	StackOnExistingItem UMETA(DisplayName = "Stack On Existing Item"),
	ReplaceExistingItem UMETA(DisplayName = "Replace Existing Item"),
	NoAction UMETA(DisplayName = "No Action")
};

/**
 * 
 */
UCLASS()
class PACKSYSTEMPLUGIN_API USlottedInventoryComponent : public UInventoryComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Inventory|Slotted")
	int32 GetSlotCount() const;

	UFUNCTION(BlueprintPure, Category = "Inventory|Slotted")
	FInventoryEntryHandle GetSlotHandle(int32 SlotIndex) const;

	UFUNCTION(BlueprintPure, Category = "Inventory|Slotted")
	FInventoryQuantityOperationResult PlacePayloadInSlot(int32 SlotIndex, const FInventoryItemPayload& Payload);
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Slotted")
	int32 SlotCount;
	
};
