// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/InventoryEntry.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryEntry() {}

// Begin Cross Module References
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemInstance_NoRegister();
PACKSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryEntry();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin ScriptStruct FInventoryEntry
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_InventoryEntry;
class UScriptStruct* FInventoryEntry::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryEntry.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_InventoryEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventoryEntry, (UObject*)Z_Construct_UPackage__Script_PackSystemPlugin(), TEXT("InventoryEntry"));
	}
	return Z_Registration_Info_UScriptStruct_InventoryEntry.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UScriptStruct* StaticStruct<FInventoryEntry>()
{
	return FInventoryEntry::StaticStruct();
}
struct Z_Construct_UScriptStruct_FInventoryEntry_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xe8\x83\x8c\xe5\x8c\x85\xe4\xb8\xad\xe7\x9a\x84\xe4\xb8\x80\xe6\x9d\xa1\xe5\xba\x93\xe5\xad\x98\xe8\xae\xb0\xe5\xbd\x95\xe3\x80\x82\n * \xe4\xbf\x9d\xe5\xad\x98\xe6\x9d\xa1\xe7\x9b\xae\xe6\xa0\x87\xe8\xaf\x86\xe3\x80\x81\xe6\x95\xb0\xe9\x87\x8f\xe4\xbb\xa5\xe5\x8f\x8a\xe8\xaf\xa5\xe6\x9d\xa1\xe7\x9b\xae\xe5\xbc\x95\xe7\x94\xa8\xe7\x9a\x84\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82\n */" },
#endif
		{ "ModuleRelativePath", "Public/InventoryEntry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x83\x8c\xe5\x8c\x85\xe4\xb8\xad\xe7\x9a\x84\xe4\xb8\x80\xe6\x9d\xa1\xe5\xba\x93\xe5\xad\x98\xe8\xae\xb0\xe5\xbd\x95\xe3\x80\x82\n\xe4\xbf\x9d\xe5\xad\x98\xe6\x9d\xa1\xe7\x9b\xae\xe6\xa0\x87\xe8\xaf\x86\xe3\x80\x81\xe6\x95\xb0\xe9\x87\x8f\xe4\xbb\xa5\xe5\x8f\x8a\xe8\xaf\xa5\xe6\x9d\xa1\xe7\x9b\xae\xe5\xbc\x95\xe7\x94\xa8\xe7\x9a\x84\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemInstance_MetaData[] = {
		{ "Category", "Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xbd\x93\xe5\x89\x8d\xe6\x9d\xa1\xe7\x9b\xae\xe5\xbc\x95\xe7\x94\xa8\xe7\x9a\x84\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x9b\xe4\xb8\xba\xe7\xa9\xba\xe8\xa1\xa8\xe7\xa4\xba\xe8\xaf\xa5\xe6\x9d\xa1\xe7\x9b\xae\xe6\xb2\xa1\xe6\x9c\x89\xe7\x89\xa9\xe5\x93\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/InventoryEntry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe6\x9d\xa1\xe7\x9b\xae\xe5\xbc\x95\xe7\x94\xa8\xe7\x9a\x84\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x9b\xe4\xb8\xba\xe7\xa9\xba\xe8\xa1\xa8\xe7\xa4\xba\xe8\xaf\xa5\xe6\x9d\xa1\xe7\x9b\xae\xe6\xb2\xa1\xe6\x9c\x89\xe7\x89\xa9\xe5\x93\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \xe5\xbd\x93\xe5\x89\x8d\xe6\x9d\xa1\xe7\x9b\xae\xe4\xb8\xad\xe7\x9a\x84\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82\n\x09 * \xe6\x95\xb0\xe9\x87\x8f\xe5\xb1\x9e\xe4\xba\x8e\xe5\xba\x93\xe5\xad\x98\xe6\x9d\xa1\xe7\x9b\xae\xe8\x80\x8c\xe4\xb8\x8d\xe6\x98\xaf\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x8c\xe5\x9b\xa0\xe4\xb8\xba\xe4\xb8\x8d\xe5\x90\x8c\xe5\xba\x93\xe5\xad\x98\xe7\xad\x96\xe7\x95\xa5\xe5\x8f\xaf\xe4\xbb\xa5\xe4\xb8\xba\xe5\x90\x8c\xe4\xb8\x80\xe7\x89\xa9\xe5\x93\x81\xe8\xae\xbe\xe7\xbd\xae\xe4\xb8\x8d\xe5\x90\x8c\xe7\x9a\x84\xe5\xae\xb9\xe9\x87\x8f\xe8\xa7\x84\xe5\x88\x99\xe3\x80\x82\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/InventoryEntry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe6\x9d\xa1\xe7\x9b\xae\xe4\xb8\xad\xe7\x9a\x84\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82\n\xe6\x95\xb0\xe9\x87\x8f\xe5\xb1\x9e\xe4\xba\x8e\xe5\xba\x93\xe5\xad\x98\xe6\x9d\xa1\xe7\x9b\xae\xe8\x80\x8c\xe4\xb8\x8d\xe6\x98\xaf\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9e\xe4\xbe\x8b\xef\xbc\x8c\xe5\x9b\xa0\xe4\xb8\xba\xe4\xb8\x8d\xe5\x90\x8c\xe5\xba\x93\xe5\xad\x98\xe7\xad\x96\xe7\x95\xa5\xe5\x8f\xaf\xe4\xbb\xa5\xe4\xb8\xba\xe5\x90\x8c\xe4\xb8\x80\xe7\x89\xa9\xe5\x93\x81\xe8\xae\xbe\xe7\xbd\xae\xe4\xb8\x8d\xe5\x90\x8c\xe7\x9a\x84\xe5\xae\xb9\xe9\x87\x8f\xe8\xa7\x84\xe5\x88\x99\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntryID_MetaData[] = {
		{ "Category", "Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9d\xa1\xe7\x9b\xae\xe6\xa0\x87\xe8\xaf\x86\xef\xbc\x9bINDEX_NONE \xe8\xa1\xa8\xe7\xa4\xba\xe5\xb0\x9a\xe6\x9c\xaa\xe5\x88\x86\xe9\x85\x8d\xe6\x9c\x89\xe6\x95\x88\xe6\xa0\x87\xe8\xaf\x86\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/InventoryEntry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9d\xa1\xe7\x9b\xae\xe6\xa0\x87\xe8\xaf\x86\xef\xbc\x9bINDEX_NONE \xe8\xa1\xa8\xe7\xa4\xba\xe5\xb0\x9a\xe6\x9c\xaa\xe5\x88\x86\xe9\x85\x8d\xe6\x9c\x89\xe6\x95\x88\xe6\xa0\x87\xe8\xaf\x86\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Owner_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8b\xa5\xe6\x9c\x89\xe8\xaf\xa5\xe6\x9d\xa1\xe7\x9b\xae\xe7\x9a\x84\xe8\x83\x8c\xe5\x8c\x85\xe7\xbb\x84\xe4\xbb\xb6\xef\xbc\x8c\xe4\xb8\x8d\xe5\x8f\x82\xe4\xb8\x8e\xe4\xbf\x9d\xe5\xad\x98\xe6\x88\x96\xe7\xbd\x91\xe7\xbb\x9c\xe5\xa4\x8d\xe5\x88\xb6\xe3\x80\x82 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InventoryEntry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8b\xa5\xe6\x9c\x89\xe8\xaf\xa5\xe6\x9d\xa1\xe7\x9b\xae\xe7\x9a\x84\xe8\x83\x8c\xe5\x8c\x85\xe7\xbb\x84\xe4\xbb\xb6\xef\xbc\x8c\xe4\xb8\x8d\xe5\x8f\x82\xe4\xb8\x8e\xe4\xbf\x9d\xe5\xad\x98\xe6\x88\x96\xe7\xbd\x91\xe7\xbb\x9c\xe5\xa4\x8d\xe5\x88\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemInstance;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FIntPropertyParams NewProp_EntryID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Owner;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventoryEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FInventoryEntry_Statics::NewProp_ItemInstance = { "ItemInstance", nullptr, (EPropertyFlags)0x0114000000020015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryEntry, ItemInstance), Z_Construct_UClass_UInventoryItemInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemInstance_MetaData), NewProp_ItemInstance_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FInventoryEntry_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryEntry, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FInventoryEntry_Statics::NewProp_EntryID = { "EntryID", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryEntry, EntryID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntryID_MetaData), NewProp_EntryID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FInventoryEntry_Statics::NewProp_Owner = { "Owner", nullptr, (EPropertyFlags)0x0124080080082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryEntry, Owner), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Owner_MetaData), NewProp_Owner_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventoryEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryEntry_Statics::NewProp_ItemInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryEntry_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryEntry_Statics::NewProp_EntryID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryEntry_Statics::NewProp_Owner,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryEntry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventoryEntry_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
	nullptr,
	&NewStructOps,
	"InventoryEntry",
	Z_Construct_UScriptStruct_FInventoryEntry_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryEntry_Statics::PropPointers),
	sizeof(FInventoryEntry),
	alignof(FInventoryEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryEntry_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FInventoryEntry_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FInventoryEntry()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_InventoryEntry.InnerSingleton, Z_Construct_UScriptStruct_FInventoryEntry_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_InventoryEntry.InnerSingleton;
}
// End ScriptStruct FInventoryEntry

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryEntry_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FInventoryEntry::StaticStruct, Z_Construct_UScriptStruct_FInventoryEntry_Statics::NewStructOps, TEXT("InventoryEntry"), &Z_Registration_Info_UScriptStruct_InventoryEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInventoryEntry), 3483008653U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryEntry_h_2037899376(TEXT("/Script/PackSystemPlugin"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryEntry_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryEntry_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
