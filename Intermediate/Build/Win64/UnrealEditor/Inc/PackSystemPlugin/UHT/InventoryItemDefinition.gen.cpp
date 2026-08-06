// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/Item/InventoryItemDefinition.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryItemDefinition() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
GAMEPLAYTAGS_API UClass* Z_Construct_UClass_UGameplayTagAssetInterface_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemDefinition();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemFragment_NoRegister();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin Class UInventoryItemDefinition Function CreateItemInstance
struct Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics
{
	struct InventoryItemDefinition_eventCreateItemInstance_Parms
	{
		UObject* Outer;
		UInventoryItemInstance* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\x9b\xe5\xbb\xba\xe5\xb9\xb6\xe5\x88\x9d\xe5\xa7\x8b\xe5\x8c\x96\xe4\xb8\x80\xe4\xb8\xaa\xe5\xbc\x95\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xae\x9a\xe4\xb9\x89\xe7\x9a\x84\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82 */" },
#endif
		{ "DefaultToSelf", "Outer" },
		{ "ModuleRelativePath", "Public/Item/InventoryItemDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\x9b\xe5\xbb\xba\xe5\xb9\xb6\xe5\x88\x9d\xe5\xa7\x8b\xe5\x8c\x96\xe4\xb8\x80\xe4\xb8\xaa\xe5\xbc\x95\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xae\x9a\xe4\xb9\x89\xe7\x9a\x84\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Outer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::NewProp_Outer = { "Outer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemDefinition_eventCreateItemInstance_Parms, Outer), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemDefinition_eventCreateItemInstance_Parms, ReturnValue), Z_Construct_UClass_UInventoryItemInstance_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::NewProp_Outer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryItemDefinition, nullptr, "CreateItemInstance", nullptr, nullptr, Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::PropPointers), sizeof(Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::InventoryItemDefinition_eventCreateItemInstance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::InventoryItemDefinition_eventCreateItemInstance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemDefinition::execCreateItemInstance)
{
	P_GET_OBJECT(UObject,Z_Param_Outer);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UInventoryItemInstance**)Z_Param__Result=P_THIS->CreateItemInstance(Z_Param_Outer);
	P_NATIVE_END;
}
// End Class UInventoryItemDefinition Function CreateItemInstance

// Begin Class UInventoryItemDefinition Function FindFragmentByClass
struct Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics
{
	struct InventoryItemDefinition_eventFindFragmentByClass_Parms
	{
		TSubclassOf<UInventoryItemFragment> FragmentClass;
		UInventoryItemFragment* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\xb9\xe6\x8d\xae\xe7\xb1\xbb\xe5\x9e\x8b\xe6\x9f\xa5\xe6\x89\xbe\xe7\xac\xac\xe4\xb8\x80\xe4\xb8\xaa\xe5\x8c\xb9\xe9\x85\x8d\xe7\x9a\x84 Fragment\xef\xbc\x8c\xe6\x94\xaf\xe6\x8c\x81\xe4\xbc\xa0\xe5\x85\xa5\xe6\xb4\xbe\xe7\x94\x9f\xe7\xb1\xbb\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "FragmentClass" },
		{ "ModuleRelativePath", "Public/Item/InventoryItemDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\xb9\xe6\x8d\xae\xe7\xb1\xbb\xe5\x9e\x8b\xe6\x9f\xa5\xe6\x89\xbe\xe7\xac\xac\xe4\xb8\x80\xe4\xb8\xaa\xe5\x8c\xb9\xe9\x85\x8d\xe7\x9a\x84 Fragment\xef\xbc\x8c\xe6\x94\xaf\xe6\x8c\x81\xe4\xbc\xa0\xe5\x85\xa5\xe6\xb4\xbe\xe7\x94\x9f\xe7\xb1\xbb\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_FragmentClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::NewProp_FragmentClass = { "FragmentClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemDefinition_eventFindFragmentByClass_Parms, FragmentClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UInventoryItemFragment_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemDefinition_eventFindFragmentByClass_Parms, ReturnValue), Z_Construct_UClass_UInventoryItemFragment_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::NewProp_FragmentClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryItemDefinition, nullptr, "FindFragmentByClass", nullptr, nullptr, Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::InventoryItemDefinition_eventFindFragmentByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::InventoryItemDefinition_eventFindFragmentByClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemDefinition::execFindFragmentByClass)
{
	P_GET_OBJECT(UClass,Z_Param_FragmentClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UInventoryItemFragment**)Z_Param__Result=P_THIS->FindFragmentByClass(Z_Param_FragmentClass);
	P_NATIVE_END;
}
// End Class UInventoryItemDefinition Function FindFragmentByClass

