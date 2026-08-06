// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/Item/InventoryItemInstance.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryItemInstance() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
GAMEPLAYTAGS_API UClass* Z_Construct_UClass_UGameplayTagAssetInterface_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemFragment_NoRegister();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemInstance();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin Class UInventoryItemInstance Function AddInstanceTag
struct Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag_Statics
{
	struct InventoryItemInstance_eventAddInstanceTag_Parms
	{
		FGameplayTag Tag;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Instance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xb8\xba\xe5\xbd\x93\xe5\x89\x8d\xe5\xae\x9e\xe4\xbe\x8b\xe6\xb7\xbb\xe5\x8a\xa0\xe4\xb8\x80\xe4\xb8\xaa\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe6\xa0\x87\xe7\xad\xbe\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Item/InventoryItemInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xb8\xba\xe5\xbd\x93\xe5\x89\x8d\xe5\xae\x9e\xe4\xbe\x8b\xe6\xb7\xbb\xe5\x8a\xa0\xe4\xb8\x80\xe4\xb8\xaa\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe6\xa0\x87\xe7\xad\xbe\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemInstance_eventAddInstanceTag_Parms, Tag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 1298103297
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag_Statics::NewProp_Tag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryItemInstance, nullptr, "AddInstanceTag", nullptr, nullptr, Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag_Statics::PropPointers), sizeof(Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag_Statics::InventoryItemInstance_eventAddInstanceTag_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag_Statics::InventoryItemInstance_eventAddInstanceTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemInstance::execAddInstanceTag)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_Tag);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddInstanceTag(Z_Param_Tag);
	P_NATIVE_END;
}
// End Class UInventoryItemInstance Function AddInstanceTag

// Begin Class UInventoryItemInstance Function FindFragmentByClass
struct Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics
{
	struct InventoryItemInstance_eventFindFragmentByClass_Parms
	{
		TSubclassOf<UInventoryItemFragment> FragmentClass;
		UInventoryItemFragment* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Instance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbb\x8e\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9a\xe4\xb9\x89\xe4\xb8\xad\xe6\x9f\xa5\xe6\x89\xbe\xe6\x8c\x87\xe5\xae\x9a\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84 Fragment\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "FragmentClass" },
		{ "ModuleRelativePath", "Public/Item/InventoryItemInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbb\x8e\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9a\xe4\xb9\x89\xe4\xb8\xad\xe6\x9f\xa5\xe6\x89\xbe\xe6\x8c\x87\xe5\xae\x9a\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84 Fragment\xe3\x80\x82" },
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
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::NewProp_FragmentClass = { "FragmentClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemInstance_eventFindFragmentByClass_Parms, FragmentClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UInventoryItemFragment_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemInstance_eventFindFragmentByClass_Parms, ReturnValue), Z_Construct_UClass_UInventoryItemFragment_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::NewProp_FragmentClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryItemInstance, nullptr, "FindFragmentByClass", nullptr, nullptr, Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::InventoryItemInstance_eventFindFragmentByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::InventoryItemInstance_eventFindFragmentByClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemInstance::execFindFragmentByClass)
{
	P_GET_OBJECT(UClass,Z_Param_FragmentClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UInventoryItemFragment**)Z_Param__Result=P_THIS->FindFragmentByClass(Z_Param_FragmentClass);
	P_NATIVE_END;
}
// End Class UInventoryItemInstance Function FindFragmentByClass

// Begin Class UInventoryItemInstance Function GetItemDefinition
struct Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition_Statics
{
	struct InventoryItemInstance_eventGetItemDefinition_Parms
	{
		UInventoryItemDefinition* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Instance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x94\xe5\x9b\x9e\xe8\xaf\xa5\xe5\xae\x9e\xe4\xbe\x8b\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe9\x9d\x99\xe6\x80\x81\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9a\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Item/InventoryItemInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x94\xe5\x9b\x9e\xe8\xaf\xa5\xe5\xae\x9e\xe4\xbe\x8b\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe9\x9d\x99\xe6\x80\x81\xe7\x89\xa9\xe5\x93\x81\xe5\xae\x9a\xe4\xb9\x89\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemInstance_eventGetItemDefinition_Parms, ReturnValue), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryItemInstance, nullptr, "GetItemDefinition", nullptr, nullptr, Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition_Statics::InventoryItemInstance_eventGetItemDefinition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition_Statics::InventoryItemInstance_eventGetItemDefinition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemInstance::execGetItemDefinition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UInventoryItemDefinition**)Z_Param__Result=P_THIS->GetItemDefinition();
	P_NATIVE_END;
}
// End Class UInventoryItemInstance Function GetItemDefinition

// Begin Class UInventoryItemInstance Function RemoveInstanceTag
struct Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag_Statics
{
	struct InventoryItemInstance_eventRemoveInstanceTag_Parms
	{
		FGameplayTag Tag;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Instance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbb\x8e\xe5\xbd\x93\xe5\x89\x8d\xe5\xae\x9e\xe4\xbe\x8b\xe7\xa7\xbb\xe9\x99\xa4\xe4\xb8\x80\xe4\xb8\xaa\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe6\xa0\x87\xe7\xad\xbe\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Item/InventoryItemInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbb\x8e\xe5\xbd\x93\xe5\x89\x8d\xe5\xae\x9e\xe4\xbe\x8b\xe7\xa7\xbb\xe9\x99\xa4\xe4\xb8\x80\xe4\xb8\xaa\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe6\xa0\x87\xe7\xad\xbe\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemInstance_eventRemoveInstanceTag_Parms, Tag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 1298103297
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag_Statics::NewProp_Tag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryItemInstance, nullptr, "RemoveInstanceTag", nullptr, nullptr, Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag_Statics::PropPointers), sizeof(Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag_Statics::InventoryItemInstance_eventRemoveInstanceTag_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag_Statics::InventoryItemInstance_eventRemoveInstanceTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemInstance::execRemoveInstanceTag)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_Tag);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveInstanceTag(Z_Param_Tag);
	P_NATIVE_END;
}
// End Class UInventoryItemInstance Function RemoveInstanceTag

