// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/InventoryComponent.h"
#include "Core/InventoryQuantityOperationResult.h"
#include "SlottedInventoryComponent.generated.h"

UENUM(BlueprintType)
enum class EInventorySlotPlacementAction : uint8
{
	PlaceInEmptySlot UMETA(DisplayName = "Place In Empty Slot"),
	StackOnExistingItem UMETA(DisplayName = "Stack On Existing Item"),
	ReplaceExistingItem UMETA(DisplayName = "Replace Existing Item"),
	NoAction UMETA(DisplayName = "No Action")
};

/**
 * 
 */
UCLASS()
class PACKSYSTEMPLUGIN_API USlottedInventoryComponent : public UInventoryComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Inventory|Slotted")
	int32 GetSlotCount() const;

	UFUNCTION(BlueprintPure, Category = "Inventory|Slotted")
	FInventoryEntryHandle GetSlotHandle(int32 SlotIndex) const;

	UFUNCTION(BlueprintPure, Category = "Inventory|Slotted")
	bool IsSlotEmpty(const FInventoryEntryHandle& SlotHandle) const;

	/** 从指定格子提取完整或部分物品。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slotted")
	FInventoryQuantityOperationResult ExtractItemFromSlot(
		const FInventoryEntryHandle& SlotHandle,
		int64 Quantity);

	/** 将 Cursor Payload 放置、合并或交换到指定格子。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slotted")
	FInventoryQuantityOperationResult PlaceItemAtSlot(
		const FInventoryEntryHandle& SlotHandle,
		const FInventoryItemPayload& CursorPayload);

	/** 自动将 Payload 加入相容堆叠或空格，并优先尝试指定格子。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slotted")
	FInventoryQuantityOperationResult AddItem(
		const FInventoryItemPayload& Payload,
		const FInventoryEntryHandle& PreferredSlot);

protected:
	virtual void OnRegister() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Slotted", meta = (ClampMin = "0", UIMin = "0"))
	int32 SlotCount = 0;

private:
	/** 根据配置补齐固定空格；已有 Entry 永远不会在初始化阶段被删除。 */
	void EnsureSlotsInitialized();

	FInventoryQuantityOperationResult PlaceInEmptySlot(
		const FInventoryEntryHandle& SlotHandle,
		const FInventoryItemPayload& CursorPayload,
		int64 MaxStackSize);

	FInventoryQuantityOperationResult MergeIntoSlot(
		const FInventoryEntryHandle& SlotHandle,
		const FInventoryItemPayload& TargetPayload,
		const FInventoryItemPayload& CursorPayload,
		int64 MaxStackSize);

	FInventoryQuantityOperationResult SwapWithSlot(
		const FInventoryEntryHandle& SlotHandle,
		const FInventoryItemPayload& TargetPayload,
		const FInventoryItemPayload& CursorPayload,
		int64 MaxStackSize);

	/** 尝试把 RemainingPayload 合并进一个相容堆叠；不适用的格子会被正常跳过。 */
	bool TryMergeRemainingIntoSlot(
		const FInventoryEntryHandle& SlotHandle,
		int64 MaxStackSize,
		FInventoryItemPayload& RemainingPayload,
		int64& OutPlacedQuantity);

	/** 尝试把 RemainingPayload 的一个堆叠写入空格；非空格子会被正常跳过。 */
	bool TryPlaceRemainingInEmptySlot(
		const FInventoryEntryHandle& SlotHandle,
		int64 MaxStackSize,
		FInventoryItemPayload& RemainingPayload,
		int64& OutPlacedQuantity);

	/** 尝试一个格子，并累计自动添加操作的总变化量和首个受影响格。 */
	bool TryAddRemainingToSlot(
		const FInventoryEntryHandle& SlotHandle,
		int64 MaxStackSize,
		EInventorySlotPlacementAction PlacementAction,
		FInventoryItemPayload& RemainingPayload,
		int64& ChangedQuantity,
		FInventoryEntryHandle& FirstAffectedSlot);

	/** 按指定策略扫描除 PreferredSlot 外的全部格子，直到物品放完或写入失败。 */
	bool TryAddRemainingAcrossSlots(
		const TArray<FInventoryEntryHandle>& SlotHandles,
		const FInventoryEntryHandle& PreferredSlot,
		int64 MaxStackSize,
		EInventorySlotPlacementAction PlacementAction,
		FInventoryItemPayload& RemainingPayload,
		int64& ChangedQuantity,
		FInventoryEntryHandle& FirstAffectedSlot);

	static FInventoryQuantityOperationResult MakeFailedPlacementResult(
		const FInventoryItemPayload& CursorPayload);
};
