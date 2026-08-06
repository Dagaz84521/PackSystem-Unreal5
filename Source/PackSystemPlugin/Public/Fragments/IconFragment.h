// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/InventoryItemFragment.h"
#include "IconFragment.generated.h"

class UTexture2D;

/**
 * 为物品提供 UI 图标的配置片段。
 *
 * 这里显式声明 EditInlineNew，确保该具体类会出现在 Instanced Fragment 数组的
 * “新建”类型菜单中；仅有 BlueprintType 并不足以保证可作为内联子对象创建。
 */
UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class PACKSYSTEMPLUGIN_API UIconFragment : public UInventoryItemFragment
{
	GENERATED_BODY()

public:
	/** 软引用图标，打开物品定义资产时不会强制加载纹理。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Icon")
	TSoftObjectPtr<UTexture2D> Icon;
};
