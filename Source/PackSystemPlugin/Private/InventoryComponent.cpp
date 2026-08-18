#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	EntryArray.InventoryComponent = this;
}

void UInventoryComponent::OnRegister()
{
	Super::OnRegister();
	RebuildRuntimeState();
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

bool UInventoryComponent::IsValidEntryHandle(const FInventoryEntryHandle& EntryHandle) const
{
	return FindEntry(EntryHandle) != nullptr;
}

bool UInventoryComponent::GetEntry(
	const FInventoryEntryHandle& EntryHandle,
	FInventoryEntry& OutEntry) const
{
	if (const FInventoryEntry* Entry = FindEntry(EntryHandle))
	{
		OutEntry = *Entry;
		return true;
	}

	OutEntry = FInventoryEntry();
	return false;
}

const FInventoryEntry* UInventoryComponent::FindEntry(
	const FInventoryEntryHandle& EntryHandle) const
{
	if (EntryHandle.EntryID == INDEX_NONE || EntryHandle.ParentInventory != this)
	{
		return nullptr;
	}

	return EntryArray.ItemEntries.FindByPredicate(
		[&EntryHandle](const FInventoryEntry& Entry)
		{
			return Entry.EntryID == EntryHandle.EntryID;
		});
}

FInventoryEntry* UInventoryComponent::FindMutableEntry(
	const FInventoryEntryHandle& EntryHandle)
{
	if (EntryHandle.EntryID == INDEX_NONE || EntryHandle.ParentInventory != this)
	{
		return nullptr;
	}

	return EntryArray.ItemEntries.FindByPredicate(
		[&EntryHandle](const FInventoryEntry& Entry)
		{
			return Entry.EntryID == EntryHandle.EntryID;
		});
}

FInventoryEntryHandle UInventoryComponent::CreateEntry(
	const FInventoryItemPayload& Payload)
{
	if (!Payload.IsWellFormed())
	{
		return {};
	}

	const int32 EntryID = AllocateEntryID();
	if (EntryID == INDEX_NONE)
	{
		return {};
	}

	EntryArray.ItemEntries.Emplace(Payload, EntryID);
	const FInventoryEntryHandle EntryHandle = MakeEntryHandle(EntryID);

	OnEntryAdded.Broadcast(EntryHandle);
	return EntryHandle;
}

bool UInventoryComponent::RemoveEntry(const FInventoryEntryHandle& EntryHandle)
{
	if (EntryHandle.EntryID == INDEX_NONE ||
		EntryHandle.ParentInventory != this)
	{
		return false;
	}

	const int32 EntryIndex =
		EntryArray.ItemEntries.IndexOfByPredicate(
			[&EntryHandle](const FInventoryEntry& Entry)
			{
				return Entry.EntryID == EntryHandle.EntryID;
			});

	if (EntryIndex == INDEX_NONE)
	{
		return false;
	}

	EntryArray.ItemEntries.RemoveAt(EntryIndex);

	// 删除之后再通知，确保收到事件时 Model 已经是最终状态。
	OnEntryRemoved.Broadcast(EntryHandle);
	return true;
}

bool UInventoryComponent::SetEntryPayload(const FInventoryEntryHandle& EntryHandle, const FInventoryItemPayload& Payload)
{
	if (!Payload.IsWellFormed())
	{
		return false;
	}

	FInventoryEntry* Entry = FindMutableEntry(EntryHandle);
	if (Entry == nullptr)
	{
		return false;
	}

	if (Entry->Payload == Payload)
	{
		return true;
	}
	
	Entry->Payload = Payload;
	OnEntryChanged.Broadcast(EntryHandle);
	return true;
}

bool UInventoryComponent::ClearEntry(const FInventoryEntryHandle& EntryHandle)
{
	return SetEntryPayload(EntryHandle, FInventoryItemPayload());
}

FInventoryEntryHandle UInventoryComponent::MakeEntryHandle(int32 EntryID) const
{
	if (EntryID == INDEX_NONE)
	{
		return {};
	}

	return FInventoryEntryHandle(EntryID,const_cast<UInventoryComponent*>(this));
}

void UInventoryComponent::RebuildRuntimeState()
{
	EntryArray.InventoryComponent = this;

	int64 HighestEntryID = INDEX_NONE;
	for (const FInventoryEntry& Entry : EntryArray.ItemEntries)
	{
		if (Entry.EntryID != INDEX_NONE)
		{
			HighestEntryID = FMath::Max<int64>(HighestEntryID, Entry.EntryID);
		}
	}
	NextEntryID = HighestEntryID + 1;

	TSet<int32> UsedEntryIDs;
	for (FInventoryEntry& Entry : EntryArray.ItemEntries)
	{
		if (!Entry.Payload.IsWellFormed())
		{
			ensureMsgf(false, TEXT("Inventory entry %d contains a malformed payload"), Entry.EntryID);
			Entry.Payload.Reset();
		}

		if (Entry.EntryID == INDEX_NONE || UsedEntryIDs.Contains(Entry.EntryID))
		{
			Entry.EntryID = AllocateEntryID();
		}

		if (Entry.EntryID != INDEX_NONE)
		{
			UsedEntryIDs.Add(Entry.EntryID);
		}
	}
	OnInventoryReset.Broadcast();
}

int32 UInventoryComponent::AllocateEntryID()
{
	if (NextEntryID > MAX_int32)
	{
		ensureMsgf(false, TEXT("Inventory entry ID space exhausted for %s"), *GetPathName());
		return INDEX_NONE;
	}

	return static_cast<int32>(NextEntryID++);
}
