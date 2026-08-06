// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/InventoryAddPlan.h"
#include "PackSystemPlugin/Public/InventoryEntryArray.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryAddPlan() {}

// Begin Cross Module References
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemInstance_NoRegister();
PACKSYSTEMPLUGIN_API UEnum* Z_Construct_UEnum_PackSystemPlugin_EInventoryAddPlanOperation();
PACKSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryAddPlan();
PACKSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryAddPlanChange();
PACKSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryEntryHandle();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin Enum EInventoryAddPlanOperation
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EInventoryAddPlanOperation;
static UEnum* EInventoryAddPlanOperation_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EInventoryAddPlanOperation.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EInventoryAddPlanOperation.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PackSystemPlugin_EInventoryAddPlanOperation, (UObject*)Z_Construct_UPackage__Script_PackSystemPlugin(), TEXT("EInventoryAddPlanOperation"));
	}
	return Z_Registration_Info_UEnum_EInventoryAddPlanOperation.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UEnum* StaticEnum<EInventoryAddPlanOperation>()
{
	return EInventoryAddPlanOperation_StaticEnum();
}
struct Z_Construct_UEnum_PackSystemPlugin_EInventoryAddPlanOperation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xb8\x80\xe6\x9d\xa1\xe6\xb7\xbb\xe5\x8a\xa0\xe8\xae\xa1\xe5\x88\x92\xe5\x87\x86\xe5\xa4\x87\xe5\xaf\xb9\xe5\xba\x93\xe5\xad\x98 Entry \xe6\x89\xa7\xe8\xa1\x8c\xe7\x9a\x84\xe6\x93\x8d\xe4\xbd\x9c\xe3\x80\x82 */" },
#endif
		{ "CreateEntry.Name", "EInventoryAddPlanOperation::CreateEntry" },
		{ "IncreaseQuantity.Name", "EInventoryAddPlanOperation::IncreaseQuantity" },
		{ "ModuleRelativePath", "Public/InventoryAddPlan.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xb8\x80\xe6\x9d\xa1\xe6\xb7\xbb\xe5\x8a\xa0\xe8\xae\xa1\xe5\x88\x92\xe5\x87\x86\xe5\xa4\x87\xe5\xaf\xb9\xe5\xba\x93\xe5\xad\x98 Entry \xe6\x89\xa7\xe8\xa1\x8c\xe7\x9a\x84\xe6\x93\x8d\xe4\xbd\x9c\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EInventoryAddPlanOperation::CreateEntry", (int64)EInventoryAddPlanOperation::CreateEntry },
		{ "EInventoryAddPlanOperation::IncreaseQuantity", (int64)EInventoryAddPlanOperation::IncreaseQuantity },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PackSystemPlugin_EInventoryAddPlanOperation_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_PackSystemPlugin,
	nullptr,
	"EInventoryAddPlanOperation",
	"EInventoryAddPlanOperation",
	Z_Construct_UEnum_PackSystemPlugin_EInventoryAddPlanOperation_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_PackSystemPlugin_EInventoryAddPlanOperation_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PackSystemPlugin_EInventoryAddPlanOperation_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PackSystemPlugin_EInventoryAddPlanOperation_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_PackSystemPlugin_EInventoryAddPlanOperation()
{
	if (!Z_Registration_Info_UEnum_EInventoryAddPlanOperation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EInventoryAddPlanOperation.InnerSingleton, Z_Construct_UEnum_PackSystemPlugin_EInventoryAddPlanOperation_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EInventoryAddPlanOperation.InnerSingleton;
}
// End Enum EInventoryAddPlanOperation

// Begin ScriptStruct FInventoryAddPlanChange
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_InventoryAddPlanChange;
class UScriptStruct* FInventoryAddPlanChange::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryAddPlanChange.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_InventoryAddPlanChange.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventoryAddPlanChange, (UObject*)Z_Construct_UPackage__Script_PackSystemPlugin(), TEXT("InventoryAddPlanChange"));
	}
	return Z_Registration_Info_UScriptStruct_InventoryAddPlanChange.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UScriptStruct* StaticStruct<FInventoryAddPlanChange>()
{
	return FInventoryAddPlanChange::StaticStruct();
}
struct Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xe6\xb7\xbb\xe5\x8a\xa0\xe8\xae\xa1\xe5\x88\x92\xe4\xb8\xad\xe7\x9a\x84\xe5\x8d\x95\xe6\x9d\xa1 Entry \xe5\x8f\x98\xe6\x9b\xb4\xe3\x80\x82\n *\n * CreateEntry \xe6\x93\x8d\xe4\xbd\x9c\xe5\xbf\xbd\xe7\x95\xa5 TargetEntry\xef\xbc\x8c\xe5\xb9\xb6\xe4\xbd\xbf\xe7\x94\xa8 ItemInstance \xe4\xb8\x8e Quantity \xe5\x88\x9b\xe5\xbb\xba\xe6\x96\xb0\xe6\x9d\xa1\xe7\x9b\xae\xef\xbc\x9b\n * IncreaseQuantity \xe6\x93\x8d\xe4\xbd\x9c\xe5\x88\x99\xe6\x8a\x8a Quantity \xe5\xa2\x9e\xe5\x8a\xa0\xe5\x88\xb0 TargetEntry\xe3\x80\x82\n */" },
#endif
		{ "ModuleRelativePath", "Public/InventoryAddPlan.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb7\xbb\xe5\x8a\xa0\xe8\xae\xa1\xe5\x88\x92\xe4\xb8\xad\xe7\x9a\x84\xe5\x8d\x95\xe6\x9d\xa1 Entry \xe5\x8f\x98\xe6\x9b\xb4\xe3\x80\x82\n\nCreateEntry \xe6\x93\x8d\xe4\xbd\x9c\xe5\xbf\xbd\xe7\x95\xa5 TargetEntry\xef\xbc\x8c\xe5\xb9\xb6\xe4\xbd\xbf\xe7\x94\xa8 ItemInstance \xe4\xb8\x8e Quantity \xe5\x88\x9b\xe5\xbb\xba\xe6\x96\xb0\xe6\x9d\xa1\xe7\x9b\xae\xef\xbc\x9b\nIncreaseQuantity \xe6\x93\x8d\xe4\xbd\x9c\xe5\x88\x99\xe6\x8a\x8a Quantity \xe5\xa2\x9e\xe5\x8a\xa0\xe5\x88\xb0 TargetEntry\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Operation_MetaData[] = {
		{ "Category", "Inventory|Add Plan" },
		{ "ModuleRelativePath", "Public/InventoryAddPlan.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetEntry_MetaData[] = {
		{ "Category", "Inventory|Add Plan" },
		{ "ModuleRelativePath", "Public/InventoryAddPlan.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemInstance_MetaData[] = {
		{ "Category", "Inventory|Add Plan" },
		{ "ModuleRelativePath", "Public/InventoryAddPlan.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Inventory|Add Plan" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/InventoryAddPlan.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Operation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Operation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetEntry;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemInstance;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventoryAddPlanChange>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::NewProp_Operation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::NewProp_Operation = { "Operation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddPlanChange, Operation), Z_Construct_UEnum_PackSystemPlugin_EInventoryAddPlanOperation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Operation_MetaData), NewProp_Operation_MetaData) }; // 3626719622
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::NewProp_TargetEntry = { "TargetEntry", nullptr, (EPropertyFlags)0x0010008000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddPlanChange, TargetEntry), Z_Construct_UScriptStruct_FInventoryEntryHandle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetEntry_MetaData), NewProp_TargetEntry_MetaData) }; // 3909057280
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::NewProp_ItemInstance = { "ItemInstance", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddPlanChange, ItemInstance), Z_Construct_UClass_UInventoryItemInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemInstance_MetaData), NewProp_ItemInstance_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddPlanChange, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::NewProp_Operation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::NewProp_Operation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::NewProp_TargetEntry,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::NewProp_ItemInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::NewProp_Quantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
	nullptr,
	&NewStructOps,
	"InventoryAddPlanChange",
	Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::PropPointers),
	sizeof(FInventoryAddPlanChange),
	alignof(FInventoryAddPlanChange),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FInventoryAddPlanChange()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryAddPlanChange.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_InventoryAddPlanChange.InnerSingleton, Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_InventoryAddPlanChange.InnerSingleton;
}
// End ScriptStruct FInventoryAddPlanChange

