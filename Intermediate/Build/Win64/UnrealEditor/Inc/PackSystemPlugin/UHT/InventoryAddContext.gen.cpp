// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/InventoryAddContext.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryAddContext() {}

// Begin Cross Module References
PACKSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryAddContext();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin ScriptStruct FInventoryAddContext
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_InventoryAddContext;
class UScriptStruct* FInventoryAddContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryAddContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_InventoryAddContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventoryAddContext, (UObject*)Z_Construct_UPackage__Script_PackSystemPlugin(), TEXT("InventoryAddContext"));
	}
	return Z_Registration_Info_UScriptStruct_InventoryAddContext.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UScriptStruct* StaticStruct<FInventoryAddContext>()
{
	return FInventoryAddContext::StaticStruct();
}
struct Z_Construct_UScriptStruct_FInventoryAddContext_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xe4\xb8\x80\xe6\xac\xa1\xe6\xb7\xbb\xe5\x8a\xa0\xe6\x93\x8d\xe4\xbd\x9c\xe6\x89\x80\xe6\x90\xba\xe5\xb8\xa6\xe7\x9a\x84\xe7\xad\x96\xe7\x95\xa5\xe7\x9b\xb8\xe5\x85\xb3\xe6\x95\xb0\xe6\x8d\xae\xe3\x80\x82\n *\n * \xe6\xb4\xbe\xe7\x94\x9f USTRUCT \xe5\x8f\xaa\xe8\xb4\x9f\xe8\xb4\xa3\xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x9b\xe7\x89\xa9\xe5\x93\x81\xe7\x9a\x84\xe6\x94\xbe\xe7\xbd\xae\xe8\xa1\x8c\xe4\xb8\xba\xe4\xbb\x8d\xe7\x94\xb1\n * UInventoryStorageStrategy \xe5\xae\x9e\xe7\x8e\xb0\xe3\x80\x82\n */" },
#endif
		{ "ModuleRelativePath", "Public/InventoryAddContext.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xb8\x80\xe6\xac\xa1\xe6\xb7\xbb\xe5\x8a\xa0\xe6\x93\x8d\xe4\xbd\x9c\xe6\x89\x80\xe6\x90\xba\xe5\xb8\xa6\xe7\x9a\x84\xe7\xad\x96\xe7\x95\xa5\xe7\x9b\xb8\xe5\x85\xb3\xe6\x95\xb0\xe6\x8d\xae\xe3\x80\x82\n\n\xe6\xb4\xbe\xe7\x94\x9f USTRUCT \xe5\x8f\xaa\xe8\xb4\x9f\xe8\xb4\xa3\xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x9b\xe7\x89\xa9\xe5\x93\x81\xe7\x9a\x84\xe6\x94\xbe\xe7\xbd\xae\xe8\xa1\x8c\xe4\xb8\xba\xe4\xbb\x8d\xe7\x94\xb1\nUInventoryStorageStrategy \xe5\xae\x9e\xe7\x8e\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventoryAddContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventoryAddContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
	nullptr,
	&NewStructOps,
	"InventoryAddContext",
	nullptr,
	0,
	sizeof(FInventoryAddContext),
	alignof(FInventoryAddContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FInventoryAddContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FInventoryAddContext()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryAddContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_InventoryAddContext.InnerSingleton, Z_Construct_UScriptStruct_FInventoryAddContext_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_InventoryAddContext.InnerSingleton;
}
// End ScriptStruct FInventoryAddContext

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddContext_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FInventoryAddContext::StaticStruct, Z_Construct_UScriptStruct_FInventoryAddContext_Statics::NewStructOps, TEXT("InventoryAddContext"), &Z_Registration_Info_UScriptStruct_InventoryAddContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInventoryAddContext), 1099407468U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddContext_h_2714178465(TEXT("/Script/PackSystemPlugin"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddContext_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddContext_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
