// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/Fragments/IconFragment.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIconFragment() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UIconFragment();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UIconFragment_NoRegister();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemFragment();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin Class UIconFragment
void UIconFragment::StaticRegisterNativesUIconFragment()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UIconFragment);
UClass* Z_Construct_UClass_UIconFragment_NoRegister()
{
	return UIconFragment::StaticClass();
}
struct Z_Construct_UClass_UIconFragment_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xe4\xb8\xba\xe7\x89\xa9\xe5\x93\x81\xe6\x8f\x90\xe4\xbe\x9b UI \xe5\x9b\xbe\xe6\xa0\x87\xe7\x9a\x84\xe9\x85\x8d\xe7\xbd\xae\xe7\x89\x87\xe6\xae\xb5\xe3\x80\x82\n *\n * \xe8\xbf\x99\xe9\x87\x8c\xe6\x98\xbe\xe5\xbc\x8f\xe5\xa3\xb0\xe6\x98\x8e EditInlineNew\xef\xbc\x8c\xe7\xa1\xae\xe4\xbf\x9d\xe8\xaf\xa5\xe5\x85\xb7\xe4\xbd\x93\xe7\xb1\xbb\xe4\xbc\x9a\xe5\x87\xba\xe7\x8e\xb0\xe5\x9c\xa8 Instanced Fragment \xe6\x95\xb0\xe7\xbb\x84\xe7\x9a\x84\n * \xe2\x80\x9c\xe6\x96\xb0\xe5\xbb\xba\xe2\x80\x9d\xe7\xb1\xbb\xe5\x9e\x8b\xe8\x8f\x9c\xe5\x8d\x95\xe4\xb8\xad\xef\xbc\x9b\xe4\xbb\x85\xe6\x9c\x89 BlueprintType \xe5\xb9\xb6\xe4\xb8\x8d\xe8\xb6\xb3\xe4\xbb\xa5\xe4\xbf\x9d\xe8\xaf\x81\xe5\x8f\xaf\xe4\xbd\x9c\xe4\xb8\xba\xe5\x86\x85\xe8\x81\x94\xe5\xad\x90\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x88\x9b\xe5\xbb\xba\xe3\x80\x82\n */" },
#endif
		{ "IncludePath", "Fragments/IconFragment.h" },
		{ "ModuleRelativePath", "Public/Fragments/IconFragment.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xb8\xba\xe7\x89\xa9\xe5\x93\x81\xe6\x8f\x90\xe4\xbe\x9b UI \xe5\x9b\xbe\xe6\xa0\x87\xe7\x9a\x84\xe9\x85\x8d\xe7\xbd\xae\xe7\x89\x87\xe6\xae\xb5\xe3\x80\x82\n\n\xe8\xbf\x99\xe9\x87\x8c\xe6\x98\xbe\xe5\xbc\x8f\xe5\xa3\xb0\xe6\x98\x8e EditInlineNew\xef\xbc\x8c\xe7\xa1\xae\xe4\xbf\x9d\xe8\xaf\xa5\xe5\x85\xb7\xe4\xbd\x93\xe7\xb1\xbb\xe4\xbc\x9a\xe5\x87\xba\xe7\x8e\xb0\xe5\x9c\xa8 Instanced Fragment \xe6\x95\xb0\xe7\xbb\x84\xe7\x9a\x84\n\xe2\x80\x9c\xe6\x96\xb0\xe5\xbb\xba\xe2\x80\x9d\xe7\xb1\xbb\xe5\x9e\x8b\xe8\x8f\x9c\xe5\x8d\x95\xe4\xb8\xad\xef\xbc\x9b\xe4\xbb\x85\xe6\x9c\x89 BlueprintType \xe5\xb9\xb6\xe4\xb8\x8d\xe8\xb6\xb3\xe4\xbb\xa5\xe4\xbf\x9d\xe8\xaf\x81\xe5\x8f\xaf\xe4\xbd\x9c\xe4\xb8\xba\xe5\x86\x85\xe8\x81\x94\xe5\xad\x90\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x88\x9b\xe5\xbb\xba\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[] = {
		{ "Category", "Inventory|Icon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xaf\xe5\xbc\x95\xe7\x94\xa8\xe5\x9b\xbe\xe6\xa0\x87\xef\xbc\x8c\xe6\x89\x93\xe5\xbc\x80\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9a\xe4\xb9\x89\xe8\xb5\x84\xe4\xba\xa7\xe6\x97\xb6\xe4\xb8\x8d\xe4\xbc\x9a\xe5\xbc\xba\xe5\x88\xb6\xe5\x8a\xa0\xe8\xbd\xbd\xe7\xba\xb9\xe7\x90\x86\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Fragments/IconFragment.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xaf\xe5\xbc\x95\xe7\x94\xa8\xe5\x9b\xbe\xe6\xa0\x87\xef\xbc\x8c\xe6\x89\x93\xe5\xbc\x80\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9a\xe4\xb9\x89\xe8\xb5\x84\xe4\xba\xa7\xe6\x97\xb6\xe4\xb8\x8d\xe4\xbc\x9a\xe5\xbc\xba\xe5\x88\xb6\xe5\x8a\xa0\xe8\xbd\xbd\xe7\xba\xb9\xe7\x90\x86\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Icon;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UIconFragment>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UIconFragment_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UIconFragment, Icon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Icon_MetaData), NewProp_Icon_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UIconFragment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIconFragment_Statics::NewProp_Icon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UIconFragment_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UIconFragment_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInventoryItemFragment,
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UIconFragment_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UIconFragment_Statics::ClassParams = {
	&UIconFragment::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UIconFragment_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UIconFragment_Statics::PropPointers),
	0,
	0x003010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UIconFragment_Statics::Class_MetaDataParams), Z_Construct_UClass_UIconFragment_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UIconFragment()
{
	if (!Z_Registration_Info_UClass_UIconFragment.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UIconFragment.OuterSingleton, Z_Construct_UClass_UIconFragment_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UIconFragment.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UClass* StaticClass<UIconFragment>()
{
	return UIconFragment::StaticClass();
}
UIconFragment::UIconFragment(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UIconFragment);
UIconFragment::~UIconFragment() {}
// End Class UIconFragment

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Fragments_IconFragment_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UIconFragment, UIconFragment::StaticClass, TEXT("UIconFragment"), &Z_Registration_Info_UClass_UIconFragment, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UIconFragment), 995105999U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Fragments_IconFragment_h_2646682057(TEXT("/Script/PackSystemPlugin"),
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Fragments_IconFragment_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Fragments_IconFragment_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
