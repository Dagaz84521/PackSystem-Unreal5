#include "InventoryComponent.h"

#include "InventoryBlueprintLibrary.h"
#include "InventoryOperationTags.h"
#include "Item/InventoryItemDefinition.h"
#include "Item/InventoryItemInstance.h"
#include "Strategy/InventoryStorageStrategy.h"
#include "Strategy/SlottedStorageStrategy.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	StorageStrategy = CreateDefaultSubobject<USlottedStorageStrategy>(TEXT("StorageStrategy"));
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	InitializeInventory();
}

bool UInventoryComponent::SetStorageStrategy(UInventoryStorageStrategy* InStorageStrategy)
{
	if (bInitialized || !IsValid(InStorageStrategy))
	{
		return false;
	}

	StorageStrategy = InStorageStrategy->GetOuter() == this
		? InStorageStrategy
		: DuplicateObject<UInventoryStorageStrategy>(InStorageStrategy, this);
	return IsValid(StorageStrategy);
}

bool UInventoryComponent::InitializeInventory()
{
	if (bInitialized)
	{
		return true;
	}
	if (!IsValid(StorageStrategy))
	{
		return false;
	}

	EntryArray.InventoryComponent = this;
	TSet<int32> UsedIDs;
	NextEntryID = 0;
	for (FInventoryEntry& Entry : EntryArray.ItemEntries)
	{
		Entry.Owner = this;
		if (Entry.EntryID == INDEX_NONE || UsedIDs.Contains(Entry.EntryID))
		{
			while (NextEntryID == INDEX_NONE || UsedIDs.Contains(NextEntryID))
			{
				++NextEntryID;
			}
			Entry.EntryID = NextEntryID++;
		}
		UsedIDs.Add(Entry.EntryID);
		if (Entry.EntryID >= NextEntryID && Entry.EntryID < MAX_int32)
		{
			NextEntryID = Entry.EntryID + 1;
		}
	}

	const int32 RequiredEntries = FMath::Max(0, StorageStrategy->GetInitialEntryCount());
	while (EntryArray.ItemEntries.Num() < RequiredEntries)
	{
		const int32 EntryID = AllocateEntryID(EntryArray.ItemEntries, NextEntryID);
		if (EntryID == INDEX_NONE)
		{
			return false;
		}
		FInventoryEntry& NewEntry = EntryArray.ItemEntries.Emplace_GetRef(nullptr, EntryID, 0);
		NewEntry.Owner = this;
	}

	bInitialized = true;
	return true;
}

TArray<FInventoryEntryHandle> UInventoryComponent::GetAllEntryHandles() const
{
	TArray<FInventoryEntryHandle> Handles;
	Handles.Reserve(EntryArray.ItemEntries.Num());
	for (const FInventoryEntry& Entry : EntryArray.ItemEntries)
	{
		Handles.Emplace(Entry.EntryID, const_cast<UInventoryComponent*>(this));
	}
	return Handles;
}

bool UInventoryComponent::GetEntry(FInventoryEntryHandle EntryHandle, FInventoryEntry& OutEntry) const
{
	const int32 Index = FindEntryIndex(EntryHandle, EntryArray.ItemEntries);
	if (Index == INDEX_NONE)
	{
		return false;
	}
	OutEntry = EntryArray.ItemEntries[Index];
	return true;
}

bool UInventoryComponent::IsValidEntryHandle(FInventoryEntryHandle EntryHandle) const
{
	return FindEntryIndex(EntryHandle, EntryArray.ItemEntries) != INDEX_NONE;
}

int64 UInventoryComponent::GetQuantityForItem(const UInventoryItemInstance* ItemInstance) const
{
	if (!IsValid(ItemInstance))
	{
		return 0;
	}

	int64 Total = 0;
	for (const FInventoryEntry& Entry : EntryArray.ItemEntries)
	{
		if (!UInventoryBlueprintLibrary::CanStackItems(Entry.ItemInstance, ItemInstance))
		{
			continue;
		}
		if (Entry.Quantity > MAX_int64 - Total)
		{
			return MAX_int64;
		}
		Total += Entry.Quantity;
	}
	return Total;
}

