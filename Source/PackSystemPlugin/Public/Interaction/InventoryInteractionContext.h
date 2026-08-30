#pragma once

#include "CoreMinimal.h"
#include "Core/InventoryQuantityOperationResult.h"
#include "UObject/Object.h"
#include "InventoryInteractionContext.generated.h"

class USlottedInventoryComponent;

/** Held Payload 发生变化后广播；监听者可通过 GetHeldPayload 读取最新状态。 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInventoryHeldPayloadChangedDelegate);

/**
 * 一次 Slotted Inventory 鼠标交互会话。
 *
 * Context 独立于 Widget，负责保存鼠标当前持有的 Payload 及其来源。它应由
 * PlayerController、HUD 或长期存在的 UI Manager 持有，避免关闭 Widget 时丢失物品。
 */
UCLASS(BlueprintType, Blueprintable)
class PACKSYSTEMPLUGIN_API UInventoryInteractionContext : public UObject
{
	GENERATED_BODY()

public:
	/** 当前 Cursor 是否持有一个有效物品 Payload。 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Interaction")
	bool IsHoldingItem() const;

	/** 返回当前 Cursor Payload 的副本。 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Interaction")
	FInventoryItemPayload GetHeldPayload() const;

	/** 从来源格子准确提取指定数量，并在成功后开始一次持有会话。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Interaction")
	FInventoryQuantityOperationResult TakeItemFromSlot(
		const FInventoryEntryHandle& SourceSlot,
		int64 Quantity);

	/** 将当前 Cursor 应用到目标格，并根据结果更新 Cursor。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Interaction")
	FInventoryQuantityOperationResult PlaceHeldItemAtSlot(
		const FInventoryEntryHandle& TargetSlot);

	/** 优先归还来源格，再由来源背包自动寻找其他可用格子。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Interaction")
	FInventoryQuantityOperationResult CancelHeldItem();

	UPROPERTY(BlueprintAssignable, Category = "Inventory|Interaction")
	FInventoryHeldPayloadChangedDelegate OnHeldPayloadChanged;

private:
	USlottedInventoryComponent* ResolveSlottedInventory(
		const FInventoryEntryHandle& SlotHandle) const;

	void SetHeldPayload(const FInventoryItemPayload& NewPayload);
	void ClearOrigin();

	static FInventoryQuantityOperationResult MakeFailedCursorResult(
		const FInventoryItemPayload& CursorPayload);

	UPROPERTY(Transient)
	FInventoryItemPayload HeldPayload;

	UPROPERTY(Transient)
	TWeakObjectPtr<USlottedInventoryComponent> OriginInventory;

	UPROPERTY(Transient)
	FInventoryEntryHandle OriginSlot;
};
