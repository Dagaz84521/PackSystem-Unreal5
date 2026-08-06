// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/Strategy/SlottedStorageStrategy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSlottedStorageStrategy() {}

// Begin Cross Module References
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryStorageStrategy();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_USlottedStorageStrategy();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_USlottedStorageStrategy_NoRegister();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin Class USlottedStorageStrategy
void USlottedStorageStrategy::StaticRegisterNativesUSlottedStorageStrategy()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USlottedStorageStrategy);
UClass* Z_Construct_UClass_USlottedStorageStrategy_NoRegister()
{
	return USlottedStorageStrategy::StaticClass();
}
struct Z_Construct_UClass_USlottedStorageStrategy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Strategy/SlottedStorageStrategy.h" },
		{ "ModuleRelativePath", "Public/Strategy/SlottedStorageStrategy.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlottedStorageStrategy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_USlottedStorageStrategy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInventoryStorageStrategy,
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USlottedStorageStrategy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USlottedStorageStrategy_Statics::ClassParams = {
	&USlottedStorageStrategy::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USlottedStorageStrategy_Statics::Class_MetaDataParams), Z_Construct_UClass_USlottedStorageStrategy_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USlottedStorageStrategy()
{
	if (!Z_Registration_Info_UClass_USlottedStorageStrategy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlottedStorageStrategy.OuterSingleton, Z_Construct_UClass_USlottedStorageStrategy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USlottedStorageStrategy.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UClass* StaticClass<USlottedStorageStrategy>()
{
	return USlottedStorageStrategy::StaticClass();
}
USlottedStorageStrategy::USlottedStorageStrategy() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(USlottedStorageStrategy);
USlottedStorageStrategy::~USlottedStorageStrategy() {}
// End Class USlottedStorageStrategy

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_SlottedStorageStrategy_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USlottedStorageStrategy, USlottedStorageStrategy::StaticClass, TEXT("USlottedStorageStrategy"), &Z_Registration_Info_UClass_USlottedStorageStrategy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlottedStorageStrategy), 1144469092U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_SlottedStorageStrategy_h_59130678(TEXT("/Script/PackSystemPlugin"),
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_SlottedStorageStrategy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Strategy_SlottedStorageStrategy_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
