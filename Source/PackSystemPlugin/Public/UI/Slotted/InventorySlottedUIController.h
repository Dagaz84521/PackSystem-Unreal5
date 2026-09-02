#pragma once

#include "CoreMinimal.h"
#include "UI/InventoryUIControllerBase.h"
#include "InventorySlottedUIController.generated.h"

class UInventoryInteractionContext;
class USlottedInventoryComponent;

/**
 * 玩家 Slotted Inventory 界面的 Controller 基础框架。
 *
 * 目前只负责绑定 Inventory，并创建该玩家 UI 唯一的交互 Context。
 * 具体 View、格子点击和 ViewData 转换将在相应 UI 契约确定后补充。
 */
UCLASS(BlueprintType, Blueprintable)
class PACKSYSTEMPLUGIN_API UInventorySlottedUIController : public UInventoryUIControllerBase
{
	GENERATED_BODY()

public:
	/** 切换当前观察的 Slotted Inventory，并完成通用 Inventory 事件绑定。 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void Initialize(USlottedInventoryComponent* InInventory);

	/** 解绑当前 Inventory；InteractionContext 跟随 Controller 生命周期，不在此处销毁。 */
	virtual void Shutdown() override;

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	USlottedInventoryComponent* GetSlottedInventory() const;

	/**
	 * 返回该玩家 UI 唯一的交互 Context。
	 * 箱子、装备等 Controller 应共享此引用，而不是自行创建新的 Context。
	 */
	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	UInventoryInteractionContext* GetInteractionContext() const;

private:
	/** 首次成功初始化时创建 Context；重复初始化保持对象地址不变。 */
	void EnsureInteractionContext();

	UPROPERTY(Transient)
	TObjectPtr<UInventoryInteractionContext> InteractionContext;
};
