// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "InventoryAddResult.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PACKSYSTEMPLUGIN_InventoryAddResult_generated_h
#error "InventoryAddResult.generated.h already included, missing '#pragma once' in InventoryAddResult.h"
#endif
#define PACKSYSTEMPLUGIN_InventoryAddResult_generated_h

#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddResult_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FInventoryAddResult_Statics; \
	static class UScriptStruct* StaticStruct();


template<> PACKSYSTEMPLUGIN_API UScriptStruct* StaticStruct<struct FInventoryAddResult>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddResult_h


#define FOREACH_ENUM_EINVENTORYOPERATIONSTATUS(op) \
	op(EInventoryOperationStatus::Failed) \
	op(EInventoryOperationStatus::PartialSucceeded) \
	op(EInventoryOperationStatus::Succeeded) 

enum class EInventoryOperationStatus : uint8;
template<> struct TIsUEnumClass<EInventoryOperationStatus> { enum { Value = true }; };
template<> PACKSYSTEMPLUGIN_API UEnum* StaticEnum<EInventoryOperationStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
