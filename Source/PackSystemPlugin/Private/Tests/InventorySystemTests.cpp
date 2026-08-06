#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "InventoryComponent.h"
#include "InventoryOperationTags.h"
#include "Item/InventoryItemDefinition.h"
#include "Item/InventoryItemInstance.h"
#include "Strategy/AggregatedStorageStrategy.h"
#include "Strategy/SlottedStorageStrategy.h"
#include "Tests/InventoryTestListener.h"
#include "UObject/UnrealType.h"

namespace
{
	void SetIntProperty(UObject* Object, const TCHAR* PropertyName, const int32 Value)
	{
		FIntProperty* Property = FindFProperty<FIntProperty>(Object->GetClass(), PropertyName);
		check(Property);
		Property->SetPropertyValue_InContainer(Object, Value);
	}

	UInventoryItemInstance* MakeItem(const int32 MaxStackSize, UInventoryItemDefinition*& OutDefinition)
	{
		OutDefinition = NewObject<UInventoryItemDefinition>(GetTransientPackage());
		SetIntProperty(OutDefinition, TEXT("MaxStackSize"), MaxStackSize);
		return OutDefinition->CreateItemInstance(GetTransientPackage());
	}

	UInventoryItemInstance* MakeItemFromDefinition(UInventoryItemDefinition* Definition)
	{
		return Definition->CreateItemInstance(GetTransientPackage());
	}

	UInventoryComponent* MakeAggregatedInventory()
	{
		UInventoryComponent* Inventory = NewObject<UInventoryComponent>(GetTransientPackage());
		Inventory->SetStorageStrategy(NewObject<UAggregatedStorageStrategy>(Inventory));
		check(Inventory->InitializeInventory());
		return Inventory;
	}

	UInventoryComponent* MakeSlottedInventory(const int32 SlotCount)
	{
		UInventoryComponent* Inventory = NewObject<UInventoryComponent>(GetTransientPackage());
		USlottedStorageStrategy* Strategy = NewObject<USlottedStorageStrategy>(Inventory);
		SetIntProperty(Strategy, TEXT("SlotCount"), SlotCount);
		Inventory->SetStorageStrategy(Strategy);
		check(Inventory->InitializeInventory());
		return Inventory;
	}

	FInventoryOperationResult Add(
		UInventoryComponent* Inventory,
		UInventoryItemInstance* Item,
		const int64 Quantity,
		const FInventoryEntryHandle Target = FInventoryEntryHandle())
	{
		FInventoryAddRequest Request;
		Request.InventoryItemInstance = Item;
		Request.Quantity = Quantity;
		Request.TargetEntry = Target;
		return Inventory->AddItem(Request);
	}

