#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "Core/InventoryItemPayload.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Interaction/InventoryInteractionContext.h"
#include "Inventory/Aggregate/AggregateInventoryComponent.h"
#include "Inventory/Slotted/SlottedInventoryComponent.h"
#include "Item/InventoryItemDefinition.h"
#include "Item/InventoryItemInstance.h"
#include "UObject/UnrealType.h"

namespace
{
bool SetDefinitionMaxStackSize(UInventoryItemDefinition* Definition, const int32 MaxStackSize)
{
	FIntProperty* Property = FindFProperty<FIntProperty>(
		UInventoryItemDefinition::StaticClass(),
		TEXT("MaxStackSize"));
	if (Property == nullptr)
	{
		return false;
	}

	Property->SetPropertyValue_InContainer(Definition, MaxStackSize);
	return true;
}

bool SetSlottedInventorySlotCount(
	USlottedInventoryComponent* Inventory,
	const int32 SlotCount)
{
	FIntProperty* Property = FindFProperty<FIntProperty>(
		USlottedInventoryComponent::StaticClass(),
		TEXT("SlotCount"));
	if (Property == nullptr)
	{
		return false;
	}

	Property->SetPropertyValue_InContainer(Inventory, SlotCount);
	return true;
}

UWorld* FindInventoryTestWorld()
{
	if (GEngine == nullptr)
	{
		return nullptr;
	}

	for (const FWorldContext& Context : GEngine->GetWorldContexts())
	{
		UWorld* World = Context.World();
		if (World != nullptr &&
			(Context.WorldType == EWorldType::Editor ||
			 Context.WorldType == EWorldType::PIE ||
			 Context.WorldType == EWorldType::Game))
		{
			return World;
		}
	}

	return nullptr;
}

USlottedInventoryComponent* CreateRegisteredSlottedInventory(
	UWorld* World,
	const int32 SlotCount,
	AActor*& OutOwner)
{
	OutOwner = nullptr;
	if (World == nullptr)
	{
		return nullptr;
	}

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.ObjectFlags |= RF_Transient;
	OutOwner = World->SpawnActor<AActor>(
		AActor::StaticClass(),
		FTransform::Identity,
		SpawnParameters);
	if (OutOwner == nullptr)
	{
		return nullptr;
	}

	USlottedInventoryComponent* Inventory =
		NewObject<USlottedInventoryComponent>(OutOwner, NAME_None, RF_Transient);
	if (!SetSlottedInventorySlotCount(Inventory, SlotCount))
	{
		OutOwner->Destroy();
		OutOwner = nullptr;
		return nullptr;
	}

	OutOwner->AddInstanceComponent(Inventory);
	Inventory->RegisterComponent();
	return Inventory;
}

FInventoryEntryHandle AddTestSlot(
	USlottedInventoryComponent* Inventory,
	const FInventoryItemPayload& Payload,
	const int32 EntryID = 0)
{
	FStructProperty* Property = FindFProperty<FStructProperty>(
		UInventoryComponent::StaticClass(),
		TEXT("EntryArray"));
	if (Property == nullptr)
	{
		return {};
	}

	FInventoryEntryArray* EntryArray =
		Property->ContainerPtrToValuePtr<FInventoryEntryArray>(Inventory);
	EntryArray->InventoryComponent = Inventory;
	EntryArray->ItemEntries.Emplace(Payload, EntryID);
	return FInventoryEntryHandle(EntryID, Inventory);
}
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FStatelessInventoryPayloadSplitTest,
	"PackSystem.Inventory.Payload.StatelessSplitDoesNotCreateInstance",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FStatelessInventoryPayloadSplitTest::RunTest(const FString& Parameters)
{
	UInventoryItemDefinition* Definition = NewObject<UInventoryItemDefinition>();
	TestNotNull(TEXT("A transient definition can be created"), Definition);

	const FInventoryItemPayload OriginalPayload = Definition->CreateItemPayload(
		20,
		GetTransientPackage());
	TestTrue(TEXT("A stateless payload is valid"), OriginalPayload.IsValid());
	TestNull(TEXT("A stateless payload has no item instance"), OriginalPayload.ItemInstance.Get());

	UAggregateInventoryComponent* Inventory = NewObject<UAggregateInventoryComponent>();
	const FInventoryQuantityOperationResult AddResult = Inventory->AddItem(OriginalPayload);
	TestEqual(
		TEXT("Adding the payload succeeds"),
		AddResult.Status,
		EInventoryQuantityOperationStatus::Succeeded);

	const FInventoryQuantityOperationResult ExtractResult = Inventory->ExtractItemFromEntry(
		AddResult.AffectedEntry,
		6);
	TestEqual(
		TEXT("Extracting part of the stack succeeds"),
		ExtractResult.Status,
		EInventoryQuantityOperationStatus::Succeeded);
	TestEqual(TEXT("The extracted quantity is preserved"), ExtractResult.ChangedQuantity, int64{6});
	TestTrue(TEXT("The extracted payload is valid"), ExtractResult.OutputPayload.IsValid());
	TestEqual(
		TEXT("The extracted payload keeps the definition"),
		ExtractResult.OutputPayload.ItemDefinition.Get(),
		Definition);
	TestNull(
		TEXT("Splitting a stateless stack does not create an instance"),
		ExtractResult.OutputPayload.ItemInstance.Get());

	FInventoryEntry RemainingEntry;
	TestTrue(
		TEXT("The source entry remains after a partial extraction"),
		Inventory->GetEntry(AddResult.AffectedEntry, RemainingEntry));
	TestEqual(TEXT("The source quantity is reduced"), RemainingEntry.Payload.Quantity, int64{14});
	TestEqual(
		TEXT("The source payload keeps the definition"),
		RemainingEntry.Payload.ItemDefinition.Get(),
		Definition);
	TestNull(
		TEXT("The source payload remains stateless"),
		RemainingEntry.Payload.ItemInstance.Get());

	UInventoryItemInstance* UnexpectedInstance = NewObject<UInventoryItemInstance>();
	const FInventoryItemPayload InvalidPayload(Definition, 1, UnexpectedInstance);
	TestFalse(
		TEXT("A stateless definition rejects an unexpected instance"),
		InvalidPayload.IsValid());

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FSlottedInventoryPlaceItemTest,
	"PackSystem.Inventory.Slotted.PlaceItemAtSlot",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FSlottedInventoryPlaceItemTest::RunTest(const FString& Parameters)
{
	UInventoryItemDefinition* WoodDefinition = NewObject<UInventoryItemDefinition>();
	UInventoryItemDefinition* StoneDefinition = NewObject<UInventoryItemDefinition>();
	TestTrue(TEXT("Wood stack size can be configured"), SetDefinitionMaxStackSize(WoodDefinition, 20));
	TestTrue(TEXT("Stone stack size can be configured"), SetDefinitionMaxStackSize(StoneDefinition, 20));

	USlottedInventoryComponent* EmptyInventory = NewObject<USlottedInventoryComponent>();
	const FInventoryEntryHandle EmptySlot = AddTestSlot(EmptyInventory, {});
	const FInventoryItemPayload WoodTen = WoodDefinition->CreateItemPayload(10, GetTransientPackage());
	const FInventoryQuantityOperationResult EmptyResult =
		EmptyInventory->PlaceItemAtSlot(EmptySlot, WoodTen);
	TestEqual(TEXT("Placing in an empty slot succeeds"), EmptyResult.Status, EInventoryQuantityOperationStatus::Succeeded);
	TestTrue(TEXT("Cursor is empty after placing in an empty slot"), EmptyResult.OutputPayload.IsEmpty());
	FInventoryEntry EmptyEntryAfter;
	TestTrue(TEXT("Empty target remains addressable"), EmptyInventory->GetEntry(EmptySlot, EmptyEntryAfter));
	TestEqual(TEXT("Empty target receives the full quantity"), EmptyEntryAfter.Payload.Quantity, int64{10});

	USlottedInventoryComponent* CompleteMergeInventory = NewObject<USlottedInventoryComponent>();
	const FInventoryEntryHandle CompleteMergeSlot = AddTestSlot(
		CompleteMergeInventory,
		WoodDefinition->CreateItemPayload(15, GetTransientPackage()));
	const FInventoryQuantityOperationResult CompleteMergeResult =
		CompleteMergeInventory->PlaceItemAtSlot(
			CompleteMergeSlot,
			WoodDefinition->CreateItemPayload(5, GetTransientPackage()));
	TestEqual(TEXT("A complete merge succeeds"), CompleteMergeResult.Status, EInventoryQuantityOperationStatus::Succeeded);
	TestTrue(TEXT("Cursor is empty after a complete merge"), CompleteMergeResult.OutputPayload.IsEmpty());
	FInventoryEntry CompleteMergeEntryAfter;
	TestTrue(
		TEXT("Complete merge target remains addressable"),
		CompleteMergeInventory->GetEntry(CompleteMergeSlot, CompleteMergeEntryAfter));
	TestEqual(TEXT("Complete merge preserves all quantity"), CompleteMergeEntryAfter.Payload.Quantity, int64{20});

	USlottedInventoryComponent* MergeInventory = NewObject<USlottedInventoryComponent>();
	const FInventoryEntryHandle MergeSlot = AddTestSlot(
		MergeInventory,
		WoodDefinition->CreateItemPayload(18, GetTransientPackage()));
	const FInventoryQuantityOperationResult MergeResult = MergeInventory->PlaceItemAtSlot(
		MergeSlot,
		WoodDefinition->CreateItemPayload(5, GetTransientPackage()));
	TestEqual(TEXT("A capacity-limited merge partially succeeds"), MergeResult.Status, EInventoryQuantityOperationStatus::PartialSucceeded);
	TestEqual(TEXT("A partial merge moves only available quantity"), MergeResult.ChangedQuantity, int64{2});
	TestEqual(TEXT("Cursor keeps the unmerged quantity"), MergeResult.OutputPayload.Quantity, int64{3});
	FInventoryEntry MergeEntryAfter;
	TestTrue(TEXT("Merged target remains addressable"), MergeInventory->GetEntry(MergeSlot, MergeEntryAfter));
	TestEqual(TEXT("Merged target reaches its stack limit"), MergeEntryAfter.Payload.Quantity, int64{20});

	const FInventoryQuantityOperationResult FullResult = MergeInventory->PlaceItemAtSlot(
		MergeSlot,
		WoodDefinition->CreateItemPayload(4, GetTransientPackage()));
	TestEqual(TEXT("Merging into a full stack fails"), FullResult.Status, EInventoryQuantityOperationStatus::Failed);
	TestEqual(TEXT("Failed merge preserves the cursor"), FullResult.OutputPayload.Quantity, int64{4});
	FInventoryEntry FullEntryAfter;
	TestTrue(TEXT("Full target remains addressable"), MergeInventory->GetEntry(MergeSlot, FullEntryAfter));
	TestEqual(TEXT("Failed merge does not change the target"), FullEntryAfter.Payload.Quantity, int64{20});

	USlottedInventoryComponent* SwapInventory = NewObject<USlottedInventoryComponent>();
	const FInventoryItemPayload StoneFour = StoneDefinition->CreateItemPayload(4, GetTransientPackage());
	const FInventoryEntryHandle SwapSlot = AddTestSlot(SwapInventory, StoneFour);
	const FInventoryItemPayload WoodFive = WoodDefinition->CreateItemPayload(5, GetTransientPackage());
	const FInventoryQuantityOperationResult SwapResult =
		SwapInventory->PlaceItemAtSlot(SwapSlot, WoodFive);
	TestEqual(TEXT("Different items are swapped"), SwapResult.Status, EInventoryQuantityOperationStatus::Succeeded);
	TestTrue(TEXT("Cursor receives the previous target payload"), SwapResult.OutputPayload == StoneFour);
	FInventoryEntry SwapEntryAfter;
	TestTrue(TEXT("Swapped target remains addressable"), SwapInventory->GetEntry(SwapSlot, SwapEntryAfter));
	TestTrue(TEXT("Target receives the previous cursor payload"), SwapEntryAfter.Payload == WoodFive);

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FSlottedInventoryInitializationAndExtractTest,
	"PackSystem.Inventory.Slotted.InitializationAndExtract",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FSlottedInventoryInitializationAndExtractTest::RunTest(const FString& Parameters)
{
	UWorld* World = FindInventoryTestWorld();
	if (!TestNotNull(TEXT("An editor or game world is available"), World))
	{
		return false;
	}

	AActor* Owner = nullptr;
	USlottedInventoryComponent* Inventory =
		CreateRegisteredSlottedInventory(World, 3, Owner);
	if (!TestNotNull(TEXT("A registered slotted inventory can be created"), Inventory))
	{
		return false;
	}

	TestEqual(TEXT("Registration creates the configured number of slots"), Inventory->GetSlotCount(), 3);
	const FInventoryEntryHandle FirstSlot = Inventory->GetSlotHandle(0);
	const FInventoryEntryHandle SecondSlot = Inventory->GetSlotHandle(1);
	const FInventoryEntryHandle ThirdSlot = Inventory->GetSlotHandle(2);
	TestTrue(TEXT("First slot has a resolvable handle"), Inventory->IsValidEntryHandle(FirstSlot));
	TestTrue(TEXT("Second slot has a resolvable handle"), Inventory->IsValidEntryHandle(SecondSlot));
	TestTrue(TEXT("Third slot has a resolvable handle"), Inventory->IsValidEntryHandle(ThirdSlot));
	TestTrue(TEXT("Initialized slots are empty"), Inventory->IsSlotEmpty(FirstSlot));
	TestFalse(TEXT("Negative slot index is invalid"), Inventory->GetSlotHandle(-1).IsSet());
	TestFalse(TEXT("Index equal to slot count is invalid"), Inventory->GetSlotHandle(3).IsSet());

	Inventory->UnregisterComponent();
	Inventory->RegisterComponent();
	TestEqual(TEXT("Repeated registration does not add slots"), Inventory->GetAllEntryHandles().Num(), 3);
	TestTrue(
		TEXT("Repeated registration preserves stable slot handles"),
		Inventory->GetSlotHandle(1) == SecondSlot);

	UInventoryItemDefinition* Definition = NewObject<UInventoryItemDefinition>();
	TestTrue(TEXT("Extract test stack size can be configured"), SetDefinitionMaxStackSize(Definition, 20));
	const FInventoryItemPayload OriginalPayload =
		Definition->CreateItemPayload(10, GetTransientPackage());
	const FInventoryQuantityOperationResult PlaceResult =
		Inventory->PlaceItemAtSlot(FirstSlot, OriginalPayload);
	TestEqual(TEXT("Extract source payload can be placed"), PlaceResult.Status, EInventoryQuantityOperationStatus::Succeeded);

	const FInventoryQuantityOperationResult PartialExtractResult =
		Inventory->ExtractItemFromSlot(FirstSlot, 4);
	TestEqual(TEXT("Exact partial extraction succeeds"), PartialExtractResult.Status, EInventoryQuantityOperationStatus::Succeeded);
	TestEqual(TEXT("Partial extraction returns requested quantity"), PartialExtractResult.OutputPayload.Quantity, int64{4});
	TestEqual(TEXT("Partial extraction reports changed quantity"), PartialExtractResult.ChangedQuantity, int64{4});
	FInventoryEntry EntryAfterExtract;
	TestTrue(TEXT("Partially extracted slot remains addressable"), Inventory->GetEntry(FirstSlot, EntryAfterExtract));
	TestEqual(TEXT("Partial extraction leaves the remainder"), EntryAfterExtract.Payload.Quantity, int64{6});

	const FInventoryQuantityOperationResult ExcessExtractResult =
		Inventory->ExtractItemFromSlot(FirstSlot, 7);
	TestEqual(TEXT("Extraction larger than source fails"), ExcessExtractResult.Status, EInventoryQuantityOperationStatus::Failed);
	TestTrue(TEXT("Excess extraction returns no payload"), ExcessExtractResult.OutputPayload.IsEmpty());
	TestTrue(TEXT("Slot remains addressable after failed extraction"), Inventory->GetEntry(FirstSlot, EntryAfterExtract));
	TestEqual(TEXT("Failed extraction does not change quantity"), EntryAfterExtract.Payload.Quantity, int64{6});

	const FInventoryQuantityOperationResult FullExtractResult =
		Inventory->ExtractItemFromSlot(FirstSlot, 6);
	TestEqual(TEXT("Full extraction succeeds"), FullExtractResult.Status, EInventoryQuantityOperationStatus::Succeeded);
	TestEqual(TEXT("Full extraction returns all remaining items"), FullExtractResult.OutputPayload.Quantity, int64{6});
	TestTrue(TEXT("Full extraction clears the slot"), Inventory->IsSlotEmpty(FirstSlot));
	TestTrue(TEXT("Cleared slot handle remains valid"), Inventory->IsValidEntryHandle(FirstSlot));

	const FInventoryQuantityOperationResult EmptyExtractResult =
		Inventory->ExtractItemFromSlot(FirstSlot, 1);
	TestEqual(TEXT("Extracting from an empty slot fails"), EmptyExtractResult.Status, EInventoryQuantityOperationStatus::Failed);
	const FInventoryQuantityOperationResult InvalidExtractResult =
		Inventory->ExtractItemFromSlot({}, 1);
	TestEqual(TEXT("Extracting with an invalid handle fails"), InvalidExtractResult.Status, EInventoryQuantityOperationStatus::Failed);

	Owner->Destroy();
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryInteractionContextTest,
	"PackSystem.Inventory.Interaction.Context",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FInventoryInteractionContextTest::RunTest(const FString& Parameters)
{
	UWorld* World = FindInventoryTestWorld();
	if (!TestNotNull(TEXT("An editor or game world is available"), World))
	{
		return false;
	}

	UInventoryItemDefinition* WoodDefinition = NewObject<UInventoryItemDefinition>();
	UInventoryItemDefinition* StoneDefinition = NewObject<UInventoryItemDefinition>();
	TestTrue(TEXT("Wood stack size can be configured"), SetDefinitionMaxStackSize(WoodDefinition, 20));
	TestTrue(TEXT("Stone stack size can be configured"), SetDefinitionMaxStackSize(StoneDefinition, 20));

	AActor* SourceOwner = nullptr;
	AActor* TargetOwner = nullptr;
	USlottedInventoryComponent* SourceInventory =
		CreateRegisteredSlottedInventory(World, 2, SourceOwner);
	USlottedInventoryComponent* TargetInventory =
		CreateRegisteredSlottedInventory(World, 2, TargetOwner);
	if (!TestNotNull(TEXT("Source inventory can be created"), SourceInventory) ||
		!TestNotNull(TEXT("Target inventory can be created"), TargetInventory))
	{
		return false;
	}

	const FInventoryEntryHandle SourceSlot = SourceInventory->GetSlotHandle(0);
	const FInventoryEntryHandle TargetEmptySlot = TargetInventory->GetSlotHandle(0);
	const FInventoryEntryHandle TargetStoneSlot = TargetInventory->GetSlotHandle(1);
	SourceInventory->PlaceItemAtSlot(
		SourceSlot,
		WoodDefinition->CreateItemPayload(10, GetTransientPackage()));
	TargetInventory->PlaceItemAtSlot(
		TargetStoneSlot,
		StoneDefinition->CreateItemPayload(3, GetTransientPackage()));

	UInventoryInteractionContext* Context = NewObject<UInventoryInteractionContext>();
	const FInventoryQuantityOperationResult TakeResult =
		Context->TakeItemFromSlot(SourceSlot, 4);
	TestEqual(TEXT("Taking an item starts a held interaction"), TakeResult.Status, EInventoryQuantityOperationStatus::Succeeded);
	TestTrue(TEXT("Context reports a held item"), Context->IsHoldingItem());
	TestEqual(TEXT("Context holds the extracted quantity"), Context->GetHeldPayload().Quantity, int64{4});

	const FInventoryQuantityOperationResult RepeatedTakeResult =
		Context->TakeItemFromSlot(SourceSlot, 1);
	TestEqual(TEXT("Taking while already holding fails"), RepeatedTakeResult.Status, EInventoryQuantityOperationStatus::Failed);
	TestEqual(TEXT("Failed repeated take preserves held quantity"), Context->GetHeldPayload().Quantity, int64{4});

	const FInventoryQuantityOperationResult PlaceResult =
		Context->PlaceHeldItemAtSlot(TargetEmptySlot);
	TestEqual(TEXT("Placing the held item succeeds"), PlaceResult.Status, EInventoryQuantityOperationStatus::Succeeded);
	TestFalse(TEXT("Complete placement clears the context"), Context->IsHoldingItem());

	const FInventoryQuantityOperationResult SecondTakeResult =
		Context->TakeItemFromSlot(SourceSlot, 6);
	TestEqual(TEXT("A new interaction can start after placement"), SecondTakeResult.Status, EInventoryQuantityOperationStatus::Succeeded);
	const FInventoryQuantityOperationResult SwapResult =
		Context->PlaceHeldItemAtSlot(TargetStoneSlot);
	TestEqual(TEXT("Placing on an incompatible target swaps"), SwapResult.Status, EInventoryQuantityOperationStatus::Succeeded);
	TestEqual(TEXT("Context receives the target item after swap"), Context->GetHeldPayload().Quantity, int64{3});
	TestEqual(TEXT("Context receives the target definition after swap"), Context->GetHeldPayload().ItemDefinition.Get(), StoneDefinition);

	const FInventoryQuantityOperationResult CancelSwapResult = Context->CancelHeldItem();
	TestEqual(TEXT("Cancelling after swap returns the held item"), CancelSwapResult.Status, EInventoryQuantityOperationStatus::Succeeded);
	TestFalse(TEXT("Successful cancel clears the context"), Context->IsHoldingItem());
	FInventoryEntry SourceEntry;
	TestTrue(TEXT("Original source slot remains addressable"), SourceInventory->GetEntry(SourceSlot, SourceEntry));
	TestEqual(TEXT("Cancel prefers the original source slot"), SourceEntry.Payload.ItemDefinition.Get(), StoneDefinition);

	AActor* PartialOwner = nullptr;
	USlottedInventoryComponent* PartialInventory =
		CreateRegisteredSlottedInventory(World, 2, PartialOwner);
	if (!TestNotNull(TEXT("Partial cancel inventory can be created"), PartialInventory))
	{
		return false;
	}

	const FInventoryEntryHandle PartialOriginSlot = PartialInventory->GetSlotHandle(0);
	const FInventoryEntryHandle PartialStackSlot = PartialInventory->GetSlotHandle(1);
	PartialInventory->PlaceItemAtSlot(
		PartialOriginSlot,
		WoodDefinition->CreateItemPayload(20, GetTransientPackage()));
	PartialInventory->PlaceItemAtSlot(
		PartialStackSlot,
		WoodDefinition->CreateItemPayload(15, GetTransientPackage()));

	UInventoryInteractionContext* PartialContext = NewObject<UInventoryInteractionContext>();
	PartialContext->TakeItemFromSlot(PartialOriginSlot, 20);
	PartialInventory->PlaceItemAtSlot(
		PartialOriginSlot,
		StoneDefinition->CreateItemPayload(1, GetTransientPackage()));
	const FInventoryQuantityOperationResult PartialCancelResult =
		PartialContext->CancelHeldItem();
	TestEqual(TEXT("Cancel reports partial success when source has limited space"), PartialCancelResult.Status, EInventoryQuantityOperationStatus::PartialSucceeded);
	TestEqual(TEXT("Partially cancelled context keeps the remainder"), PartialContext->GetHeldPayload().Quantity, int64{15});
	TestTrue(TEXT("Partially cancelled context remains active"), PartialContext->IsHoldingItem());
	TestTrue(TEXT("Partial stack remains addressable"), PartialInventory->GetEntry(PartialStackSlot, SourceEntry));
	TestEqual(TEXT("Cancel fills available compatible capacity"), SourceEntry.Payload.Quantity, int64{20});

	const FInventoryQuantityOperationResult FailedCancelResult =
		PartialContext->CancelHeldItem();
	TestEqual(TEXT("Cancelling again with no space fails"), FailedCancelResult.Status, EInventoryQuantityOperationStatus::Failed);
	TestEqual(TEXT("Failed cancel preserves the held remainder"), PartialContext->GetHeldPayload().Quantity, int64{15});

	SourceOwner->Destroy();
	TargetOwner->Destroy();
	PartialOwner->Destroy();
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FSlottedInventoryAddItemTest,
	"PackSystem.Inventory.Slotted.AddItem",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FSlottedInventoryAddItemTest::RunTest(const FString& Parameters)
{
	UInventoryItemDefinition* WoodDefinition = NewObject<UInventoryItemDefinition>();
	UInventoryItemDefinition* StoneDefinition = NewObject<UInventoryItemDefinition>();
	TestTrue(TEXT("Wood stack size can be configured"), SetDefinitionMaxStackSize(WoodDefinition, 20));
	TestTrue(TEXT("Stone stack size can be configured"), SetDefinitionMaxStackSize(StoneDefinition, 20));

	USlottedInventoryComponent* CompleteInventory = NewObject<USlottedInventoryComponent>();
	const FInventoryEntryHandle PreferredSlot = AddTestSlot(
		CompleteInventory,
		WoodDefinition->CreateItemPayload(18, GetTransientPackage()),
		0);
	const FInventoryEntryHandle OtherStackSlot = AddTestSlot(
		CompleteInventory,
		WoodDefinition->CreateItemPayload(17, GetTransientPackage()),
		1);
	const FInventoryItemPayload StoneFour =
		StoneDefinition->CreateItemPayload(4, GetTransientPackage());
	const FInventoryEntryHandle IncompatibleSlot = AddTestSlot(CompleteInventory, StoneFour, 2);
	const FInventoryEntryHandle FirstEmptySlot = AddTestSlot(CompleteInventory, {}, 3);
	const FInventoryEntryHandle SecondEmptySlot = AddTestSlot(CompleteInventory, {}, 4);

	const FInventoryQuantityOperationResult CompleteResult = CompleteInventory->AddItem(
		WoodDefinition->CreateItemPayload(30, GetTransientPackage()),
		PreferredSlot);
	TestEqual(TEXT("Adding across several slots succeeds"), CompleteResult.Status, EInventoryQuantityOperationStatus::Succeeded);
	TestEqual(TEXT("All requested items are added"), CompleteResult.ChangedQuantity, int64{30});
	TestTrue(TEXT("No payload remains after a complete add"), CompleteResult.OutputPayload.IsEmpty());

	FInventoryEntry Entry;
	TestTrue(TEXT("Preferred slot remains addressable"), CompleteInventory->GetEntry(PreferredSlot, Entry));
	TestEqual(TEXT("Preferred stack is filled first"), Entry.Payload.Quantity, int64{20});
	TestTrue(TEXT("Other stack remains addressable"), CompleteInventory->GetEntry(OtherStackSlot, Entry));
	TestEqual(TEXT("Other compatible stack is filled"), Entry.Payload.Quantity, int64{20});
	TestTrue(TEXT("First empty slot remains addressable"), CompleteInventory->GetEntry(FirstEmptySlot, Entry));
	TestEqual(TEXT("First empty slot receives a full stack"), Entry.Payload.Quantity, int64{20});
	TestTrue(TEXT("Second empty slot remains addressable"), CompleteInventory->GetEntry(SecondEmptySlot, Entry));
	TestEqual(TEXT("Second empty slot receives the final quantity"), Entry.Payload.Quantity, int64{5});
	TestTrue(TEXT("Incompatible slot remains addressable"), CompleteInventory->GetEntry(IncompatibleSlot, Entry));
	TestTrue(TEXT("Automatic add never swaps an incompatible item"), Entry.Payload == StoneFour);

	USlottedInventoryComponent* PartialInventory = NewObject<USlottedInventoryComponent>();
	const FInventoryEntryHandle PartialPreferredSlot = AddTestSlot(
		PartialInventory,
		StoneDefinition->CreateItemPayload(7, GetTransientPackage()),
		0);
	const FInventoryEntryHandle PartialStackSlot = AddTestSlot(
		PartialInventory,
		WoodDefinition->CreateItemPayload(19, GetTransientPackage()),
		1);
	const FInventoryEntryHandle PartialEmptySlot = AddTestSlot(PartialInventory, {}, 2);
	const FInventoryQuantityOperationResult PartialResult = PartialInventory->AddItem(
		WoodDefinition->CreateItemPayload(25, GetTransientPackage()),
		PartialPreferredSlot);
	TestEqual(TEXT("Insufficient total space partially succeeds"), PartialResult.Status, EInventoryQuantityOperationStatus::PartialSucceeded);
	TestEqual(TEXT("Only available capacity is used"), PartialResult.ChangedQuantity, int64{21});
	TestEqual(TEXT("Unplaced quantity is returned"), PartialResult.OutputPayload.Quantity, int64{4});
	TestTrue(TEXT("Partial preferred slot remains addressable"), PartialInventory->GetEntry(PartialPreferredSlot, Entry));
	TestEqual(TEXT("Incompatible preferred slot is unchanged"), Entry.Payload.Quantity, int64{7});
	TestTrue(TEXT("Partial stack remains addressable"), PartialInventory->GetEntry(PartialStackSlot, Entry));
	TestEqual(TEXT("Compatible stack uses its remaining capacity"), Entry.Payload.Quantity, int64{20});
	TestTrue(TEXT("Partial empty slot remains addressable"), PartialInventory->GetEntry(PartialEmptySlot, Entry));
	TestEqual(TEXT("Empty slot receives one full stack"), Entry.Payload.Quantity, int64{20});

	USlottedInventoryComponent* FullInventory = NewObject<USlottedInventoryComponent>();
	const FInventoryEntryHandle FullPreferredSlot = AddTestSlot(
		FullInventory,
		StoneDefinition->CreateItemPayload(6, GetTransientPackage()),
		0);
	const FInventoryEntryHandle FullWoodSlot = AddTestSlot(
		FullInventory,
		WoodDefinition->CreateItemPayload(20, GetTransientPackage()),
		1);
	const FInventoryQuantityOperationResult FailedResult = FullInventory->AddItem(
		WoodDefinition->CreateItemPayload(5, GetTransientPackage()),
		FullPreferredSlot);
	TestEqual(TEXT("Adding with no available space fails"), FailedResult.Status, EInventoryQuantityOperationStatus::Failed);
	TestEqual(TEXT("Failed add returns the full payload"), FailedResult.OutputPayload.Quantity, int64{5});
	TestTrue(TEXT("Full preferred slot remains addressable"), FullInventory->GetEntry(FullPreferredSlot, Entry));
	TestEqual(TEXT("Failed add does not replace preferred item"), Entry.Payload.Quantity, int64{6});
	TestTrue(TEXT("Full wood slot remains addressable"), FullInventory->GetEntry(FullWoodSlot, Entry));
	TestEqual(TEXT("Failed add does not change full stacks"), Entry.Payload.Quantity, int64{20});

	return true;
}

#endif
