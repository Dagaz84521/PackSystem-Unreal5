#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InventoryEntryArray.h"
#include "InventoryOperationTypes.generated.h"

class UInventoryItemInstance;

/** 一次公开库存操作的最终状态；PartialSucceeded 表示只处理了请求数量的一部分。 */
UENUM(BlueprintType)
enum class EInventoryOperationStatus : uint8
{
	Failed,
	PartialSucceeded,
	Succeeded
};

/**
 * Entry 中与物品有关的最小状态快照。
 *
 * 快照只有两种合法形态：空状态（空指针且数量为 0），或有效物品且数量大于 0。
 * Plan 同时记录修改前后的快照，Component 因而可以在提交前发现计划是否已经过期。
 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryEntryState
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	TObjectPtr<UInventoryItemInstance> ItemInstance = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory", meta = (ClampMin = "0"))
	int64 Quantity = 0;

	FInventoryEntryState() = default;
	FInventoryEntryState(UInventoryItemInstance* InItemInstance, const int64 InQuantity)
		 : ItemInstance(InItemInstance), Quantity(InQuantity)
	{
	}

	bool HasValidState() const
	{
		return (ItemInstance == nullptr && Quantity == 0)
			|| (::IsValid(ItemInstance) && Quantity > 0);
	}

	bool operator==(const FInventoryEntryState& Other) const
	{
		return ItemInstance == Other.ItemInstance && Quantity == Other.Quantity;
	}

	bool operator!=(const FInventoryEntryState& Other) const { return !(*this == Other); }
};

/** Component 执行器能够理解的三种底层变更，具体背包规则不会进入执行器。 */
UENUM()
enum class EInventoryEntryMutationType : uint8
{
	/** 创建一个新 Entry；Aggregate 添加新种类时使用。 */
	Create,
	/** 保留 Handle，只替换 Entry 状态；Slot 填充、清空、移动和交换都使用它。 */
	Update,
	/** 删除 Entry 并使 Handle 失效；Aggregate 数量归零时使用。 */
	Delete
};

/**
 * Strategy 计算出的单条变更建议。
 * ExpectedState 相当于乐观锁：只有执行时 Entry 仍和规划时一致，变更才允许提交。
 */
USTRUCT()
struct PACKSYSTEMPLUGIN_API FInventoryEntryMutation
{
	GENERATED_BODY()

	UPROPERTY()
	EInventoryEntryMutationType Type = EInventoryEntryMutationType::Update;

	UPROPERTY()
	FInventoryEntryHandle TargetEntry;

	UPROPERTY()
	FInventoryEntryState ExpectedState;

	UPROPERTY()
	FInventoryEntryState DesiredState;

	/**
	 * 新建或拆分堆叠时复制实例，确保两个 Entry 不共享同一个可变 UObject。
	 * 整堆移动和交换则保持 false，以保留原来的实例对象。
	 */
	UPROPERTY()
	bool bDuplicateItemInstance = false;
};

/**
 * Strategy 的只读计算结果。Plan 只描述“准备怎样改”，不代表库存已经发生变化。
 * Component 会校验全部 Mutations，在数组副本中执行成功后才一次性提交。
 */
USTRUCT()
struct PACKSYSTEMPLUGIN_API FInventoryOperationPlan
{
	GENERATED_BODY()

	int64 RequestedQuantity = 0;
	int64 PlannedQuantity = 0;
	int64 RemainingQuantity = 0;
	FGameplayTag FailureReason;
	TArray<FInventoryEntryMutation> Mutations;
};

/** 返回给 C++/蓝图调用者的已执行结果。 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryOperationResult
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	EInventoryOperationStatus Status = EInventoryOperationStatus::Failed;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	int64 RequestedQuantity = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	int64 ProcessedQuantity = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	int64 RemainingQuantity = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	FGameplayTag FailureReason;
};

/** 单个 Entry 提交前后的变化，供 UI 或其他观察者增量刷新。 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryEntryChange
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	FInventoryEntryHandle EntryHandle;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	FInventoryEntryState Before;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	FInventoryEntryState After;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	bool bEntryCreated = false;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	bool bEntryDeleted = false;
};

/** 一次库存操作产生的完整变化集合；成功操作每个容器只广播一次。 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryChangeSet
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	TArray<FInventoryEntryChange> Changes;
};
