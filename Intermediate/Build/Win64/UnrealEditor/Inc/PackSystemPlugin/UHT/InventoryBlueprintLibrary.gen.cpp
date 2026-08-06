// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/InventoryBlueprintLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryBlueprintLibrary() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryBlueprintLibrary();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryBlueprintLibrary_NoRegister();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin Class UInventoryBlueprintLibrary Function CanStackItems
struct Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics
{
	struct InventoryBlueprintLibrary_eventCanStackItems_Parms
	{
		const UInventoryItemInstance* ItemA;
		const UInventoryItemInstance* ItemB;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns whether two item instances can be stored in the same stack. */" },
#endif
		{ "DisplayName", "Can Stack Items" },
		{ "ModuleRelativePath", "Public/InventoryBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns whether two item instances can be stored in the same stack." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemA_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemB_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemA;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemB;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::NewProp_ItemA = { "ItemA", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryBlueprintLibrary_eventCanStackItems_Parms, ItemA), Z_Construct_UClass_UInventoryItemInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemA_MetaData), NewProp_ItemA_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::NewProp_ItemB = { "ItemB", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryBlueprintLibrary_eventCanStackItems_Parms, ItemB), Z_Construct_UClass_UInventoryItemInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemB_MetaData), NewProp_ItemB_MetaData) };
void Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryBlueprintLibrary_eventCanStackItems_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryBlueprintLibrary_eventCanStackItems_Parms), &Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::NewProp_ItemA,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::NewProp_ItemB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryBlueprintLibrary, nullptr, "CanStackItems", nullptr, nullptr, Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::PropPointers), sizeof(Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::InventoryBlueprintLibrary_eventCanStackItems_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::InventoryBlueprintLibrary_eventCanStackItems_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryBlueprintLibrary::execCanStackItems)
{
	P_GET_OBJECT(UInventoryItemInstance,Z_Param_ItemA);
	P_GET_OBJECT(UInventoryItemInstance,Z_Param_ItemB);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UInventoryBlueprintLibrary::CanStackItems(Z_Param_ItemA,Z_Param_ItemB);
	P_NATIVE_END;
}
// End Class UInventoryBlueprintLibrary Function CanStackItems

// Begin Class UInventoryBlueprintLibrary
void UInventoryBlueprintLibrary::StaticRegisterNativesUInventoryBlueprintLibrary()
{
	UClass* Class = UInventoryBlueprintLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CanStackItems", &UInventoryBlueprintLibrary::execCanStackItems },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInventoryBlueprintLibrary);
UClass* Z_Construct_UClass_UInventoryBlueprintLibrary_NoRegister()
{
	return UInventoryBlueprintLibrary::StaticClass();
}
struct Z_Construct_UClass_UInventoryBlueprintLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Stateless helper functions shared by inventory Blueprints.\n */" },
#endif
		{ "IncludePath", "InventoryBlueprintLibrary.h" },
		{ "ModuleRelativePath", "Public/InventoryBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stateless helper functions shared by inventory Blueprints." },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryBlueprintLibrary_CanStackItems, "CanStackItems" }, // 1150139341
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryBlueprintLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UInventoryBlueprintLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryBlueprintLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryBlueprintLibrary_Statics::ClassParams = {
	&UInventoryBlueprintLibrary::StaticClass,
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
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryBlueprintLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryBlueprintLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UInventoryBlueprintLibrary()
{
	if (!Z_Registration_Info_UClass_UInventoryBlueprintLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryBlueprintLibrary.OuterSingleton, Z_Construct_UClass_UInventoryBlueprintLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryBlueprintLibrary.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UClass* StaticClass<UInventoryBlueprintLibrary>()
{
	return UInventoryBlueprintLibrary::StaticClass();
}
UInventoryBlueprintLibrary::UInventoryBlueprintLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryBlueprintLibrary);
UInventoryBlueprintLibrary::~UInventoryBlueprintLibrary() {}
// End Class UInventoryBlueprintLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryBlueprintLibrary_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryBlueprintLibrary, UInventoryBlueprintLibrary::StaticClass, TEXT("UInventoryBlueprintLibrary"), &Z_Registration_Info_UClass_UInventoryBlueprintLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryBlueprintLibrary), 2162515388U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryBlueprintLibrary_h_1075245725(TEXT("/Script/PackSystemPlugin"),
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryBlueprintLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryBlueprintLibrary_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