int64 UInventoryComponent::GetQuantityForDefinition(const UInventoryItemDefinition* ItemDefinition) const
{
	if (!IsValid(ItemDefinition))
	{
		return 0;
	}

	int64 Total = 0;
	for (const FInventoryEntry& Entry : EntryArray.ItemEntries)
	{
		if (!IsValid(Entry.ItemInstance) || Entry.ItemInstance->GetItemDefinition() != ItemDefinition)
		{
			continue;
		}
		if (Entry.Quantity > MAX_int64 - Total)
		{
			return MAX_int64;
		}
		Total += Entry.Quantity;
	}
	return Total;
}

bool UInventoryComponent::ContainsItem(const UInventoryItemInstance* ItemInstance, const int64 Quantity) const
{
	return Quantity > 0 && GetQuantityForItem(ItemInstance) >= Quantity;
}

FInventoryOperationResult UInventoryComponent::AddItem(const FInventoryAddRequest& Request)
{
	if (!InitializeInventory())
	{
		return MakeFailure(Request.Quantity, InventoryOperationTags::MissingStrategy);
	}
	if (!IsValid(Request.InventoryItemInstance))
	{
		return MakeFailure(Request.Quantity, InventoryOperationTags::InvalidItem);
	}
	if (Request.Quantity <= 0)
	{
		return MakeFailure(Request.Quantity, InventoryOperationTags::InvalidQuantity);
	}
	const bool bHasTarget = Request.TargetEntry.EntryID != INDEX_NONE
		|| Request.TargetEntry.ParentInventory != nullptr;
	if (bHasTarget && Request.TargetEntry.ParentInventory != this)
	{
		return MakeFailure(Request.Quantity, InventoryOperationTags::ForeignHandle);
	}
	if (bHasTarget && !IsValidEntryHandle(Request.TargetEntry))
	{
		return MakeFailure(Request.Quantity, InventoryOperationTags::InvalidHandle);
	}

	return ExecutePlan(StorageStrategy->BuildAddPlan(*this, Request));
}

FInventoryOperationResult UInventoryComponent::RemoveMatchingItem(UInventoryItemInstance* ItemInstance, const int64 Quantity)
{
	if (!InitializeInventory())
	{
		return MakeFailure(Quantity, InventoryOperationTags::MissingStrategy);
	}
	if (!IsValid(ItemInstance))
	{
		return MakeFailure(Quantity, InventoryOperationTags::InvalidItem);
	}
	if (Quantity <= 0)
	{
		return MakeFailure(Quantity, InventoryOperationTags::InvalidQuantity);
	}
	return ExecutePlan(StorageStrategy->BuildRemoveMatchingPlan(*this, ItemInstance, Quantity));
}

FInventoryOperationResult UInventoryComponent::RemoveFromEntry(FInventoryEntryHandle EntryHandle, const int64 Quantity)
{
	if (!InitializeInventory())
	{
		return MakeFailure(Quantity, InventoryOperationTags::MissingStrategy);
	}
	if (Quantity <= 0)
	{
		return MakeFailure(Quantity, InventoryOperationTags::InvalidQuantity);
	}
	if (EntryHandle.ParentInventory != this)
	{
		return MakeFailure(Quantity, InventoryOperationTags::ForeignHandle);
	}
	if (!IsValidEntryHandle(EntryHandle))
	{
		return MakeFailure(Quantity, InventoryOperationTags::InvalidHandle);
	}
	return ExecutePlan(StorageStrategy->BuildRemoveFromEntryPlan(*this, EntryHandle, Quantity));
}

