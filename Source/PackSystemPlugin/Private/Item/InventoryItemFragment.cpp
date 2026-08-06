// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/InventoryItemFragment.h"

void UInventoryItemFragment::OnInstanceCreated_Implementation(UInventoryItemInstance* Instance) const
{
	// 基类不写入额外数据，具体初始化逻辑由派生 Fragment 实现。
}
