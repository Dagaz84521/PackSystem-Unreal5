// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Strategy/SlottedStorageStrategy.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PACKSYSTEMPLUGIN_SlottedStorageStrategy_generated_h
#error "SlottedStorageStrategy.generated.h already included, missing '#pragma once' in SlottedStorageStrategy.h"
#endif
#define PACKSYSTEMPLUGIN_SlottedStorageStrategy_generated_h

#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_SlottedStorageStrategy_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlottedStorageStrategy(); \
	friend struct Z_Construct_UClass_USlottedStorageStrategy_Statics; \
public: \
	DECLARE_CLASS(USlottedStorageStrategy, UInventoryStorageStrategy, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PackSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(USlottedStorageStrategy)


#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_SlottedStorageStrategy_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlottedStorageStrategy(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	USlottedStorageStrategy(USlottedStorageStrategy&&); \
	USlottedStorageStrategy(const USlottedStorageStrategy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlottedStorageStrategy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlottedStorageStrategy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USlottedStorageStrategy) \
	NO_API virtual ~USlottedStorageStrategy();


#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_SlottedStorageStrategy_h_12_PROLOG
#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_SlottedStorageStrategy_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_SlottedStorageStrategy_h_15_INCLASS_NO_PURE_DECLS \
	FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_SlottedStorageStrategy_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PACKSYSTEMPLUGIN_API UClass* StaticClass<class USlottedStorageStrategy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_SlottedStorageStrategy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
