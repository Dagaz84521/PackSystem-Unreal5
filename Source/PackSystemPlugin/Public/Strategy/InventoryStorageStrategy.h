#pragma once

#include "CoreMinimal.h"
#include "InventoryAddPlan.h"
#include "InventoryAddRequest.h"
#include "InventoryComponent.h"
#include "UObject/Object.h"
#include "InventoryStorageStrategy.generated.h"

class UInventoryItemDefinition;
class UInventoryItemInstance;

UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class PACKSYSTEMPLUGIN_API UInventoryStorageStrategy : public UObject
{
	GENERATED_BODY()
public:
	UInventoryStorageStrategy() = default;
	
	virtual FInventoryAddPlan BuildAddPlan(
		const UInventoryComponent& Inventory,
		const FInventoryAddRequest& Request) const
		PURE_VIRTUAL(UInventoryStorageStrategy::BuildAddPlan, return {};);
};
