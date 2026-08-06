// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Strategy/AggregatedStorageStrategy.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PACKSYSTEMPLUGIN_AggregatedStorageStrategy_generated_h
#error "AggregatedStorageStrategy.generated.h already included, missing '#pragma once' in AggregatedStorageStrategy.h"
#endif
#define PACKSYSTEMPLUGIN_AggregatedStorageStrategy_generated_h

#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_AggregatedStorageStrategy_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAggregatedStorageStrategy(); \
	friend struct Z_Construct_UClass_UAggregatedStorageStrategy_Statics; \
public: \
	DECLARE_CLASS(UAggregatedStorageStrategy, UInventoryStorageStrategy, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PackSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(UAggregatedStorageStrategy)


#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_AggregatedStorageStrategy_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAggregatedStorageStrategy(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UAggregatedStorageStrategy(UAggregatedStorageStrategy&&); \
	UAggregatedStorageStrategy(const UAggregatedStorageStrategy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAggregatedStorageStrategy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAggregatedStorageStrategy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UAggregatedStorageStrategy) \
	NO_API virtual ~UAggregatedStorageStrategy();


#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_AggregatedStorageStrategy_h_12_PROLOG
#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_AggregatedStorageStrategy_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_AggregatedStorageStrategy_h_15_INCLASS_NO_PURE_DECLS \
	FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_AggregatedStorageStrategy_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PACKSYSTEMPLUGIN_API UClass* StaticClass<class UAggregatedStorageStrategy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_AggregatedStorageStrategy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
