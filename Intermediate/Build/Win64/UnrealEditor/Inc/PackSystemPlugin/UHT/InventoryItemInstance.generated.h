// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Item/InventoryItemInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UInventoryItemDefinition;
class UInventoryItemFragment;
struct FGameplayTag;
#ifdef PACKSYSTEMPLUGIN_InventoryItemInstance_generated_h
#error "InventoryItemInstance.generated.h already included, missing '#pragma once' in InventoryItemInstance.h"
#endif
#define PACKSYSTEMPLUGIN_InventoryItemInstance_generated_h

#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemInstance_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRemoveInstanceTag); \
	DECLARE_FUNCTION(execAddInstanceTag); \
	DECLARE_FUNCTION(execFindFragmentByClass); \
	DECLARE_FUNCTION(execGetItemDefinition);


#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemInstance_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryItemInstance(); \
	friend struct Z_Construct_UClass_UInventoryItemInstance_Statics; \
public: \
	DECLARE_CLASS(UInventoryItemInstance, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PackSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(UInventoryItemInstance) \
	virtual UObject* _getUObject() const override { return const_cast<UInventoryItemInstance*>(this); }


#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemInstance_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryItemInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UInventoryItemInstance(UInventoryItemInstance&&); \
	UInventoryItemInstance(const UInventoryItemInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryItemInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryItemInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryItemInstance) \
	NO_API virtual ~UInventoryItemInstance();


#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemInstance_h_17_PROLOG
#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemInstance_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemInstance_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemInstance_h_20_INCLASS_NO_PURE_DECLS \
	FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemInstance_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PACKSYSTEMPLUGIN_API UClass* StaticClass<class UInventoryItemInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
