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
	// 组件开箱即用：没有显式配置时，它就是一个固定 20 格的 Slot 背包。
	// 因为 Strategy 是 Instanced 子对象，每个组件都能拥有自己独立的规则配置。
	StorageStrategy = CreateDefaultSubobject<USlottedStorageStrategy>(TEXT("StorageStrategy"));
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	InitializeInventory();
}

bool UInventoryComponent::SetStorageStrategy(UInventoryStorageStrategy* InStorageStrategy)
{
	// 初始化后再换规则会破坏已有 Entry 的不变量，例如把 Slot 空格交给 Aggregate。
	if (bInitialized || !IsValid(InStorageStrategy))
	{
		return false;
	}

	// 外部传入的模板对象不能直接共享；复制到组件下，使生命周期和配置都归当前背包所有。
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
	// 兼容编辑器预置或将来的反序列化数据：修复 Owner、重复 ID 和无效 ID。
	// ID 只要求容器内唯一；NextEntryID 单调前进，避免正常运行时过早复用旧 Handle。
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

	// 只有初始化阶段会补齐 Slot。运行时没有 Resize API，因此此后格子数量保持不变。
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
	// Handle 从权威 EntryArray 即时生成，避免维护一份容易失配的并行缓存。
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
		// 查询不应因为极端数据发生有符号整数溢出；无法精确表示时饱和到 int64 上限。
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
	// 公开入口只做与策略无关的防御性校验；放置顺序、堆叠上限等由 Strategy 决定。
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
		// 同容器“转移”退化为移动，避免为同一数组维护两份工作副本。
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
	// 先询问目标最多能接收多少，再按该数量为源端规划移除。
	// 这就是部分转移的核心：目标接收 N，源端也必须恰好移除 N。
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

	// 两个计划都通过校验后，仍只在各自副本上执行。任意一边失败时，真实容器均不改变。
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

	// 两边都准备完成后才连续提交，并延后广播；观察者不会看到只有一边完成的中间状态。
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

	// 最多检查 Num + 1 个候选就必然能找到空 ID（除非 int32 空间真的已经耗尽）。
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
	// 先校验数量守恒，阻止 Strategy 返回自相矛盾的“成功数量”。
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

	// 同一 Plan 不允许重复修改同一个既有 Entry，避免 Mutation 顺序影响语义。
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
		// ExpectedState 是计划阶段拍下的快照；不一致说明计划已经过期。
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
	// 本函数只操作调用者提供的工作副本。它可以失败，但绝不会留下半提交的真实库存。
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
			// 新堆叠拥有独立实例，防止未来修改 Instance Tags/Fragment 状态时串改其他堆叠。
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
	// 单容器操作的统一事务管线：校验 -> 副本执行 -> 一次提交 -> 一次广播。
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
	// MoveTemp 将已经完整验证的工作副本替换为权威状态；此前没有触碰真实数组。
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
