// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/Strategy/AggregatedStorageStrategy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAggregatedStorageStrategy() {}

// Begin Cross Module References
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UAggregatedStorageStrategy();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UAggregatedStorageStrategy_NoRegister();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryStorageStrategy();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin Class UAggregatedStorageStrategy
void UAggregatedStorageStrategy::StaticRegisterNativesUAggregatedStorageStrategy()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAggregatedStorageStrategy);
UClass* Z_Construct_UClass_UAggregatedStorageStrategy_NoRegister()
{
	return UAggregatedStorageStrategy::StaticClass();
}
struct Z_Construct_UClass_UAggregatedStorageStrategy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Strategy/AggregatedStorageStrategy.h" },
		{ "ModuleRelativePath", "Public/Strategy/AggregatedStorageStrategy.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAggregatedStorageStrategy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAggregatedStorageStrategy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInventoryStorageStrategy,
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAggregatedStorageStrategy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAggregatedStorageStrategy_Statics::ClassParams = {
	&UAggregatedStorageStrategy::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x003010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAggregatedStorageStrategy_Statics::Class_MetaDataParams), Z_Construct_UClass_UAggregatedStorageStrategy_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAggregatedStorageStrategy()
{
	if (!Z_Registration_Info_UClass_UAggregatedStorageStrategy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAggregatedStorageStrategy.OuterSingleton, Z_Construct_UClass_UAggregatedStorageStrategy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAggregatedStorageStrategy.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UClass* StaticClass<UAggregatedStorageStrategy>()
{
	return UAggregatedStorageStrategy::StaticClass();
}
UAggregatedStorageStrategy::UAggregatedStorageStrategy() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAggregatedStorageStrategy);
UAggregatedStorageStrategy::~UAggregatedStorageStrategy() {}
// End Class UAggregatedStorageStrategy

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_AggregatedStorageStrategy_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAggregatedStorageStrategy, UAggregatedStorageStrategy::StaticClass, TEXT("UAggregatedStorageStrategy"), &Z_Registration_Info_UClass_UAggregatedStorageStrategy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAggregatedStorageStrategy), 2915472064U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_AggregatedStorageStrategy_h_1554597359(TEXT("/Script/PackSystemPlugin"),
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_AggregatedStorageStrategy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_AggregatedStorageStrategy_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
