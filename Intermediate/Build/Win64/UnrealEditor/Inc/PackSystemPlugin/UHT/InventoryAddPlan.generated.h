// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "InventoryAddPlan.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PACKSYSTEMPLUGIN_InventoryAddPlan_generated_h
#error "InventoryAddPlan.generated.h already included, missing '#pragma once' in InventoryAddPlan.h"
#endif
#define PACKSYSTEMPLUGIN_InventoryAddPlan_generated_h

#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddPlan_h_27_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics; \
	static class UScriptStruct* StaticStruct();


template<> PACKSYSTEMPLUGIN_API UScriptStruct* StaticStruct<struct FInventoryAddPlanChange>();

#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddPlan_h_49_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FInventoryAddPlan_Statics; \
	static class UScriptStruct* StaticStruct();


template<> PACKSYSTEMPLUGIN_API UScriptStruct* StaticStruct<struct FInventoryAddPlan>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddPlan_h


#define FOREACH_ENUM_EINVENTORYADDPLANOPERATION(op) \
	op(EInventoryAddPlanOperation::CreateEntry) \
	op(EInventoryAddPlanOperation::IncreaseQuantity) 

enum class EInventoryAddPlanOperation : uint8;
template<> struct TIsUEnumClass<EInventoryAddPlanOperation> { enum { Value = true }; };
template<> PACKSYSTEMPLUGIN_API UEnum* StaticEnum<EInventoryAddPlanOperation>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
