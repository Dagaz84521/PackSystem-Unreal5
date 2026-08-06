// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/InventoryAddRequest.h"
#include "StructUtils/Public/InstancedStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryAddRequest() {}

// Begin Cross Module References
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemInstance_NoRegister();
PACKSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryAddRequest();
STRUCTUTILS_API UScriptStruct* Z_Construct_UScriptStruct_FInstancedStruct();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin ScriptStruct FInventoryAddRequest
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_InventoryAddRequest;
class UScriptStruct* FInventoryAddRequest::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryAddRequest.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_InventoryAddRequest.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventoryAddRequest, (UObject*)Z_Construct_UPackage__Script_PackSystemPlugin(), TEXT("InventoryAddRequest"));
	}
	return Z_Registration_Info_UScriptStruct_InventoryAddRequest.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UScriptStruct* StaticStruct<FInventoryAddRequest>()
{
	return FInventoryAddRequest::StaticStruct();
}
struct Z_Construct_UScriptStruct_FInventoryAddRequest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/InventoryAddRequest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryItemInstance_MetaData[] = {
		{ "Category", "InventoryAddRequest" },
		{ "ModuleRelativePath", "Public/InventoryAddRequest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "InventoryAddRequest" },
		{ "ModuleRelativePath", "Public/InventoryAddRequest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AddContext_MetaData[] = {
		{ "BaseStruct", "/Script/PackSystemPlugin.InventoryAddContext" },
		{ "Category", "InventoryAddRequest" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe5\xbd\x93\xe5\x89\x8d\xe5\xad\x98\xe5\x82\xa8\xe7\xad\x96\xe7\x95\xa5\xe6\x89\x80\xe9\x9c\x80\xe7\x9a\x84\xe9\x99\x84\xe5\x8a\xa0\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe4\xbe\x8b\xe5\xa6\x82\xe7\x9b\xae\xe6\xa0\x87 Entry \xe6\x88\x96\xe4\xba\x8c\xe7\xbb\xb4\xe7\xbd\x91\xe6\xa0\xbc\xe5\x9d\x90\xe6\xa0\x87\xe3\x80\x82\n" },
#endif
		{ "ModuleRelativePath", "Public/InventoryAddRequest.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe5\xad\x98\xe5\x82\xa8\xe7\xad\x96\xe7\x95\xa5\xe6\x89\x80\xe9\x9c\x80\xe7\x9a\x84\xe9\x99\x84\xe5\x8a\xa0\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe4\xbe\x8b\xe5\xa6\x82\xe7\x9b\xae\xe6\xa0\x87 Entry \xe6\x88\x96\xe4\xba\x8c\xe7\xbb\xb4\xe7\xbd\x91\xe6\xa0\xbc\xe5\x9d\x90\xe6\xa0\x87\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryItemInstance;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AddContext;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventoryAddRequest>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::NewProp_InventoryItemInstance = { "InventoryItemInstance", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddRequest, InventoryItemInstance), Z_Construct_UClass_UInventoryItemInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryItemInstance_MetaData), NewProp_InventoryItemInstance_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddRequest, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::NewProp_AddContext = { "AddContext", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddRequest, AddContext), Z_Construct_UScriptStruct_FInstancedStruct, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AddContext_MetaData), NewProp_AddContext_MetaData) }; // 174410355
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::NewProp_InventoryItemInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::NewProp_AddContext,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
	nullptr,
	&NewStructOps,
	"InventoryAddRequest",
	Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::PropPointers),
	sizeof(FInventoryAddRequest),
	alignof(FInventoryAddRequest),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FInventoryAddRequest()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryAddRequest.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_InventoryAddRequest.InnerSingleton, Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_InventoryAddRequest.InnerSingleton;
}
// End ScriptStruct FInventoryAddRequest

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddRequest_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FInventoryAddRequest::StaticStruct, Z_Construct_UScriptStruct_FInventoryAddRequest_Statics::NewStructOps, TEXT("InventoryAddRequest"), &Z_Registration_Info_UScriptStruct_InventoryAddRequest, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInventoryAddRequest), 2023228882U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddRequest_h_3846389782(TEXT("/Script/PackSystemPlugin"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddRequest_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddRequest_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
