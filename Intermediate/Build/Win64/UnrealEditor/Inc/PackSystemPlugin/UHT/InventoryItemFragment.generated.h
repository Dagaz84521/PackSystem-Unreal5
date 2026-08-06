// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Item/InventoryItemFragment.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UInventoryItemInstance;
#ifdef PACKSYSTEMPLUGIN_InventoryItemFragment_generated_h
#error "InventoryItemFragment.generated.h already included, missing '#pragma once' in InventoryItemFragment.h"
#endif
#define PACKSYSTEMPLUGIN_InventoryItemFragment_generated_h

#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnInstanceCreated);


#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_21_CALLBACK_WRAPPERS
#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryItemFragment(); \
	friend struct Z_Construct_UClass_UInventoryItemFragment_Statics; \
public: \
	DECLARE_CLASS(UInventoryItemFragment, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/PackSystemPlugin"), NO_API) \
	DECLARE_SERIALIZER(UInventoryItemFragment)


#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryItemFragment(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UInventoryItemFragment(UInventoryItemFragment&&); \
	UInventoryItemFragment(const UInventoryItemFragment&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryItemFragment); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryItemFragment); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryItemFragment) \
	NO_API virtual ~UInventoryItemFragment();


#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_18_PROLOG
#define FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_21_CALLBACK_WRAPPERS \
	FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_21_INCLASS_NO_PURE_DECLS \
	FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PACKSYSTEMPLUGIN_API UClass* StaticClass<class UInventoryItemFragment>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