FInventoryOperationResult UInventoryComponent::MoveItem(
	FInventoryEntryHandle SourceEntry,
	FInventoryEntryHandle TargetEntry,
	const int64 Quantity)
{
	if (!InitializeInventory())
	{
		return MakeFailure(Quantity, InventoryOperationTags::MissingStrategy);
	}
	if (Quantity <= 0)
	{
		return MakeFailure(Quantity, InventoryOperationTags::InvalidQuantity);
	}
	if (SourceEntry.ParentInventory != this || TargetEntry.ParentInventory != this)
	{
		return MakeFailure(Quantity, InventoryOperationTags::ForeignHandle);
	}
	if (!IsValidEntryHandle(SourceEntry) || !IsValidEntryHandle(TargetEntry))
	{
		return MakeFailure(Quantity, InventoryOperationTags::InvalidHandle);
	}
	return ExecutePlan(StorageStrategy->BuildMovePlan(*this, SourceEntry, TargetEntry, Quantity));
}

FInventoryOperationResult UInventoryComponent::SwapEntries(
	FInventoryEntryHandle FirstEntry,
	FInventoryEntryHandle SecondEntry)
{
	if (!InitializeInventory())
	{
		return MakeFailure(1, InventoryOperationTags::MissingStrategy);
	}
	if (FirstEntry.ParentInventory != this || SecondEntry.ParentInventory != this)
	{
		return MakeFailure(1, InventoryOperationTags::ForeignHandle);
	}
	if (!IsValidEntryHandle(FirstEntry) || !IsValidEntryHandle(SecondEntry))
	{
		return MakeFailure(1, InventoryOperationTags::InvalidHandle);
	}
	return ExecutePlan(StorageStrategy->BuildSwapPlan(*this, FirstEntry, SecondEntry));
}

FInventoryOperationResult UInventoryComponent::ClearInventory()
{
	if (!InitializeInventory())
	{
		return MakeFailure(0, InventoryOperationTags::MissingStrategy);
	}

	const FInventoryOperationPlan Plan = StorageStrategy->BuildClearPlan(*this);
	if (Plan.Mutations.IsEmpty() && !Plan.FailureReason.IsValid())
	{
		FInventoryOperationResult Result;
		Result.Status = EInventoryOperationStatus::Succeeded;
		return Result;
	}
	return ExecutePlan(Plan);
}

