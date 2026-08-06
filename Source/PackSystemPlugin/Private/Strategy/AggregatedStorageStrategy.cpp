#include "Strategy/AggregatedStorageStrategy.h"

#include "InventoryBlueprintLibrary.h"
#include "InventoryComponent.h"
#include "InventoryOperationTags.h"

namespace
{
	FInventoryOperationPlan MakeFailedPlan(const int64 RequestedQuantity, const FGameplayTag Reason)
	{
		FInventoryOperationPlan Plan;
		Plan.RequestedQuantity = FMath::Max<int64>(0, RequestedQuantity);
		Plan.RemainingQuantity = Plan.RequestedQuantity;
		Plan.FailureReason = Reason;
		return Plan;
	}

	FInventoryEntryMutation MakeUpdateMutation(
		const FInventoryEntryHandle& Handle,
		const FInventoryEntry& Entry,
		const FInventoryEntryState& DesiredState)
	{
		FInventoryEntryMutation Mutation;
		Mutation.Type = EInventoryEntryMutationType::Update;
		Mutation.TargetEntry = Handle;
		Mutation.ExpectedState = FInventoryEntryState(Entry.ItemInstance, Entry.Quantity);
		Mutation.DesiredState = DesiredState;
		return Mutation;
	}

	FInventoryEntryMutation MakeDeleteMutation(
		const FInventoryEntryHandle& Handle,
		const FInventoryEntry& Entry)
	{
		FInventoryEntryMutation Mutation;
		Mutation.Type = EInventoryEntryMutationType::Delete;
		Mutation.TargetEntry = Handle;
		Mutation.ExpectedState = FInventoryEntryState(Entry.ItemInstance, Entry.Quantity);
		return Mutation;
	}
}

FInventoryOperationPlan UAggregatedStorageStrategy::BuildAddPlan(
	const UInventoryComponent& Inventory,
	const FInventoryAddRequest& Request) const
{
	if (!IsValid(Request.InventoryItemInstance))
	{
		return MakeFailedPlan(Request.Quantity, InventoryOperationTags::InvalidItem);
	}
	if (Request.Quantity <= 0)
	{
		return MakeFailedPlan(Request.Quantity, InventoryOperationTags::InvalidQuantity);
	}

	FInventoryEntryHandle StackHandle;
	FInventoryEntry StackEntry;
	if (Request.TargetEntry.IsValid())
	{
		if (!Inventory.GetEntry(Request.TargetEntry, StackEntry))
		{
			return MakeFailedPlan(Request.Quantity, InventoryOperationTags::InvalidHandle);
		}
		if (!UInventoryBlueprintLibrary::CanStackItems(StackEntry.ItemInstance, Request.InventoryItemInstance))
		{
			return MakeFailedPlan(Request.Quantity, InventoryOperationTags::IncompatibleItem);
		}
		StackHandle = Request.TargetEntry;
	}
	else
	{
		for (const FInventoryEntryHandle& Handle : Inventory.GetAllEntryHandles())
		{
			FInventoryEntry Entry;
			if (Inventory.GetEntry(Handle, Entry)
				&& UInventoryBlueprintLibrary::CanStackItems(Entry.ItemInstance, Request.InventoryItemInstance))
			{
				StackHandle = Handle;
				StackEntry = Entry;
				break;
			}
		}
	}

	FInventoryOperationPlan Plan;
	Plan.RequestedQuantity = Request.Quantity;
	if (StackHandle.IsValid())
	{
		const int64 Capacity = MAX_int64 - StackEntry.Quantity;
		Plan.PlannedQuantity = FMath::Min(Request.Quantity, Capacity);
		Plan.RemainingQuantity = Request.Quantity - Plan.PlannedQuantity;
		if (Plan.PlannedQuantity <= 0)
		{
			Plan.FailureReason = InventoryOperationTags::Overflow;
			return Plan;
		}

		Plan.Mutations.Add(MakeUpdateMutation(
			StackHandle,
			StackEntry,
			FInventoryEntryState(StackEntry.ItemInstance, StackEntry.Quantity + Plan.PlannedQuantity)));
		if (Plan.RemainingQuantity > 0)
		{
			Plan.FailureReason = InventoryOperationTags::Overflow;
		}
		return Plan;
	}

	Plan.PlannedQuantity = Request.Quantity;
	FInventoryEntryMutation Mutation;
	Mutation.Type = EInventoryEntryMutationType::Create;
	Mutation.DesiredState = FInventoryEntryState(Request.InventoryItemInstance, Request.Quantity);
	Mutation.bDuplicateItemInstance = true;
	Plan.Mutations.Add(Mutation);
	return Plan;
}

