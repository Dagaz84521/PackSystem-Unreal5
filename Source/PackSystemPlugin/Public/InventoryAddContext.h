// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryAddContext.generated.h"

/**
 * 一次添加操作所携带的策略相关数据。
 *
 * 派生 USTRUCT 只负责保存参数；物品的放置行为仍由
 * UInventoryStorageStrategy 实现。
 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryAddContext
{
	GENERATED_BODY()
};
