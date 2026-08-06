// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/Item/InventoryItemFragment.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryItemFragment() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemFragment();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemFragment_NoRegister();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin Class UInventoryItemFragment Function OnInstanceCreated
struct InventoryItemFragment_eventOnInstanceCreated_Parms
{
	UInventoryItemInstance* Instance;
};
static FName NAME_UInventoryItemFragment_OnInstanceCreated = FName(TEXT("OnInstanceCreated"));
void UInventoryItemFragment::OnInstanceCreated(UInventoryItemInstance* Instance) const
{
	InventoryItemFragment_eventOnInstanceCreated_Parms Parms;
	Parms.Instance=Instance;
	const_cast<UInventoryItemFragment*>(this)->ProcessEvent(FindFunctionChecked(NAME_UInventoryItemFragment_OnInstanceCreated),&Parms);
}
struct Z_Construct_UFunction_UInventoryItemFragment_OnInstanceCreated_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Fragment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \xe5\xbd\x93\xe5\xae\x9a\xe4\xb9\x89\xe5\x88\x9b\xe5\xbb\xba\xe5\x87\xba\xe4\xb8\x80\xe4\xb8\xaa\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9e\xe4\xbe\x8b\xe5\x90\x8e\xe8\xb0\x83\xe7\x94\xa8\xe3\x80\x82\n\x09 * \xe6\xb4\xbe\xe7\x94\x9f Fragment \xe5\x8f\xaf\xe5\x9c\xa8\xe6\xad\xa4\xe5\x90\x91\xe5\xae\x9e\xe4\xbe\x8b\xe5\x86\x99\xe5\x85\xa5\xe5\x88\x9d\xe5\xa7\x8b\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x9b\xe8\x93\x9d\xe5\x9b\xbe Fragment \xe4\xb9\x9f\xe5\x8f\xaf\xe4\xbb\xa5\xe8\xa6\x86\xe5\x86\x99\xe8\xaf\xa5\xe4\xba\x8b\xe4\xbb\xb6\xe3\x80\x82\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/Item/InventoryItemFragment.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xbd\x93\xe5\xae\x9a\xe4\xb9\x89\xe5\x88\x9b\xe5\xbb\xba\xe5\x87\xba\xe4\xb8\x80\xe4\xb8\xaa\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9e\xe4\xbe\x8b\xe5\x90\x8e\xe8\xb0\x83\xe7\x94\xa8\xe3\x80\x82\n\xe6\xb4\xbe\xe7\x94\x9f Fragment \xe5\x8f\xaf\xe5\x9c\xa8\xe6\xad\xa4\xe5\x90\x91\xe5\xae\x9e\xe4\xbe\x8b\xe5\x86\x99\xe5\x85\xa5\xe5\x88\x9d\xe5\xa7\x8b\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x9b\xe8\x93\x9d\xe5\x9b\xbe Fragment \xe4\xb9\x9f\xe5\x8f\xaf\xe4\xbb\xa5\xe8\xa6\x86\xe5\x86\x99\xe8\xaf\xa5\xe4\xba\x8b\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Instance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemFragment_OnInstanceCreated_Statics::NewProp_Instance = { "Instance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemFragment_eventOnInstanceCreated_Parms, Instance), Z_Construct_UClass_UInventoryItemInstance_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemFragment_OnInstanceCreated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemFragment_OnInstanceCreated_Statics::NewProp_Instance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemFragment_OnInstanceCreated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemFragment_OnInstanceCreated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryItemFragment, nullptr, "OnInstanceCreated", nullptr, nullptr, Z_Construct_UFunction_UInventoryItemFragment_OnInstanceCreated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemFragment_OnInstanceCreated_Statics::PropPointers), sizeof(InventoryItemFragment_eventOnInstanceCreated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemFragment_OnInstanceCreated_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemFragment_OnInstanceCreated_Statics::Function_MetaDataParams) };
static_assert(sizeof(InventoryItemFragment_eventOnInstanceCreated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemFragment_OnInstanceCreated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemFragment_OnInstanceCreated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemFragment::execOnInstanceCreated)
{
	P_GET_OBJECT(UInventoryItemInstance,Z_Param_Instance);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnInstanceCreated_Implementation(Z_Param_Instance);
	P_NATIVE_END;
}
// End Class UInventoryItemFragment Function OnInstanceCreated

// Begin Class UInventoryItemFragment
void UInventoryItemFragment::StaticRegisterNativesUInventoryItemFragment()
{
	UClass* Class = UInventoryItemFragment::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnInstanceCreated", &UInventoryItemFragment::execOnInstanceCreated },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInventoryItemFragment);
UClass* Z_Construct_UClass_UInventoryItemFragment_NoRegister()
{
	return UInventoryItemFragment::StaticClass();
}
struct Z_Construct_UClass_UInventoryItemFragment_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xe7\x89\xa9\xe5\x93\x81\xe7\x89\x87\xe6\xae\xb5\xe5\x9f\xba\xe7\xb1\xbb\xe3\x80\x82\n *\n * Fragment \xe7\x94\xa8\xe4\xba\x8e\xe6\x8a\x8a\xe4\xb8\x80\xe4\xb8\xaa\xe7\x89\xa9\xe5\x93\x81\xe7\x9a\x84\xe9\x85\x8d\xe7\xbd\xae\xe6\x8b\x86\xe5\x88\x86\xe6\x88\x90\xe5\xa4\x9a\xe4\xb8\xaa\xe5\x8f\xaf\xe5\xa4\x8d\xe7\x94\xa8\xe7\x9a\x84\xe5\xb0\x8f\xe6\xa8\xa1\xe5\x9d\x97\xef\xbc\x8c\xe4\xbe\x8b\xe5\xa6\x82\xe5\x9b\xbe\xe6\xa0\x87\xe3\x80\x81\xe9\x87\x8d\xe9\x87\x8f\xe3\x80\x81\n * \xe8\xa3\x85\xe5\xa4\x87\xe4\xbf\xa1\xe6\x81\xaf\xe7\xad\x89\xe3\x80\x82""DefaultToInstanced \xe4\xb8\x8e EditInlineNew \xe5\x85\x81\xe8\xae\xb8\xe6\xb4\xbe\xe7\x94\x9f\xe7\xb1\xbb\xe4\xbb\xa5\xe5\x86\x85\xe8\x81\x94\xe5\xad\x90\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x9a\x84\xe5\xbd\xa2\xe5\xbc\x8f\n * \xe7\x9b\xb4\xe6\x8e\xa5\xe6\xb7\xbb\xe5\x8a\xa0\xe5\x88\xb0 UInventoryItemDefinition \xe7\x9a\x84 Fragments \xe6\x95\xb0\xe7\xbb\x84\xe4\xb8\xad\xe3\x80\x82\n */" },
#endif
		{ "IncludePath", "Item/InventoryItemFragment.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Item/InventoryItemFragment.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\x89\xa9\xe5\x93\x81\xe7\x89\x87\xe6\xae\xb5\xe5\x9f\xba\xe7\xb1\xbb\xe3\x80\x82\n\nFragment \xe7\x94\xa8\xe4\xba\x8e\xe6\x8a\x8a\xe4\xb8\x80\xe4\xb8\xaa\xe7\x89\xa9\xe5\x93\x81\xe7\x9a\x84\xe9\x85\x8d\xe7\xbd\xae\xe6\x8b\x86\xe5\x88\x86\xe6\x88\x90\xe5\xa4\x9a\xe4\xb8\xaa\xe5\x8f\xaf\xe5\xa4\x8d\xe7\x94\xa8\xe7\x9a\x84\xe5\xb0\x8f\xe6\xa8\xa1\xe5\x9d\x97\xef\xbc\x8c\xe4\xbe\x8b\xe5\xa6\x82\xe5\x9b\xbe\xe6\xa0\x87\xe3\x80\x81\xe9\x87\x8d\xe9\x87\x8f\xe3\x80\x81\n\xe8\xa3\x85\xe5\xa4\x87\xe4\xbf\xa1\xe6\x81\xaf\xe7\xad\x89\xe3\x80\x82""DefaultToInstanced \xe4\xb8\x8e EditInlineNew \xe5\x85\x81\xe8\xae\xb8\xe6\xb4\xbe\xe7\x94\x9f\xe7\xb1\xbb\xe4\xbb\xa5\xe5\x86\x85\xe8\x81\x94\xe5\xad\x90\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x9a\x84\xe5\xbd\xa2\xe5\xbc\x8f\n\xe7\x9b\xb4\xe6\x8e\xa5\xe6\xb7\xbb\xe5\x8a\xa0\xe5\x88\xb0 UInventoryItemDefinition \xe7\x9a\x84 Fragments \xe6\x95\xb0\xe7\xbb\x84\xe4\xb8\xad\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryItemFragment_OnInstanceCreated, "OnInstanceCreated" }, // 2779319704
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryItemFragment>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UInventoryItemFragment_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemFragment_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryItemFragment_Statics::ClassParams = {
	&UInventoryItemFragment::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x003010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemFragment_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryItemFragment_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UInventoryItemFragment()
{
	if (!Z_Registration_Info_UClass_UInventoryItemFragment.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryItemFragment.OuterSingleton, Z_Construct_UClass_UInventoryItemFragment_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryItemFragment.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UClass* StaticClass<UInventoryItemFragment>()
{
	return UInventoryItemFragment::StaticClass();
}
UInventoryItemFragment::UInventoryItemFragment(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryItemFragment);
UInventoryItemFragment::~UInventoryItemFragment() {}
// End Class UInventoryItemFragment

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryItemFragment, UInventoryItemFragment::StaticClass, TEXT("UInventoryItemFragment"), &Z_Registration_Info_UClass_UInventoryItemFragment, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryItemFragment), 4050336197U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_1432696622(TEXT("/Script/PackSystemPlugin"),
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemFragment_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
