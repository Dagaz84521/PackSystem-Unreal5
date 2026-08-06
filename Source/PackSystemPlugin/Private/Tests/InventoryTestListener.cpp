#include "Tests/InventoryTestListener.h"

void UInventoryTestListener::HandleInventoryChanged(const FInventoryChangeSet& ChangeSet)
{
	++CallCount;
	LastChangeCount = ChangeSet.Changes.Num();
}