FInventoryOperationResult UInventoryComponent::TransferItem(
	UInventoryComponent* TargetInventory,
	FInventoryEntryHandle SourceEntry,
	const int64 Quantity,
	FInventoryEntryHandle TargetEntry)
{
	if (!IsValid(TargetInventory))
	{
		return MakeFailure(Quantity, InventoryOperationTags::InvalidHandle);
	}
	if (Quantity <= 0)
	{
		return MakeFailure(Quantity, InventoryOperationTags::InvalidQuantity);
	}
	if (!InitializeInventory() || !TargetInventory->InitializeInventory())
	{
		return MakeFailure(Quantity, InventoryOperationTags::MissingStrategy);
	}
	if (SourceEntry.ParentInventory != this || !IsValidEntryHandle(SourceEntry))
	{
		return MakeFailure(Quantity, SourceEntry.ParentInventory == this
			? InventoryOperationTags::InvalidHandle
			: InventoryOperationTags::ForeignHandle);
	}

	if (TargetInventory == this)
	{
		if (!TargetEntry.IsValid())
		{
			return MakeFailure(Quantity, InventoryOperationTags::InvalidHandle);
		}
		return MoveItem(SourceEntry, TargetEntry, Quantity);
	}

	const bool bHasTarget = TargetEntry.EntryID != INDEX_NONE || TargetEntry.ParentInventory != nullptr;
	if (bHasTarget && TargetEntry.ParentInventory != TargetInventory)
	{
		return MakeFailure(Quantity, InventoryOperationTags::ForeignHandle);
	}
	if (bHasTarget && !TargetInventory->IsValidEntryHandle(TargetEntry))
	{
		return MakeFailure(Quantity, InventoryOperationTags::InvalidHandle);
	}

	FInventoryEntry Source;
	if (!GetEntry(SourceEntry, Source) || Source.IsEmpty())
	{
		return MakeFailure(Quantity, InventoryOperationTags::InvalidItem);
	}

	const int64 AvailableQuantity = FMath::Min(Quantity, Source.Quantity);
	FInventoryAddRequest AddRequest;
	AddRequest.InventoryItemInstance = Source.ItemInstance;
	AddRequest.Quantity = AvailableQuantity;
	AddRequest.TargetEntry = TargetEntry;
	const FInventoryOperationPlan TargetPlan = TargetInventory->StorageStrategy->BuildAddPlan(*TargetInventory, AddRequest);
	if (TargetPlan.PlannedQuantity <= 0 || !TargetInventory->ValidatePlan(TargetPlan))
	{
		return MakeFailure(Quantity, TargetPlan.FailureReason.IsValid()
			? TargetPlan.FailureReason
			: InventoryOperationTags::NoCapacity);
	}

	const int64 TransferQuantity = FMath::Min(AvailableQuantity, TargetPlan.PlannedQuantity);
	const FInventoryOperationPlan SourcePlan = StorageStrategy->BuildRemoveFromEntryPlan(*this, SourceEntry, TransferQuantity);
	if (SourcePlan.PlannedQuantity != TransferQuantity || !ValidatePlan(SourcePlan))
	{
		return MakeFailure(Quantity, InventoryOperationTags::StalePlan);
	}

	TArray<FInventoryEntry> TargetEntries = TargetInventory->EntryArray.ItemEntries;
	TArray<FInventoryEntry> SourceEntries = EntryArray.ItemEntries;
	int32 TargetNextID = TargetInventory->NextEntryID;
	int32 SourceNextID = NextEntryID;
	FInventoryChangeSet TargetChanges;
	FInventoryChangeSet SourceChanges;
	if (!TargetInventory->ApplyPlan(TargetPlan, TargetEntries, TargetNextID, TargetChanges)
		|| !ApplyPlan(SourcePlan, SourceEntries, SourceNextID, SourceChanges))
	{
		return MakeFailure(Quantity, InventoryOperationTags::StalePlan);
	}

	TargetInventory->CommitEntries(MoveTemp(TargetEntries), TargetNextID, TargetChanges, false);
	CommitEntries(MoveTemp(SourceEntries), SourceNextID, SourceChanges, false);
	if (!TargetChanges.Changes.IsEmpty())
	{
		TargetInventory->OnInventoryChanged.Broadcast(TargetChanges);
	}
	if (!SourceChanges.Changes.IsEmpty())
	{
		OnInventoryChanged.Broadcast(SourceChanges);
	}

	FInventoryOperationResult Result;
	Result.RequestedQuantity = Quantity;
	Result.ProcessedQuantity = TransferQuantity;
	Result.RemainingQuantity = Quantity - TransferQuantity;
	Result.Status = Result.RemainingQuantity > 0
		? EInventoryOperationStatus::PartialSucceeded
		: EInventoryOperationStatus::Succeeded;
	if (Result.RemainingQuantity > 0)
	{
		Result.FailureReason = TransferQuantity < AvailableQuantity
			? TargetPlan.FailureReason
			: InventoryOperationTags::InsufficientQuantity;
	}
	return Result;
}

int32 UInventoryComponent::FindEntryIndex(
	const FInventoryEntryHandle& EntryHandle,
	const TArray<FInventoryEntry>& Entries) const
{
	if (EntryHandle.ParentInventory != this || EntryHandle.EntryID == INDEX_NONE)
	{
		return INDEX_NONE;
	}
	return Entries.IndexOfByPredicate([&EntryHandle](const FInventoryEntry& Entry)
	{
		return Entry.EntryID == EntryHandle.EntryID;
	});
}

