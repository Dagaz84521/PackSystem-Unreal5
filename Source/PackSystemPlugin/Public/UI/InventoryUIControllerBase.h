#pragma once

#include "CoreMinimal.h"
#include "Core/InventoryEntryArray.h"
#include "UObject/Object.h"
#include "InventoryUIControllerBase.generated.h"

class UInventoryComponent;

/**
 * Inventory UIController 共用的 Model 绑定层。
 *
 * 基类只管理 Inventory 生命周期和事件转发，不知道具体 View、ViewData 或用户操作。
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class PACKSYSTEMPLUGIN_API UInventoryUIControllerBase : public UObject
{
	GENERATED_BODY()

public:
	/** 解绑当前 Inventory；派生类覆写时应同时解绑 View，并调用 Super。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	virtual void Shutdown();

protected:
	/** 绑定新的 Inventory。失败时保持未绑定状态。 */
	bool BindInventory(UInventoryComponent* InInventory);

	/** 解绑四类 Inventory 事件并清除 Model 引用。 */
	void UnbindInventory();

	UInventoryComponent* GetInventory() const { return Inventory; }

	virtual void InventoryEntryAdded(const FInventoryEntryHandle& EntryHandle);
	virtual void InventoryEntryChanged(const FInventoryEntryHandle& EntryHandle);
	virtual void InventoryEntryRemoved(const FInventoryEntryHandle& EntryHandle);
	virtual void InventoryReset();

private:
	UFUNCTION()
	void HandleEntryAdded(FInventoryEntryHandle EntryHandle);

	UFUNCTION()
	void HandleEntryChanged(FInventoryEntryHandle EntryHandle);

	UFUNCTION()
	void HandleEntryRemoved(FInventoryEntryHandle EntryHandle);

	UFUNCTION()
	void HandleInventoryReset();

	UPROPERTY()
	TObjectPtr<UInventoryComponent> Inventory;
};
