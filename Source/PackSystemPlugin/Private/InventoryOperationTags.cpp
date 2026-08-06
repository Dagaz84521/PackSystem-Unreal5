#include "InventoryOperationTags.h"

namespace InventoryOperationTags
{
	UE_DEFINE_GAMEPLAY_TAG(InvalidItem, "Inventory.Error.InvalidItem");
	UE_DEFINE_GAMEPLAY_TAG(InvalidQuantity, "Inventory.Error.InvalidQuantity");
	UE_DEFINE_GAMEPLAY_TAG(InvalidHandle, "Inventory.Error.InvalidHandle");
	UE_DEFINE_GAMEPLAY_TAG(ForeignHandle, "Inventory.Error.ForeignHandle");
	UE_DEFINE_GAMEPLAY_TAG(IncompatibleItem, "Inventory.Error.IncompatibleItem");
	UE_DEFINE_GAMEPLAY_TAG(InsufficientQuantity, "Inventory.Error.InsufficientQuantity");
	UE_DEFINE_GAMEPLAY_TAG(NoCapacity, "Inventory.Error.NoCapacity");
	UE_DEFINE_GAMEPLAY_TAG(Overflow, "Inventory.Error.Overflow");
	UE_DEFINE_GAMEPLAY_TAG(StalePlan, "Inventory.Error.StalePlan");
	UE_DEFINE_GAMEPLAY_TAG(MissingStrategy, "Inventory.Error.MissingStrategy");
	UE_DEFINE_GAMEPLAY_TAG(UnsupportedOperation, "Inventory.Error.UnsupportedOperation");
	UE_DEFINE_GAMEPLAY_TAG(NoChange, "Inventory.Error.NoChange");
}