int32 UInventoryComponent::AllocateEntryID(const TArray<FInventoryEntry>& Entries, int32& InOutNextEntryID) const
{
	if (InOutNextEntryID < 0)
	{
		InOutNextEntryID = 0;
	}

	for (int32 Attempt = 0; Attempt <= Entries.Num(); ++Attempt)
	{
		const int32 Candidate = InOutNextEntryID;
		InOutNextEntryID = Candidate == MAX_int32 ? 0 : Candidate + 1;
		if (Candidate == INDEX_NONE)
		{
			continue;
		}
		const bool bAlreadyUsed = Entries.ContainsByPredicate([Candidate](const FInventoryEntry& Entry)
		{
			return Entry.EntryID == Candidate;
		});
		if (!bAlreadyUsed)
		{
			return Candidate;
		}
	}
	return INDEX_NONE;
}

bool UInventoryComponent::ValidatePlan(const FInventoryOperationPlan& Plan) const
{
	if (Plan.RequestedQuantity < 0 || Plan.PlannedQuantity < 0 || Plan.RemainingQuantity < 0
		|| Plan.PlannedQuantity > Plan.RequestedQuantity
		|| Plan.RemainingQuantity != Plan.RequestedQuantity - Plan.PlannedQuantity)
	{
		return false;
	}
	if (Plan.PlannedQuantity > 0 && Plan.Mutations.IsEmpty())
	{
		return false;
	}

	TSet<int32> MutatedEntryIDs;
	for (const FInventoryEntryMutation& Mutation : Plan.Mutations)
	{
		if (Mutation.Type == EInventoryEntryMutationType::Create)
		{
			if (Mutation.TargetEntry.IsValid() || !Mutation.DesiredState.HasValidState())
			{
				return false;
			}
			continue;
		}

		if (Mutation.TargetEntry.ParentInventory != this
			|| MutatedEntryIDs.Contains(Mutation.TargetEntry.EntryID))
		{
			return false;
		}
		const int32 Index = FindEntryIndex(Mutation.TargetEntry, EntryArray.ItemEntries);
		if (Index == INDEX_NONE)
		{
			return false;
		}
		const FInventoryEntry& Current = EntryArray.ItemEntries[Index];
		if (!Current.HasValidState())
		{
			return false;
		}
		if (FInventoryEntryState(Current.ItemInstance, Current.Quantity) != Mutation.ExpectedState)
		{
			return false;
		}
		if (Mutation.Type == EInventoryEntryMutationType::Update && !Mutation.DesiredState.HasValidState())
		{
			return false;
		}
		MutatedEntryIDs.Add(Mutation.TargetEntry.EntryID);
	}
	return true;
}

bool UInventoryComponent::ApplyPlan(
	const FInventoryOperationPlan& Plan,
	TArray<FInventoryEntry>& InOutEntries,
	int32& InOutNextEntryID,
	FInventoryChangeSet& OutChangeSet)
{
	for (const FInventoryEntryMutation& Mutation : Plan.Mutations)
	{
		if (Mutation.Type == EInventoryEntryMutationType::Create)
		{
			const int32 NewEntryID = AllocateEntryID(InOutEntries, InOutNextEntryID);
			if (NewEntryID == INDEX_NONE)
			{
				return false;
			}
			UInventoryItemInstance* DesiredItem = Mutation.DesiredState.ItemInstance;
			if (Mutation.bDuplicateItemInstance && IsValid(DesiredItem))
			{
				DesiredItem = DuplicateObject<UInventoryItemInstance>(DesiredItem, this);
				if (!IsValid(DesiredItem))
				{
					return false;
				}
			}
			FInventoryEntry& NewEntry = InOutEntries.Emplace_GetRef(DesiredItem, NewEntryID, Mutation.DesiredState.Quantity);
			NewEntry.Owner = this;

			FInventoryEntryChange& Change = OutChangeSet.Changes.Emplace_GetRef();
			Change.EntryHandle = FInventoryEntryHandle(NewEntryID, this);
			Change.After = FInventoryEntryState(NewEntry.ItemInstance, NewEntry.Quantity);
			Change.bEntryCreated = true;
			continue;
		}

		const int32 Index = FindEntryIndex(Mutation.TargetEntry, InOutEntries);
		if (Index == INDEX_NONE)
		{
			return false;
		}
		FInventoryEntry& Entry = InOutEntries[Index];
		FInventoryEntryChange Change;
		Change.EntryHandle = Mutation.TargetEntry;
		Change.Before = FInventoryEntryState(Entry.ItemInstance, Entry.Quantity);

		if (Mutation.Type == EInventoryEntryMutationType::Delete)
		{
			Change.bEntryDeleted = true;
			InOutEntries.RemoveAt(Index);
			OutChangeSet.Changes.Add(MoveTemp(Change));
			continue;
		}

		UInventoryItemInstance* DesiredItem = Mutation.DesiredState.ItemInstance;
		if (Mutation.bDuplicateItemInstance && IsValid(DesiredItem))
		{
			DesiredItem = DuplicateObject<UInventoryItemInstance>(DesiredItem, this);
			if (!IsValid(DesiredItem))
			{
				return false;
			}
		}
		Entry.ItemInstance = DesiredItem;
		Entry.Quantity = Mutation.DesiredState.Quantity;
		Change.After = FInventoryEntryState(Entry.ItemInstance, Entry.Quantity);
		OutChangeSet.Changes.Add(MoveTemp(Change));
	}
	return true;
}