// Begin Class UInventoryItemDefinition Function GetMaxStackSize
struct Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize_Statics
{
	struct InventoryItemDefinition_eventGetMaxStackSize_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x94\xe5\x9b\x9e\xe5\x8d\x95\xe4\xb8\xaa\xe7\x89\xa9\xe5\x93\x81\xe6\xa7\xbd\xe5\x85\x81\xe8\xae\xb8\xe4\xbf\x9d\xe5\xad\x98\xe7\x9a\x84\xe6\x9c\x80\xe5\xa4\xa7\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Item/InventoryItemDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x94\xe5\x9b\x9e\xe5\x8d\x95\xe4\xb8\xaa\xe7\x89\xa9\xe5\x93\x81\xe6\xa7\xbd\xe5\x85\x81\xe8\xae\xb8\xe4\xbf\x9d\xe5\xad\x98\xe7\x9a\x84\xe6\x9c\x80\xe5\xa4\xa7\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemDefinition_eventGetMaxStackSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryItemDefinition, nullptr, "GetMaxStackSize", nullptr, nullptr, Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize_Statics::InventoryItemDefinition_eventGetMaxStackSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize_Statics::InventoryItemDefinition_eventGetMaxStackSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemDefinition::execGetMaxStackSize)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetMaxStackSize();
	P_NATIVE_END;
}
// End Class UInventoryItemDefinition Function GetMaxStackSize

// Begin Class UInventoryItemDefinition
void UInventoryItemDefinition::StaticRegisterNativesUInventoryItemDefinition()
{
	UClass* Class = UInventoryItemDefinition::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CreateItemInstance", &UInventoryItemDefinition::execCreateItemInstance },
		{ "FindFragmentByClass", &UInventoryItemDefinition::execFindFragmentByClass },
		{ "GetMaxStackSize", &UInventoryItemDefinition::execGetMaxStackSize },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInventoryItemDefinition);
UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister()
{
	return UInventoryItemDefinition::StaticClass();
}
struct Z_Construct_UClass_UInventoryItemDefinition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xe7\x89\xa9\xe5\x93\x81\xe7\x9a\x84\xe9\x9d\x99\xe6\x80\x81\xe5\xae\x9a\xe4\xb9\x89\xe8\xb5\x84\xe4\xba\xa7\xe3\x80\x82\n *\n * \xe5\x90\x8c\xe4\xb8\x80\xe7\xa7\x8d\xe7\x89\xa9\xe5\x93\x81\xe7\x9a\x84\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x81\xe6\x8f\x8f\xe8\xbf\xb0\xe3\x80\x81\xe6\xa0\x87\xe7\xad\xbe\xe5\x92\x8c Fragment \xe9\x85\x8d\xe7\xbd\xae\xe5\x8f\xaa\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\x80\xe4\xbb\xbd\xef\xbc\x9b\xe8\x83\x8c\xe5\x8c\x85\xe4\xb8\xad\xe7\x9a\x84\xe6\xaf\x8f\xe4\xb8\xaa\n * \xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe7\x89\xa9\xe5\x93\x81\xe5\x88\x99\xe4\xbd\xbf\xe7\x94\xa8 UInventoryItemInstance \xe5\xbc\x95\xe7\x94\xa8\xe8\xaf\xa5\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe9\x81\xbf\xe5\x85\x8d\xe9\x87\x8d\xe5\xa4\x8d\xe9\x9d\x99\xe6\x80\x81\xe6\x95\xb0\xe6\x8d\xae\xe3\x80\x82\n */" },
#endif
		{ "IncludePath", "Item/InventoryItemDefinition.h" },
		{ "ModuleRelativePath", "Public/Item/InventoryItemDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\x89\xa9\xe5\x93\x81\xe7\x9a\x84\xe9\x9d\x99\xe6\x80\x81\xe5\xae\x9a\xe4\xb9\x89\xe8\xb5\x84\xe4\xba\xa7\xe3\x80\x82\n\n\xe5\x90\x8c\xe4\xb8\x80\xe7\xa7\x8d\xe7\x89\xa9\xe5\x93\x81\xe7\x9a\x84\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x81\xe6\x8f\x8f\xe8\xbf\xb0\xe3\x80\x81\xe6\xa0\x87\xe7\xad\xbe\xe5\x92\x8c Fragment \xe9\x85\x8d\xe7\xbd\xae\xe5\x8f\xaa\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\x80\xe4\xbb\xbd\xef\xbc\x9b\xe8\x83\x8c\xe5\x8c\x85\xe4\xb8\xad\xe7\x9a\x84\xe6\xaf\x8f\xe4\xb8\xaa\n\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe7\x89\xa9\xe5\x93\x81\xe5\x88\x99\xe4\xbd\xbf\xe7\x94\xa8 UInventoryItemInstance \xe5\xbc\x95\xe7\x94\xa8\xe8\xaf\xa5\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe9\x81\xbf\xe5\x85\x8d\xe9\x87\x8d\xe5\xa4\x8d\xe9\x9d\x99\xe6\x80\x81\xe6\x95\xb0\xe6\x8d\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Inventory|Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x92\x8c UI \xe4\xb8\xad\xe6\x98\xbe\xe7\xa4\xba\xe7\x9a\x84\xe7\x89\xa9\xe5\x93\x81\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Item/InventoryItemDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x92\x8c UI \xe4\xb8\xad\xe6\x98\xbe\xe7\xa4\xba\xe7\x9a\x84\xe7\x89\xa9\xe5\x93\x81\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Inventory|Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\x89\xa9\xe5\x93\x81\xe7\x9a\x84\xe8\xaf\xa6\xe7\xbb\x86\xe8\xaf\xb4\xe6\x98\x8e\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Item/InventoryItemDefinition.h" },
		{ "MultiLine", "TRUE" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\x89\xa9\xe5\x93\x81\xe7\x9a\x84\xe8\xaf\xa6\xe7\xbb\x86\xe8\xaf\xb4\xe6\x98\x8e\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemTags_MetaData[] = {
		{ "Category", "Inventory|Tags" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8f\x8f\xe8\xbf\xb0\xe7\x89\xa9\xe5\x93\x81\xe7\xb1\xbb\xe5\x88\xab\xe5\x92\x8c\xe7\x89\xb9\xe6\x80\xa7\xe7\x9a\x84\xe9\x9d\x99\xe6\x80\x81 Gameplay Tag\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Item/InventoryItemDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8f\x8f\xe8\xbf\xb0\xe7\x89\xa9\xe5\x93\x81\xe7\xb1\xbb\xe5\x88\xab\xe5\x92\x8c\xe7\x89\xb9\xe6\x80\xa7\xe7\x9a\x84\xe9\x9d\x99\xe6\x80\x81 Gameplay Tag\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStackSize_MetaData[] = {
		{ "Category", "Inventory|Stack" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x8d\x95\xe4\xb8\xaa\xe7\x89\xa9\xe5\x93\x81\xe6\xa7\xbd\xe5\x85\x81\xe8\xae\xb8\xe4\xbf\x9d\xe5\xad\x98\xe7\x9a\x84\xe6\x9c\x80\xe5\xa4\xa7\xe6\x95\xb0\xe9\x87\x8f\xef\xbc\x8c -1\xe8\xa1\xa8\xe7\xa4\xba\xe6\xb2\xa1\xe6\x9c\x89\xe9\x99\x90\xe5\x88\xb6*/" },
#endif
		{ "ModuleRelativePath", "Public/Item/InventoryItemDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x8d\x95\xe4\xb8\xaa\xe7\x89\xa9\xe5\x93\x81\xe6\xa7\xbd\xe5\x85\x81\xe8\xae\xb8\xe4\xbf\x9d\xe5\xad\x98\xe7\x9a\x84\xe6\x9c\x80\xe5\xa4\xa7\xe6\x95\xb0\xe9\x87\x8f\xef\xbc\x8c -1\xe8\xa1\xa8\xe7\xa4\xba\xe6\xb2\xa1\xe6\x9c\x89\xe9\x99\x90\xe5\x88\xb6" },
#endif
		{ "UIMin", "1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Fragments_Inner_MetaData[] = {
		{ "Category", "Inventory|Fragments" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \xe7\xbb\x84\xe6\x88\x90\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9a\xe4\xb9\x89\xe7\x9a\x84\xe5\x86\x85\xe8\x81\x94\xe9\x85\x8d\xe7\xbd\xae\xe7\x89\x87\xe6\xae\xb5\xe3\x80\x82\n\x09 * Instanced \xe4\xbd\xbf\xe6\x95\xb0\xe7\xbb\x84\xe5\x85\x83\xe7\xb4\xa0\xe6\x88\x90\xe4\xb8\xba\xe5\xbd\x93\xe5\x89\x8d DataAsset \xe7\x9a\x84\xe5\xad\x90\xe5\xaf\xb9\xe8\xb1\xa1\xef\xbc\x8c\xe8\x80\x8c\xe4\xb8\x8d\xe6\x98\xaf\xe7\x8b\xac\xe7\xab\x8b\xe8\xb5\x84\xe4\xba\xa7\xe5\xbc\x95\xe7\x94\xa8\xe3\x80\x82\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Item/InventoryItemDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xbb\x84\xe6\x88\x90\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9a\xe4\xb9\x89\xe7\x9a\x84\xe5\x86\x85\xe8\x81\x94\xe9\x85\x8d\xe7\xbd\xae\xe7\x89\x87\xe6\xae\xb5\xe3\x80\x82\nInstanced \xe4\xbd\xbf\xe6\x95\xb0\xe7\xbb\x84\xe5\x85\x83\xe7\xb4\xa0\xe6\x88\x90\xe4\xb8\xba\xe5\xbd\x93\xe5\x89\x8d DataAsset \xe7\x9a\x84\xe5\xad\x90\xe5\xaf\xb9\xe8\xb1\xa1\xef\xbc\x8c\xe8\x80\x8c\xe4\xb8\x8d\xe6\x98\xaf\xe7\x8b\xac\xe7\xab\x8b\xe8\xb5\x84\xe4\xba\xa7\xe5\xbc\x95\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Fragments_MetaData[] = {
		{ "Category", "Inventory|Fragments" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \xe7\xbb\x84\xe6\x88\x90\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9a\xe4\xb9\x89\xe7\x9a\x84\xe5\x86\x85\xe8\x81\x94\xe9\x85\x8d\xe7\xbd\xae\xe7\x89\x87\xe6\xae\xb5\xe3\x80\x82\n\x09 * Instanced \xe4\xbd\xbf\xe6\x95\xb0\xe7\xbb\x84\xe5\x85\x83\xe7\xb4\xa0\xe6\x88\x90\xe4\xb8\xba\xe5\xbd\x93\xe5\x89\x8d DataAsset \xe7\x9a\x84\xe5\xad\x90\xe5\xaf\xb9\xe8\xb1\xa1\xef\xbc\x8c\xe8\x80\x8c\xe4\xb8\x8d\xe6\x98\xaf\xe7\x8b\xac\xe7\xab\x8b\xe8\xb5\x84\xe4\xba\xa7\xe5\xbc\x95\xe7\x94\xa8\xe3\x80\x82\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Item/InventoryItemDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xbb\x84\xe6\x88\x90\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9a\xe4\xb9\x89\xe7\x9a\x84\xe5\x86\x85\xe8\x81\x94\xe9\x85\x8d\xe7\xbd\xae\xe7\x89\x87\xe6\xae\xb5\xe3\x80\x82\nInstanced \xe4\xbd\xbf\xe6\x95\xb0\xe7\xbb\x84\xe5\x85\x83\xe7\xb4\xa0\xe6\x88\x90\xe4\xb8\xba\xe5\xbd\x93\xe5\x89\x8d DataAsset \xe7\x9a\x84\xe5\xad\x90\xe5\xaf\xb9\xe8\xb1\xa1\xef\xbc\x8c\xe8\x80\x8c\xe4\xb8\x8d\xe6\x98\xaf\xe7\x8b\xac\xe7\xab\x8b\xe8\xb5\x84\xe4\xba\xa7\xe5\xbc\x95\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemTags;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxStackSize;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Fragments_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Fragments;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryItemDefinition_CreateItemInstance, "CreateItemInstance" }, // 3135600127
		{ &Z_Construct_UFunction_UInventoryItemDefinition_FindFragmentByClass, "FindFragmentByClass" }, // 156468577
		{ &Z_Construct_UFunction_UInventoryItemDefinition_GetMaxStackSize, "GetMaxStackSize" }, // 1409815039
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryItemDefinition>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_ItemTags = { "ItemTags", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, ItemTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemTags_MetaData), NewProp_ItemTags_MetaData) }; // 3352185621
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_MaxStackSize = { "MaxStackSize", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, MaxStackSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStackSize_MetaData), NewProp_MaxStackSize_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_Fragments_Inner = { "Fragments", nullptr, (EPropertyFlags)0x0106000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UInventoryItemFragment_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Fragments_Inner_MetaData), NewProp_Fragments_Inner_MetaData) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_Fragments = { "Fragments", nullptr, (EPropertyFlags)0x012408800001001d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, Fragments), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Fragments_MetaData), NewProp_Fragments_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryItemDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_ItemTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_MaxStackSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_Fragments_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_Fragments,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemDefinition_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UInventoryItemDefinition_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemDefinition_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UInventoryItemDefinition_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UGameplayTagAssetInterface_NoRegister, (int32)VTABLE_OFFSET(UInventoryItemDefinition, IGameplayTagAssetInterface), false },  // 2863124436
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryItemDefinition_Statics::ClassParams = {
	&UInventoryItemDefinition::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UInventoryItemDefinition_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemDefinition_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemDefinition_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryItemDefinition_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UInventoryItemDefinition()
{
	if (!Z_Registration_Info_UClass_UInventoryItemDefinition.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryItemDefinition.OuterSingleton, Z_Construct_UClass_UInventoryItemDefinition_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryItemDefinition.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UClass* StaticClass<UInventoryItemDefinition>()
{
	return UInventoryItemDefinition::StaticClass();
}
UInventoryItemDefinition::UInventoryItemDefinition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryItemDefinition);
UInventoryItemDefinition::~UInventoryItemDefinition() {}
// End Class UInventoryItemDefinition

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemDefinition_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryItemDefinition, UInventoryItemDefinition::StaticClass, TEXT("UInventoryItemDefinition"), &Z_Registration_Info_UClass_UInventoryItemDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryItemDefinition), 3600193174U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemDefinition_h_952769423(TEXT("/Script/PackSystemPlugin"),
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemDefinition_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemDefinition_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