FInventoryOperationPlan UAggregatedStorageStrategy::BuildRemoveMatchingPlan(
	const UInventoryComponent& Inventory,
	const UInventoryItemInstance* ItemInstance,
	const int64 Quantity) const
{
	if (!IsValid(ItemInstance))
	{
		return MakeFailedPlan(Quantity, InventoryOperationTags::InvalidItem);
	}

	FInventoryOperationPlan Plan;
	Plan.RequestedQuantity = Quantity;
	int64 Remaining = Quantity;
	for (const FInventoryEntryHandle& Handle : Inventory.GetAllEntryHandles())
	{
		FInventoryEntry Entry;
		if (!Inventory.GetEntry(Handle, Entry)
			|| !UInventoryBlueprintLibrary::CanStackItems(Entry.ItemInstance, ItemInstance))
		{
			continue;
		}

		const int64 Removed = FMath::Min(Remaining, Entry.Quantity);
		if (Removed == Entry.Quantity)
		{
			Plan.Mutations.Add(MakeDeleteMutation(Handle, Entry));
		}
		else
		{
			Plan.Mutations.Add(MakeUpdateMutation(
				Handle,
				Entry,
				FInventoryEntryState(Entry.ItemInstance, Entry.Quantity - Removed)));
		}
		Remaining -= Removed;
		if (Remaining == 0)
		{
			break;
		}
	}

	Plan.PlannedQuantity = Quantity - Remaining;
	Plan.RemainingQuantity = Remaining;
	if (Remaining > 0)
	{
		Plan.FailureReason = InventoryOperationTags::InsufficientQuantity;
	}
	return Plan;
}

FInventoryOperationPlan UAggregatedStorageStrategy::BuildRemoveFromEntryPlan(
	const UInventoryComponent& Inventory,
	const FInventoryEntryHandle& EntryHandle,
	const int64 Quantity) const
{
	FInventoryEntry Entry;
	if (!Inventory.GetEntry(EntryHandle, Entry))
	{
		return MakeFailedPlan(Quantity, InventoryOperationTags::InvalidHandle);
	}
	if (Entry.IsEmpty())
	{
		return MakeFailedPlan(Quantity, InventoryOperationTags::InvalidItem);
	}

	FInventoryOperationPlan Plan;
	Plan.RequestedQuantity = Quantity;
	Plan.PlannedQuantity = FMath::Min(Quantity, Entry.Quantity);
	Plan.RemainingQuantity = Quantity - Plan.PlannedQuantity;
	if (Plan.PlannedQuantity == Entry.Quantity)
	{
		Plan.Mutations.Add(MakeDeleteMutation(EntryHandle, Entry));
	}
	else
	{
		Plan.Mutations.Add(MakeUpdateMutation(
			EntryHandle,
			Entry,
			FInventoryEntryState(Entry.ItemInstance, Entry.Quantity - Plan.PlannedQuantity)));
	}
	if (Plan.RemainingQuantity > 0)
	{
		Plan.FailureReason = InventoryOperationTags::InsufficientQuantity;
	}
	return Plan;
}

FInventoryOperationPlan UAggregatedStorageStrategy::BuildMovePlan(
	const UInventoryComponent& Inventory,
	const FInventoryEntryHandle& SourceEntry,
	const FInventoryEntryHandle& TargetEntry,
	const int64 Quantity) const
{
	return MakeFailedPlan(Quantity, InventoryOperationTags::UnsupportedOperation);
}

FInventoryOperationPlan UAggregatedStorageStrategy::BuildSwapPlan(
	const UInventoryComponent& Inventory,
	const FInventoryEntryHandle& FirstEntry,
	const FInventoryEntryHandle& SecondEntry) const
{
	return MakeFailedPlan(1, InventoryOperationTags::UnsupportedOperation);
}

FInventoryOperationPlan UAggregatedStorageStrategy::BuildClearPlan(const UInventoryComponent& Inventory) const
{
	FInventoryOperationPlan Plan;
	for (const FInventoryEntryHandle& Handle : Inventory.GetAllEntryHandles())
	{
		FInventoryEntry Entry;
		if (!Inventory.GetEntry(Handle, Entry))
		{
			continue;
		}
		Plan.Mutations.Add(MakeDeleteMutation(Handle, Entry));
		if (Entry.Quantity > MAX_int64 - Plan.RequestedQuantity)
		{
			Plan.RequestedQuantity = MAX_int64;
		}
		else
		{
			Plan.RequestedQuantity += Entry.Quantity;
		}
	}
	Plan.PlannedQuantity = Plan.RequestedQuantity;
	return Plan;
}