FInventoryOperationResult UInventoryComponent::ExecutePlan(const FInventoryOperationPlan& Plan)
{
	if (Plan.Mutations.IsEmpty())
	{
		return MakeFailure(Plan.RequestedQuantity, Plan.FailureReason.IsValid()
			? Plan.FailureReason
			: InventoryOperationTags::NoChange);
	}
	if (!ValidatePlan(Plan))
	{
		return MakeFailure(Plan.RequestedQuantity, InventoryOperationTags::StalePlan);
	}

	TArray<FInventoryEntry> WorkingEntries = EntryArray.ItemEntries;
	int32 WorkingNextID = NextEntryID;
	FInventoryChangeSet ChangeSet;
	if (!ApplyPlan(Plan, WorkingEntries, WorkingNextID, ChangeSet))
	{
		return MakeFailure(Plan.RequestedQuantity, InventoryOperationTags::StalePlan);
	}

	CommitEntries(MoveTemp(WorkingEntries), WorkingNextID, ChangeSet);
	return MakeResult(Plan);
}

FInventoryOperationResult UInventoryComponent::MakeResult(const FInventoryOperationPlan& Plan) const
{
	FInventoryOperationResult Result;
	Result.RequestedQuantity = Plan.RequestedQuantity;
	Result.ProcessedQuantity = Plan.PlannedQuantity;
	Result.RemainingQuantity = Plan.RemainingQuantity;
	Result.FailureReason = Plan.FailureReason;
	if (Plan.PlannedQuantity <= 0)
	{
		Result.Status = EInventoryOperationStatus::Failed;
	}
	else if (Plan.RemainingQuantity > 0)
	{
		Result.Status = EInventoryOperationStatus::PartialSucceeded;
	}
	else
	{
		Result.Status = EInventoryOperationStatus::Succeeded;
		Result.FailureReason = FGameplayTag();
	}
	return Result;
}

FInventoryOperationResult UInventoryComponent::MakeFailure(
	const int64 RequestedQuantity,
	const FGameplayTag FailureReason) const
{
	FInventoryOperationResult Result;
	Result.RequestedQuantity = FMath::Max<int64>(0, RequestedQuantity);
	Result.RemainingQuantity = Result.RequestedQuantity;
	Result.FailureReason = FailureReason;
	return Result;
}

void UInventoryComponent::CommitEntries(
	TArray<FInventoryEntry>&& NewEntries,
	const int32 NewNextEntryID,
	const FInventoryChangeSet& ChangeSet,
	const bool bBroadcast)
{
	EntryArray.ItemEntries = MoveTemp(NewEntries);
	NextEntryID = NewNextEntryID;
	for (FInventoryEntry& Entry : EntryArray.ItemEntries)
	{
		Entry.Owner = this;
	}
	if (bBroadcast && !ChangeSet.Changes.IsEmpty())
	{
		OnInventoryChanged.Broadcast(ChangeSet);
	}
}