// Begin Class UInventoryItemInstance
void UInventoryItemInstance::StaticRegisterNativesUInventoryItemInstance()
{
	UClass* Class = UInventoryItemInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddInstanceTag", &UInventoryItemInstance::execAddInstanceTag },
		{ "FindFragmentByClass", &UInventoryItemInstance::execFindFragmentByClass },
		{ "GetItemDefinition", &UInventoryItemInstance::execGetItemDefinition },
		{ "RemoveInstanceTag", &UInventoryItemInstance::execRemoveInstanceTag },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInventoryItemInstance);
UClass* Z_Construct_UClass_UInventoryItemInstance_NoRegister()
{
	return UInventoryItemInstance::StaticClass();
}
struct Z_Construct_UClass_UInventoryItemInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xe8\x83\x8c\xe5\x8c\x85\xe4\xb8\xad\xe7\x89\xa9\xe5\x93\x81\xe7\x9a\x84\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82\n * \xe5\xae\x9e\xe4\xbe\x8b\xe5\xbc\x95\xe7\x94\xa8\xe4\xb8\x80\xe4\xb8\xaa\xe9\x9d\x99\xe6\x80\x81 UInventoryItemDefinition\xef\xbc\x8c\xe5\xb9\xb6\xe5\x8f\xaa\xe4\xbf\x9d\xe5\xad\x98\xe4\xbc\x9a\xe5\x9c\xa8\xe6\xb8\xb8\xe6\x88\x8f\xe8\xbf\x87\xe7\xa8\x8b\xe4\xb8\xad\xe5\x8f\x98\xe5\x8c\x96\xe7\x9a\x84\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe4\xbe\x8b\xe5\xa6\x82\xe5\xae\x9e\xe4\xbe\x8b\xe6\xa0\x87\xe7\xad\xbe\xe5\x92\x8c\xe5\xbd\x93\xe5\x89\x8d\xe5\xa0\x86\xe5\x8f\xa0\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82\n */" },
#endif
		{ "IncludePath", "Item/InventoryItemInstance.h" },
		{ "ModuleRelativePath", "Public/Item/InventoryItemInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x83\x8c\xe5\x8c\x85\xe4\xb8\xad\xe7\x89\xa9\xe5\x93\x81\xe7\x9a\x84\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82\n\xe5\xae\x9e\xe4\xbe\x8b\xe5\xbc\x95\xe7\x94\xa8\xe4\xb8\x80\xe4\xb8\xaa\xe9\x9d\x99\xe6\x80\x81 UInventoryItemDefinition\xef\xbc\x8c\xe5\xb9\xb6\xe5\x8f\xaa\xe4\xbf\x9d\xe5\xad\x98\xe4\xbc\x9a\xe5\x9c\xa8\xe6\xb8\xb8\xe6\x88\x8f\xe8\xbf\x87\xe7\xa8\x8b\xe4\xb8\xad\xe5\x8f\x98\xe5\x8c\x96\xe7\x9a\x84\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe4\xbe\x8b\xe5\xa6\x82\xe5\xae\x9e\xe4\xbe\x8b\xe6\xa0\x87\xe7\xad\xbe\xe5\x92\x8c\xe5\xbd\x93\xe5\x89\x8d\xe5\xa0\x86\xe5\x8f\xa0\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemDefinition_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Inventory|Instance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xbd\x93\xe5\x89\x8d\xe5\xae\x9e\xe4\xbe\x8b\xe5\xbc\x95\xe7\x94\xa8\xe7\x9a\x84\xe9\x9d\x99\xe6\x80\x81\xe5\xae\x9a\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Item/InventoryItemInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe5\xae\x9e\xe4\xbe\x8b\xe5\xbc\x95\xe7\x94\xa8\xe7\x9a\x84\xe9\x9d\x99\xe6\x80\x81\xe5\xae\x9a\xe4\xb9\x89\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceTags_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Inventory|Instance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbb\x85\xe5\xb1\x9e\xe4\xba\x8e\xe5\xbd\x93\xe5\x89\x8d\xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x81\xe5\x8f\xaf\xe5\x9c\xa8\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\x8f\x98\xe5\x8c\x96\xe7\x9a\x84\xe6\xa0\x87\xe7\xad\xbe\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Item/InventoryItemInstance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbb\x85\xe5\xb1\x9e\xe4\xba\x8e\xe5\xbd\x93\xe5\x89\x8d\xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x81\xe5\x8f\xaf\xe5\x9c\xa8\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\x8f\x98\xe5\x8c\x96\xe7\x9a\x84\xe6\xa0\x87\xe7\xad\xbe\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstanceTags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryItemInstance_AddInstanceTag, "AddInstanceTag" }, // 1874395770
		{ &Z_Construct_UFunction_UInventoryItemInstance_FindFragmentByClass, "FindFragmentByClass" }, // 2479433413
		{ &Z_Construct_UFunction_UInventoryItemInstance_GetItemDefinition, "GetItemDefinition" }, // 2536631257
		{ &Z_Construct_UFunction_UInventoryItemInstance_RemoveInstanceTag, "RemoveInstanceTag" }, // 2715410938
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryItemInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryItemInstance_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0144000000020815, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemInstance, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemDefinition_MetaData), NewProp_ItemDefinition_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UInventoryItemInstance_Statics::NewProp_InstanceTags = { "InstanceTags", nullptr, (EPropertyFlags)0x0040000000020815, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemInstance, InstanceTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceTags_MetaData), NewProp_InstanceTags_MetaData) }; // 3352185621
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryItemInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemInstance_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemInstance_Statics::NewProp_InstanceTags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UInventoryItemInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UInventoryItemInstance_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UGameplayTagAssetInterface_NoRegister, (int32)VTABLE_OFFSET(UInventoryItemInstance, IGameplayTagAssetInterface), false },  // 2863124436
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryItemInstance_Statics::ClassParams = {
	&UInventoryItemInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UInventoryItemInstance_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemInstance_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryItemInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UInventoryItemInstance()
{
	if (!Z_Registration_Info_UClass_UInventoryItemInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryItemInstance.OuterSingleton, Z_Construct_UClass_UInventoryItemInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryItemInstance.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UClass* StaticClass<UInventoryItemInstance>()
{
	return UInventoryItemInstance::StaticClass();
}
UInventoryItemInstance::UInventoryItemInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryItemInstance);
UInventoryItemInstance::~UInventoryItemInstance() {}
// End Class UInventoryItemInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryItemInstance, UInventoryItemInstance::StaticClass, TEXT("UInventoryItemInstance"), &Z_Registration_Info_UClass_UInventoryItemInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryItemInstance), 2363351709U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemInstance_h_1580200977(TEXT("/Script/PackSystemPlugin"),
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_Item_InventoryItemInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
