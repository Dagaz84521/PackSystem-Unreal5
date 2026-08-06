#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryAddRequest.h"
#include "InventoryEntryArray.h"
#include "InventoryOperationTypes.h"
#include "InventoryComponent.generated.h"

class UInventoryItemDefinition;
class UInventoryItemInstance;
class UInventoryStorageStrategy;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryChangedSignature, const FInventoryChangeSet&, ChangeSet);

UCLASS(BlueprintType, Blueprintable, ClassGroup = (Inventory), meta = (BlueprintSpawnableComponent))
class PACKSYSTEMPLUGIN_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool InitializeInventory();

	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool IsInventoryInitialized() const { return bInitialized; }

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult AddItem(const FInventoryAddRequest& Request);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult RemoveMatchingItem(UInventoryItemInstance* ItemInstance, int64 Quantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult RemoveFromEntry(FInventoryEntryHandle EntryHandle, int64 Quantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult MoveItem(FInventoryEntryHandle SourceEntry, FInventoryEntryHandle TargetEntry, int64 Quantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult SwapEntries(FInventoryEntryHandle FirstEntry, FInventoryEntryHandle SecondEntry);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult TransferItem(
		UInventoryComponent* TargetInventory,
		FInventoryEntryHandle SourceEntry,
		int64 Quantity,
		FInventoryEntryHandle TargetEntry);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult ClearInventory();

	UFUNCTION(BlueprintPure, Category = "Inventory")
	TArray<FInventoryEntryHandle> GetAllEntryHandles() const;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool GetEntry(FInventoryEntryHandle EntryHandle, FInventoryEntry& OutEntry) const;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool IsValidEntryHandle(FInventoryEntryHandle EntryHandle) const;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	int64 GetQuantityForItem(const UInventoryItemInstance* ItemInstance) const;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	int64 GetQuantityForDefinition(const UInventoryItemDefinition* ItemDefinition) const;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool ContainsItem(const UInventoryItemInstance* ItemInstance, int64 Quantity = 1) const;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	UInventoryStorageStrategy* GetStorageStrategy() const { return StorageStrategy; }

	/** C++ setup hook; only succeeds before initialization. */
	bool SetStorageStrategy(UInventoryStorageStrategy* InStorageStrategy);

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FInventoryChangedSignature OnInventoryChanged;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category = "Inventory", meta = (AllowPrivateAccess = true))
	TObjectPtr<UInventoryStorageStrategy> StorageStrategy;

	UPROPERTY(VisibleInstanceOnly, Category = "Inventory")
	FInventoryEntryArray EntryArray;

	UPROPERTY(Transient)
	bool bInitialized = false;

	UPROPERTY(Transient)
	int32 NextEntryID = 0;

	int32 FindEntryIndex(const FInventoryEntryHandle& EntryHandle, const TArray<FInventoryEntry>& Entries) const;
	int32 AllocateEntryID(const TArray<FInventoryEntry>& Entries, int32& InOutNextEntryID) const;
	FInventoryOperationResult ExecutePlan(const FInventoryOperationPlan& Plan);
	bool ValidatePlan(const FInventoryOperationPlan& Plan) const;
	bool ApplyPlan(
		const FInventoryOperationPlan& Plan,
		TArray<FInventoryEntry>& InOutEntries,
		int32& InOutNextEntryID,
		FInventoryChangeSet& OutChangeSet);
	FInventoryOperationResult MakeResult(const FInventoryOperationPlan& Plan) const;
	FInventoryOperationResult MakeFailure(int64 RequestedQuantity, FGameplayTag FailureReason) const;
	void CommitEntries(TArray<FInventoryEntry>&& NewEntries, int32 NewNextEntryID, const FInventoryChangeSet& ChangeSet, bool bBroadcast = true);
};
