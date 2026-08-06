// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/InventoryEntryArray.h"
#include "PackSystemPlugin/Public/InventoryEntry.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryEntryArray() {}

// Begin Cross Module References
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
PACKSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryEntry();
PACKSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryEntryArray();
PACKSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryEntryHandle();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin ScriptStruct FInventoryEntryArray
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_InventoryEntryArray;
class UScriptStruct* FInventoryEntryArray::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryEntryArray.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_InventoryEntryArray.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventoryEntryArray, (UObject*)Z_Construct_UPackage__Script_PackSystemPlugin(), TEXT("InventoryEntryArray"));
	}
	return Z_Registration_Info_UScriptStruct_InventoryEntryArray.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UScriptStruct* StaticStruct<FInventoryEntryArray>()
{
	return FInventoryEntryArray::StaticStruct();
}
struct Z_Construct_UScriptStruct_FInventoryEntryArray_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/InventoryEntryArray.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemEntries_MetaData[] = {
		{ "Category", "InventoryEntryArray" },
		{ "ModuleRelativePath", "Public/InventoryEntryArray.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InventoryEntryArray.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemEntries_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ItemEntries;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventoryEntryArray>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::NewProp_ItemEntries_Inner = { "ItemEntries", nullptr, (EPropertyFlags)0x0000008000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FInventoryEntry, METADATA_PARAMS(0, nullptr) }; // 3483008653
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::NewProp_ItemEntries = { "ItemEntries", nullptr, (EPropertyFlags)0x0010008000020801, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryEntryArray, ItemEntries), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemEntries_MetaData), NewProp_ItemEntries_MetaData) }; // 3483008653
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::NewProp_InventoryComponent = { "InventoryComponent", nullptr, (EPropertyFlags)0x0114000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryEntryArray, InventoryComponent), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryComponent_MetaData), NewProp_InventoryComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::NewProp_ItemEntries_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::NewProp_ItemEntries,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::NewProp_InventoryComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
	nullptr,
	&NewStructOps,
	"InventoryEntryArray",
	Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::PropPointers),
	sizeof(FInventoryEntryArray),
	alignof(FInventoryEntryArray),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FInventoryEntryArray()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryEntryArray.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_InventoryEntryArray.InnerSingleton, Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_InventoryEntryArray.InnerSingleton;
}
// End ScriptStruct FInventoryEntryArray

// Begin ScriptStruct FInventoryEntryHandle
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_InventoryEntryHandle;
class UScriptStruct* FInventoryEntryHandle::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryEntryHandle.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_InventoryEntryHandle.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventoryEntryHandle, (UObject*)Z_Construct_UPackage__Script_PackSystemPlugin(), TEXT("InventoryEntryHandle"));
	}
	return Z_Registration_Info_UScriptStruct_InventoryEntryHandle.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UScriptStruct* StaticStruct<FInventoryEntryHandle>()
{
	return FInventoryEntryHandle::StaticStruct();
}
struct Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/InventoryEntryArray.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntryID_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/InventoryEntryArray.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentInventory_MetaData[] = {
		{ "Category", "Inventory" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InventoryEntryArray.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_EntryID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ParentInventory;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventoryEntryHandle>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics::NewProp_EntryID = { "EntryID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryEntryHandle, EntryID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntryID_MetaData), NewProp_EntryID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics::NewProp_ParentInventory = { "ParentInventory", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryEntryHandle, ParentInventory), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentInventory_MetaData), NewProp_ParentInventory_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics::NewProp_EntryID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics::NewProp_ParentInventory,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
	nullptr,
	&NewStructOps,
	"InventoryEntryHandle",
	Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics::PropPointers),
	sizeof(FInventoryEntryHandle),
	alignof(FInventoryEntryHandle),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FInventoryEntryHandle()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryEntryHandle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_InventoryEntryHandle.InnerSingleton, Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_InventoryEntryHandle.InnerSingleton;
}
// End ScriptStruct FInventoryEntryHandle

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryEntryArray_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FInventoryEntryArray::StaticStruct, Z_Construct_UScriptStruct_FInventoryEntryArray_Statics::NewStructOps, TEXT("InventoryEntryArray"), &Z_Registration_Info_UScriptStruct_InventoryEntryArray, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInventoryEntryArray), 37586296U) },
		{ FInventoryEntryHandle::StaticStruct, Z_Construct_UScriptStruct_FInventoryEntryHandle_Statics::NewStructOps, TEXT("InventoryEntryHandle"), &Z_Registration_Info_UScriptStruct_InventoryEntryHandle, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInventoryEntryHandle), 3909057280U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryEntryArray_h_2989080267(TEXT("/Script/PackSystemPlugin"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryEntryArray_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryEntryArray_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
