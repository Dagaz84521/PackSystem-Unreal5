#pragma once

#include "CoreMinimal.h"
#include "Core/InventoryEntryArray.h"
#include "Core/InventoryItemPayload.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

/**
 * 具体背包组件共用的存储基类。
 *
 * 该类负责管理 Entry 及其稳定 Handle，但不定义堆叠、槽位放置、容量、
 * 物品接收条件等具体存储规则。派生组件通过受保护的 Entry 修改接口实现这些规则。
 */


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryEntryAddedDelegate, FInventoryEntryHandle, EntryHandle);

/** Entry 内容变化事件。 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryEntryChangedDelegate, FInventoryEntryHandle, EntryHandle);

/** Entry 删除事件。 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryEntryRemovedDelegate, FInventoryEntryHandle, EntryHandle);

/** 背包整体重建事件。 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInventoryResetDelegate);

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup = (Inventory), meta = (BlueprintSpawnableComponent))
class PACKSYSTEMPLUGIN_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

	/** 返回当前背包拥有的全部 Entry Handle。 */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	TArray<FInventoryEntryHandle> GetAllEntryHandles() const;

	/** 仅当 Handle 属于当前背包且仍能解析到 Entry 时返回 true。 */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool IsValidEntryHandle(const FInventoryEntryHandle& EntryHandle) const;

	/** 供蓝图使用的 Entry 查询接口；Handle 无效时会重置 OutEntry。 */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool GetEntry(const FInventoryEntryHandle& EntryHandle, FInventoryEntry& OutEntry) const;

	/** 不产生拷贝的 C++ 查询接口；EntryArray 发生结构变化后，返回的指针将失效。 */
	const FInventoryEntry* FindEntry(const FInventoryEntryHandle& EntryHandle) const;

	/** 创建了新的 Entry。 */
	UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
	FInventoryEntryAddedDelegate OnEntryAdded;

	/** 已有 Entry 的 Payload 发生变化。 */
	UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
	FInventoryEntryChangedDelegate OnEntryChanged;

	/** Entry 已被删除，此时 Handle 已经不能再解析到 Entry。 */
	UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
	FInventoryEntryRemovedDelegate OnEntryRemoved;

	/** 背包数据被整体重建，UI 应重新生成全部显示项。 */
	UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
	FInventoryResetDelegate OnInventoryReset;
	
protected:
	virtual void OnRegister() override;

	/** 供派生存储实现使用的可修改 Entry 查询接口。 */
	FInventoryEntry* FindMutableEntry(const FInventoryEntryHandle& EntryHandle);

	/** 创建 Entry，并分配一个在当前组件内唯一且稳定的 ID。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Internal", meta = (BlueprintProtected = "true"))
	FInventoryEntryHandle CreateEntry(const FInventoryItemPayload& Payload);

	/** 删除 Handle 标识的 Entry。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Internal", meta = (BlueprintProtected = "true"))
	bool RemoveEntry(const FInventoryEntryHandle& EntryHandle);

	/** 替换 Entry 的完整物品内容，同时保留 Entry 本身的标识。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Internal", meta = (BlueprintProtected = "true"))
	bool SetEntryPayload(
		const FInventoryEntryHandle& EntryHandle,
		const FInventoryItemPayload& Payload);

	/** 清空 Entry 的物品内容，同时保持其 Handle 有效。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Internal", meta = (BlueprintProtected = "true"))
	bool ClearEntry(const FInventoryEntryHandle& EntryHandle);

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Inventory")
	FInventoryEntryArray EntryArray;
	
	FInventoryEntryHandle MakeEntryHandle(int32 EntryID) const;

private:
	void RebuildRuntimeState();
	int32 AllocateEntryID();

	/** 内部使用 int64 计数，避免 int32 ID 耗尽后发生回绕。 */
	int64 NextEntryID = 0;
};