// Begin ScriptStruct FInventoryAddPlan
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_InventoryAddPlan;
class UScriptStruct* FInventoryAddPlan::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryAddPlan.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_InventoryAddPlan.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventoryAddPlan, (UObject*)Z_Construct_UPackage__Script_PackSystemPlugin(), TEXT("InventoryAddPlan"));
	}
	return Z_Registration_Info_UScriptStruct_InventoryAddPlan.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UScriptStruct* StaticStruct<FInventoryAddPlan>()
{
	return FInventoryAddPlan::StaticStruct();
}
struct Z_Construct_UScriptStruct_FInventoryAddPlan_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Storage Strategy \xe6\xa0\xb9\xe6\x8d\xae\xe5\xbd\x93\xe5\x89\x8d\xe5\xba\x93\xe5\xad\x98\xe5\xbf\xab\xe7\x85\xa7\xe8\xae\xa1\xe7\xae\x97\xe5\x87\xba\xe7\x9a\x84\xe6\xb7\xbb\xe5\x8a\xa0\xe8\xae\xa1\xe5\x88\x92\xe3\x80\x82\n * \xe8\xaf\xa5\xe7\xbb\x93\xe6\x9e\x84\xe5\x8f\xaa\xe6\x8f\x8f\xe8\xbf\xb0\xe5\xbb\xba\xe8\xae\xae\xe6\x89\xa7\xe8\xa1\x8c\xe7\x9a\x84\xe5\x8f\x98\xe6\x9b\xb4\xef\xbc\x8c\xe4\xb8\x8d\xe7\x9b\xb4\xe6\x8e\xa5\xe4\xbf\xae\xe6\x94\xb9\xe5\xba\x93\xe5\xad\x98\xef\xbc\x8c\xe4\xb9\x9f\xe4\xb8\x8d\xe4\xbb\xa3\xe8\xa1\xa8\xe5\x8f\x98\xe6\x9b\xb4\xe5\xb7\xb2\xe7\xbb\x8f\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82\n */" },
#endif
		{ "ModuleRelativePath", "Public/InventoryAddPlan.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Storage Strategy \xe6\xa0\xb9\xe6\x8d\xae\xe5\xbd\x93\xe5\x89\x8d\xe5\xba\x93\xe5\xad\x98\xe5\xbf\xab\xe7\x85\xa7\xe8\xae\xa1\xe7\xae\x97\xe5\x87\xba\xe7\x9a\x84\xe6\xb7\xbb\xe5\x8a\xa0\xe8\xae\xa1\xe5\x88\x92\xe3\x80\x82\n\xe8\xaf\xa5\xe7\xbb\x93\xe6\x9e\x84\xe5\x8f\xaa\xe6\x8f\x8f\xe8\xbf\xb0\xe5\xbb\xba\xe8\xae\xae\xe6\x89\xa7\xe8\xa1\x8c\xe7\x9a\x84\xe5\x8f\x98\xe6\x9b\xb4\xef\xbc\x8c\xe4\xb8\x8d\xe7\x9b\xb4\xe6\x8e\xa5\xe4\xbf\xae\xe6\x94\xb9\xe5\xba\x93\xe5\xad\x98\xef\xbc\x8c\xe4\xb9\x9f\xe4\xb8\x8d\xe4\xbb\xa3\xe8\xa1\xa8\xe5\x8f\x98\xe6\x9b\xb4\xe5\xb7\xb2\xe7\xbb\x8f\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequestedQuantity_MetaData[] = {
		{ "Category", "Inventory|Add Plan" },
		{ "ModuleRelativePath", "Public/InventoryAddPlan.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlannedQuantity_MetaData[] = {
		{ "Category", "Inventory|Add Plan" },
		{ "ModuleRelativePath", "Public/InventoryAddPlan.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RemainingQuantity_MetaData[] = {
		{ "Category", "Inventory|Add Plan" },
		{ "ModuleRelativePath", "Public/InventoryAddPlan.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Changes_MetaData[] = {
		{ "Category", "Inventory|Add Plan" },
		{ "ModuleRelativePath", "Public/InventoryAddPlan.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureReason_MetaData[] = {
		{ "Category", "Inventory|Add Plan" },
		{ "ModuleRelativePath", "Public/InventoryAddPlan.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_RequestedQuantity;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PlannedQuantity;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_RemainingQuantity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Changes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Changes;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FailureReason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventoryAddPlan>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::NewProp_RequestedQuantity = { "RequestedQuantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddPlan, RequestedQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequestedQuantity_MetaData), NewProp_RequestedQuantity_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::NewProp_PlannedQuantity = { "PlannedQuantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddPlan, PlannedQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlannedQuantity_MetaData), NewProp_PlannedQuantity_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::NewProp_RemainingQuantity = { "RemainingQuantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddPlan, RemainingQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RemainingQuantity_MetaData), NewProp_RemainingQuantity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::NewProp_Changes_Inner = { "Changes", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FInventoryAddPlanChange, METADATA_PARAMS(0, nullptr) }; // 542591711
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::NewProp_Changes = { "Changes", nullptr, (EPropertyFlags)0x0010008000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddPlan, Changes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Changes_MetaData), NewProp_Changes_MetaData) }; // 542591711
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::NewProp_FailureReason = { "FailureReason", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddPlan, FailureReason), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureReason_MetaData), NewProp_FailureReason_MetaData) }; // 1298103297
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::NewProp_RequestedQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::NewProp_PlannedQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::NewProp_RemainingQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::NewProp_Changes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::NewProp_Changes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::NewProp_FailureReason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
	nullptr,
	&NewStructOps,
	"InventoryAddPlan",
	Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::PropPointers),
	sizeof(FInventoryAddPlan),
	alignof(FInventoryAddPlan),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FInventoryAddPlan()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryAddPlan.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_InventoryAddPlan.InnerSingleton, Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_InventoryAddPlan.InnerSingleton;
}
// End ScriptStruct FInventoryAddPlan

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddPlan_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EInventoryAddPlanOperation_StaticEnum, TEXT("EInventoryAddPlanOperation"), &Z_Registration_Info_UEnum_EInventoryAddPlanOperation, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3626719622U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FInventoryAddPlanChange::StaticStruct, Z_Construct_UScriptStruct_FInventoryAddPlanChange_Statics::NewStructOps, TEXT("InventoryAddPlanChange"), &Z_Registration_Info_UScriptStruct_InventoryAddPlanChange, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInventoryAddPlanChange), 542591711U) },
		{ FInventoryAddPlan::StaticStruct, Z_Construct_UScriptStruct_FInventoryAddPlan_Statics::NewStructOps, TEXT("InventoryAddPlan"), &Z_Registration_Info_UScriptStruct_InventoryAddPlan, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInventoryAddPlan), 3469299626U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddPlan_h_938435574(TEXT("/Script/PackSystemPlugin"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddPlan_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddPlan_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddPlan_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddPlan_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
