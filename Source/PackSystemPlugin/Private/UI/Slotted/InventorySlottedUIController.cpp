#include "UI/Slotted/InventorySlottedUIController.h"

#include "Interaction/InventoryInteractionContext.h"
#include "Inventory/Slotted/SlottedInventoryComponent.h"

void UInventorySlottedUIController::Initialize(USlottedInventoryComponent* InInventory, UInventorySlottedUIWidget* InWidget)
{
	Shutdown();
	if (!BindInventory(InInventory))
	{
		return;
	}
	View = InWidget;
	EnsureInteractionContext();
}

void UInventorySlottedUIController::Shutdown()
{
	Super::Shutdown();
}

USlottedInventoryComponent* UInventorySlottedUIController::GetSlottedInventory() const
{
	return Cast<USlottedInventoryComponent>(GetInventory());
}

UInventoryInteractionContext* UInventorySlottedUIController::GetInteractionContext() const
{
	return InteractionContext;
}

void UInventorySlottedUIController::EnsureInteractionContext()
{
	if (!IsValid(InteractionContext))
	{
		InteractionContext = NewObject<UInventoryInteractionContext>(this);
	}
}