	FInventoryEntry EntryAt(UInventoryComponent* Inventory, const FInventoryEntryHandle& Handle)
	{
		FInventoryEntry Entry;
		check(Inventory->GetEntry(Handle, Entry));
		return Entry;
	}
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryAggregatedCrudTest,
	"PackSystem.Inventory.AggregatedCRUD",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FInventoryAggregatedCrudTest::RunTest(const FString& Parameters)
{
	UInventoryComponent* Inventory = MakeAggregatedInventory();
	TestEqual(TEXT("Aggregate begins without entries"), Inventory->GetAllEntryHandles().Num(), 0);

	UInventoryItemDefinition* Definition = nullptr;
	UInventoryItemInstance* Item = MakeItem(5, Definition);
	FInventoryOperationResult Result = Add(Inventory, Item, 10);
	TestEqual(TEXT("First add succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	TestEqual(TEXT("First add creates one record"), Inventory->GetAllEntryHandles().Num(), 1);
	TestEqual(TEXT("Quantity after first add"), Inventory->GetQuantityForItem(Item), static_cast<int64>(10));

	Result = Add(Inventory, Item, 5);
	TestEqual(TEXT("Compatible add succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	TestEqual(TEXT("Compatible add keeps one record"), Inventory->GetAllEntryHandles().Num(), 1);
	TestEqual(TEXT("Compatible quantity aggregates"), Inventory->GetQuantityForDefinition(Definition), static_cast<int64>(15));

	UInventoryItemInstance* Variant = MakeItemFromDefinition(Definition);
	Variant->AddInstanceTag(InventoryOperationTags::NoChange);
	Result = Add(Inventory, Variant, 3);
	TestEqual(TEXT("Different instance state creates another record"), Inventory->GetAllEntryHandles().Num(), 2);
	TestEqual(TEXT("Definition query sums variants"), Inventory->GetQuantityForDefinition(Definition), static_cast<int64>(18));

	Result = Inventory->RemoveMatchingItem(Item, 20);
	TestEqual(TEXT("Oversized remove is partial"), Result.Status, EInventoryOperationStatus::PartialSucceeded);
	TestEqual(TEXT("Oversized remove processes available quantity"), Result.ProcessedQuantity, static_cast<int64>(15));
	TestEqual(TEXT("Depleted aggregate entry is deleted"), Inventory->GetAllEntryHandles().Num(), 1);

	Result = Inventory->ClearInventory();
	TestEqual(TEXT("Clear succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	TestEqual(TEXT("Clear deletes aggregate records"), Inventory->GetAllEntryHandles().Num(), 0);

	UInventoryComponent* OverflowInventory = MakeAggregatedInventory();
	Result = Add(OverflowInventory, Item, MAX_int64);
	TestEqual(TEXT("MAX_int64 add succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	Result = Add(OverflowInventory, Item, 1);
	TestEqual(TEXT("Overflow add fails"), Result.Status, EInventoryOperationStatus::Failed);
	TestEqual(TEXT("Overflow does not change quantity"), OverflowInventory->GetQuantityForItem(Item), MAX_int64);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventorySlottedCrudTest,
	"PackSystem.Inventory.SlottedCRUD",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FInventorySlottedCrudTest::RunTest(const FString& Parameters)
{
	UInventoryComponent* Inventory = MakeSlottedInventory(3);
	const TArray<FInventoryEntryHandle> OriginalHandles = Inventory->GetAllEntryHandles();
	TestEqual(TEXT("Slot inventory creates fixed entries"), OriginalHandles.Num(), 3);

	UInventoryItemDefinition* WoodDefinition = nullptr;
	UInventoryItemInstance* Wood = MakeItem(5, WoodDefinition);
	FInventoryOperationResult Result = Add(Inventory, Wood, 12);
	TestEqual(TEXT("Multi-slot add succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	TestEqual(TEXT("First stack is full"), EntryAt(Inventory, OriginalHandles[0]).Quantity, static_cast<int64>(5));
	TestEqual(TEXT("Second stack is full"), EntryAt(Inventory, OriginalHandles[1]).Quantity, static_cast<int64>(5));
	TestEqual(TEXT("Third stack has remainder"), EntryAt(Inventory, OriginalHandles[2]).Quantity, static_cast<int64>(2));

	Result = Add(Inventory, Wood, 5);
	TestEqual(TEXT("Full slot inventory partially accepts"), Result.Status, EInventoryOperationStatus::PartialSucceeded);
	TestEqual(TEXT("Only remaining capacity is accepted"), Result.ProcessedQuantity, static_cast<int64>(3));

	Result = Inventory->RemoveMatchingItem(Wood, 20);
	TestEqual(TEXT("Oversized slot removal is partial"), Result.Status, EInventoryOperationStatus::PartialSucceeded);
	TestEqual(TEXT("All slot items removed"), Result.ProcessedQuantity, static_cast<int64>(15));
	TestTrue(TEXT("Empty slots retain handles"), Inventory->GetAllEntryHandles() == OriginalHandles);

	Result = Add(Inventory, Wood, 5, OriginalHandles[0]);
	TestEqual(TEXT("Targeted add succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	Result = Inventory->MoveItem(OriginalHandles[0], OriginalHandles[1], 2);
	TestEqual(TEXT("Split succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	TestEqual(TEXT("Split source quantity"), EntryAt(Inventory, OriginalHandles[0]).Quantity, static_cast<int64>(3));
	TestEqual(TEXT("Split target quantity"), EntryAt(Inventory, OriginalHandles[1]).Quantity, static_cast<int64>(2));

	Result = Inventory->MoveItem(OriginalHandles[1], OriginalHandles[0], 5);
	TestEqual(TEXT("Merge larger than source is partial"), Result.Status, EInventoryOperationStatus::PartialSucceeded);
	TestEqual(TEXT("Merge fills target"), EntryAt(Inventory, OriginalHandles[0]).Quantity, static_cast<int64>(5));
	TestTrue(TEXT("Merge empties source"), EntryAt(Inventory, OriginalHandles[1]).IsEmpty());

	UInventoryItemDefinition* StoneDefinition = nullptr;
	UInventoryItemInstance* Stone = MakeItem(5, StoneDefinition);
	Result = Add(Inventory, Stone, 1, OriginalHandles[1]);
	TestEqual(TEXT("Different item targeted add succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	Result = Inventory->MoveItem(OriginalHandles[0], OriginalHandles[1], 1);
	TestEqual(TEXT("Incompatible move fails"), Result.Status, EInventoryOperationStatus::Failed);

	Result = Inventory->SwapEntries(OriginalHandles[0], OriginalHandles[1]);
	TestEqual(TEXT("Explicit swap succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	TestEqual(TEXT("Swap moves stone"), EntryAt(Inventory, OriginalHandles[0]).ItemInstance->GetItemDefinition(), StoneDefinition);
	TestEqual(TEXT("Swap moves wood"), EntryAt(Inventory, OriginalHandles[1]).ItemInstance->GetItemDefinition(), WoodDefinition);

	Result = Inventory->ClearInventory();
	TestEqual(TEXT("Slot clear succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	for (const FInventoryEntryHandle& Handle : OriginalHandles)
	{
		TestTrue(TEXT("Slot clear preserves empty entry"), EntryAt(Inventory, Handle).IsEmpty());
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryTransferAndEventTest,
	"PackSystem.Inventory.TransferAndEvents",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FInventoryTransferAndEventTest::RunTest(const FString& Parameters)
{
	UInventoryComponent* Source = MakeAggregatedInventory();
	UInventoryComponent* Target = MakeSlottedInventory(2);
	UInventoryTestListener* SourceListener = NewObject<UInventoryTestListener>();
	UInventoryTestListener* TargetListener = NewObject<UInventoryTestListener>();
	Source->OnInventoryChanged.AddDynamic(SourceListener, &UInventoryTestListener::HandleInventoryChanged);
	Target->OnInventoryChanged.AddDynamic(TargetListener, &UInventoryTestListener::HandleInventoryChanged);

	UInventoryItemDefinition* Definition = nullptr;
	UInventoryItemInstance* Item = MakeItem(5, Definition);
	Add(Source, Item, 10);
	SourceListener->CallCount = 0;
	TargetListener->CallCount = 0;

	FInventoryEntryHandle SourceHandle = Source->GetAllEntryHandles()[0];
	FInventoryOperationResult Result = Source->TransferItem(Target, SourceHandle, 7, FInventoryEntryHandle());
	TestEqual(TEXT("Aggregate to slot transfer succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	TestEqual(TEXT("Transfer target quantity"), Target->GetQuantityForItem(Item), static_cast<int64>(7));
	TestEqual(TEXT("Transfer source quantity"), Source->GetQuantityForItem(Item), static_cast<int64>(3));
	TestEqual(TEXT("Source broadcasts once"), SourceListener->CallCount, 1);
	TestEqual(TEXT("Target broadcasts once"), TargetListener->CallCount, 1);

	SourceHandle = Source->GetAllEntryHandles()[0];
	Result = Source->TransferItem(Target, SourceHandle, 10, FInventoryEntryHandle());
	TestEqual(TEXT("Capacity-limited transfer is partial"), Result.Status, EInventoryOperationStatus::PartialSucceeded);
	TestEqual(TEXT("Capacity-limited transfer processes free capacity"), Result.ProcessedQuantity, static_cast<int64>(3));
	TestEqual(TEXT("Source entry removed at zero"), Source->GetAllEntryHandles().Num(), 0);
	TestEqual(TEXT("Target reaches capacity"), Target->GetQuantityForItem(Item), static_cast<int64>(10));

	Add(Source, Item, 2);
	SourceListener->CallCount = 0;
	TargetListener->CallCount = 0;
	SourceHandle = Source->GetAllEntryHandles()[0];
	Result = Source->TransferItem(Target, SourceHandle, 2, FInventoryEntryHandle());
	TestEqual(TEXT("Transfer to full target fails"), Result.Status, EInventoryOperationStatus::Failed);
	TestEqual(TEXT("Failed transfer leaves source unchanged"), Source->GetQuantityForItem(Item), static_cast<int64>(2));
	TestEqual(TEXT("Failed transfer does not broadcast source"), SourceListener->CallCount, 0);
	TestEqual(TEXT("Failed transfer does not broadcast target"), TargetListener->CallCount, 0);

	UInventoryComponent* AggregateTarget = MakeAggregatedInventory();
	Result = Source->TransferItem(AggregateTarget, SourceHandle, 1, FInventoryEntryHandle());
	TestEqual(TEXT("Aggregate to aggregate transfer succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	TestEqual(TEXT("Aggregate target receives quantity"), AggregateTarget->GetQuantityForItem(Item), static_cast<int64>(1));

	UInventoryComponent* SlotSource = MakeSlottedInventory(1);
	UInventoryComponent* SlotTarget = MakeSlottedInventory(1);
	Add(SlotSource, Item, 5);
	FInventoryEntryHandle SlotSourceHandle = SlotSource->GetAllEntryHandles()[0];
	Result = SlotSource->TransferItem(SlotTarget, SlotSourceHandle, 5, FInventoryEntryHandle());
	TestEqual(TEXT("Slot to slot transfer succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	TestEqual(TEXT("Slot target receives full stack"), SlotTarget->GetQuantityForItem(Item), static_cast<int64>(5));

	SlotSource = MakeSlottedInventory(1);
	Add(SlotSource, Item, 4);
	SlotSourceHandle = SlotSource->GetAllEntryHandles()[0];
	Result = SlotSource->TransferItem(AggregateTarget, SlotSourceHandle, 3, FInventoryEntryHandle());
	TestEqual(TEXT("Slot to aggregate transfer succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	TestEqual(TEXT("Slot source keeps remainder"), SlotSource->GetQuantityForItem(Item), static_cast<int64>(1));
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryValidationTest,
	"PackSystem.Inventory.Validation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FInventoryValidationTest::RunTest(const FString& Parameters)
{
	UInventoryComponent* Inventory = MakeSlottedInventory(2);
	UInventoryComponent* OtherInventory = MakeSlottedInventory(1);
	UInventoryItemDefinition* Definition = nullptr;
	UInventoryItemInstance* Item = MakeItem(5, Definition);

	FInventoryOperationResult Result = Add(Inventory, nullptr, 1);
	TestEqual(TEXT("Null item add fails"), Result.Status, EInventoryOperationStatus::Failed);
	Result = Add(Inventory, Item, 0);
	TestEqual(TEXT("Zero quantity add fails"), Result.Status, EInventoryOperationStatus::Failed);
	Result = Add(Inventory, Item, 1, OtherInventory->GetAllEntryHandles()[0]);
	TestEqual(TEXT("Foreign target add fails"), Result.Status, EInventoryOperationStatus::Failed);

	FInventoryEntryHandle Malformed(INDEX_NONE, Inventory);
	Result = Add(Inventory, Item, 1, Malformed);
	TestEqual(TEXT("Malformed target add fails"), Result.Status, EInventoryOperationStatus::Failed);

	Result = Inventory->RemoveFromEntry(OtherInventory->GetAllEntryHandles()[0], 1);
	TestEqual(TEXT("Foreign remove fails"), Result.Status, EInventoryOperationStatus::Failed);

	UInventoryComponent* Aggregate = MakeAggregatedInventory();
	Add(Aggregate, Item, 1);
	const FInventoryEntryHandle AggregateHandle = Aggregate->GetAllEntryHandles()[0];
	Result = Aggregate->MoveItem(AggregateHandle, AggregateHandle, 1);
	TestEqual(TEXT("Aggregate move is unsupported"), Result.Status, EInventoryOperationStatus::Failed);

	Result = OtherInventory->ClearInventory();
	TestEqual(TEXT("Clearing an empty inventory succeeds"), Result.Status, EInventoryOperationStatus::Succeeded);
	return true;
}

#endif
