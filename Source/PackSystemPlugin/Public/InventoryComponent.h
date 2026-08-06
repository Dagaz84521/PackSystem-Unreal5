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

/**
 * 库存的权威数据拥有者与唯一写入入口。
 *
 * StorageStrategy 只读取当前状态并构建 Plan；Component 负责公共参数校验、过期检查、
 * 原子执行和事件广播。这样 Slot 与 Aggregate 可以共享同一套数据安全规则。
 */
UCLASS(BlueprintType, Blueprintable, ClassGroup = (Inventory), meta = (BlueprintSpawnableComponent))
class PACKSYSTEMPLUGIN_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

	/** 幂等初始化；BeginPlay 会自动调用，独立创建组件或测试时也可以主动调用。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool InitializeInventory();

	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool IsInventoryInitialized() const { return bInitialized; }

	/** 自动放置，或在 Request.TargetEntry 有效时仅尝试该目标。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult AddItem(const FInventoryAddRequest& Request);

	/** 按 CanStackWith 匹配并移除；持有量不足时返回部分成功。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult RemoveMatchingItem(UInventoryItemInstance* ItemInstance, int64 Quantity);

	/** 从指定 Entry 移除；归零后由 Strategy 决定清空 Slot 还是删除 Aggregate 记录。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult RemoveFromEntry(FInventoryEntryHandle EntryHandle, int64 Quantity);

	/** Slot 内移动、拆分或合并；不会隐式交换不兼容物品。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult MoveItem(FInventoryEntryHandle SourceEntry, FInventoryEntryHandle TargetEntry, int64 Quantity);

	/** 显式交换两个 Slot；Aggregate Strategy 会返回不支持。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult SwapEntries(FInventoryEntryHandle FirstEntry, FInventoryEntryHandle SecondEntry);

	/**
	 * 在两个容器间原子转移。TargetEntry 无效表示让目标 Strategy 自动放置；
	 * 目标能接收多少，源容器就只移除多少。
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult TransferItem(
		UInventoryComponent* TargetInventory,
		FInventoryEntryHandle SourceEntry,
		int64 Quantity,
		FInventoryEntryHandle TargetEntry);

	/** Slot 清空物品但保留全部 Handle；Aggregate 删除全部记录。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryOperationResult ClearInventory();

	/** 返回当前 Entry 的稳定 Handle；Slot 包含空格，Aggregate 只包含实际记录。 */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	TArray<FInventoryEntryHandle> GetAllEntryHandles() const;

	/** 安全读取 Entry 副本，调用者无法借此绕过 Component 直接修改库存。 */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool GetEntry(FInventoryEntryHandle EntryHandle, FInventoryEntry& OutEntry) const;

	/** Handle 必须指向当前组件中仍然存在的 Entry。 */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool IsValidEntryHandle(FInventoryEntryHandle EntryHandle) const;

	/** 按完整堆叠条件汇总数量，即 Definition 与实例状态都必须相同。 */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	int64 GetQuantityForItem(const UInventoryItemInstance* ItemInstance) const;

	/** 只按 Definition 汇总，包含该定义下不同实例状态的所有 Entry。 */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	int64 GetQuantityForDefinition(const UInventoryItemDefinition* ItemDefinition) const;

	/** 是否至少持有指定数量的可堆叠等价物品。 */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool ContainsItem(const UInventoryItemInstance* ItemInstance, int64 Quantity = 1) const;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	UInventoryStorageStrategy* GetStorageStrategy() const { return StorageStrategy; }

	/** C++ 初始化钩子；只允许在初始化前替换 Strategy。 */
	bool SetStorageStrategy(UInventoryStorageStrategy* InStorageStrategy);

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FInventoryChangedSignature OnInventoryChanged;

protected:
	virtual void BeginPlay() override;

private:
	/** 默认是 20 格 Slot Strategy；可在组件详情面板内联替换为 Aggregate。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category = "Inventory", meta = (AllowPrivateAccess = true))
	TObjectPtr<UInventoryStorageStrategy> StorageStrategy;

	UPROPERTY(VisibleInstanceOnly, Category = "Inventory")
	FInventoryEntryArray EntryArray;

	UPROPERTY(Transient)
	bool bInitialized = false;

	/** ID 只保证在当前容器内唯一；删除 Aggregate 记录后也不立即复用。 */
	UPROPERTY(Transient)
	int32 NextEntryID = 0;

	int32 FindEntryIndex(const FInventoryEntryHandle& EntryHandle, const TArray<FInventoryEntry>& Entries) const;
	int32 AllocateEntryID(const TArray<FInventoryEntry>& Entries, int32& InOutNextEntryID) const;
	/** 单容器的统一“校验 -> 副本执行 -> 提交”入口。 */
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
