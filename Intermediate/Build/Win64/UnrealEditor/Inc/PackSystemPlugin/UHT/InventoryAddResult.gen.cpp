// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/InventoryAddResult.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryAddResult() {}

// Begin Cross Module References
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
PACKSYSTEMPLUGIN_API UEnum* Z_Construct_UEnum_PackSystemPlugin_EInventoryOperationStatus();
PACKSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryAddResult();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin Enum EInventoryOperationStatus
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EInventoryOperationStatus;
static UEnum* EInventoryOperationStatus_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EInventoryOperationStatus.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EInventoryOperationStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PackSystemPlugin_EInventoryOperationStatus, (UObject*)Z_Construct_UPackage__Script_PackSystemPlugin(), TEXT("EInventoryOperationStatus"));
	}
	return Z_Registration_Info_UEnum_EInventoryOperationStatus.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UEnum* StaticEnum<EInventoryOperationStatus>()
{
	return EInventoryOperationStatus_StaticEnum();
}
struct Z_Construct_UEnum_PackSystemPlugin_EInventoryOperationStatus_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Failed.Name", "EInventoryOperationStatus::Failed" },
		{ "ModuleRelativePath", "Public/InventoryAddResult.h" },
		{ "PartialSucceeded.Name", "EInventoryOperationStatus::PartialSucceeded" },
		{ "Succeeded.Name", "EInventoryOperationStatus::Succeeded" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EInventoryOperationStatus::Failed", (int64)EInventoryOperationStatus::Failed },
		{ "EInventoryOperationStatus::PartialSucceeded", (int64)EInventoryOperationStatus::PartialSucceeded },
		{ "EInventoryOperationStatus::Succeeded", (int64)EInventoryOperationStatus::Succeeded },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PackSystemPlugin_EInventoryOperationStatus_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_PackSystemPlugin,
	nullptr,
	"EInventoryOperationStatus",
	"EInventoryOperationStatus",
	Z_Construct_UEnum_PackSystemPlugin_EInventoryOperationStatus_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_PackSystemPlugin_EInventoryOperationStatus_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PackSystemPlugin_EInventoryOperationStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PackSystemPlugin_EInventoryOperationStatus_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_PackSystemPlugin_EInventoryOperationStatus()
{
	if (!Z_Registration_Info_UEnum_EInventoryOperationStatus.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EInventoryOperationStatus.InnerSingleton, Z_Construct_UEnum_PackSystemPlugin_EInventoryOperationStatus_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EInventoryOperationStatus.InnerSingleton;
}
// End Enum EInventoryOperationStatus

// Begin ScriptStruct FInventoryAddResult
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_InventoryAddResult;
class UScriptStruct* FInventoryAddResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryAddResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_InventoryAddResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventoryAddResult, (UObject*)Z_Construct_UPackage__Script_PackSystemPlugin(), TEXT("InventoryAddResult"));
	}
	return Z_Registration_Info_UScriptStruct_InventoryAddResult.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UScriptStruct* StaticStruct<FInventoryAddResult>()
{
	return FInventoryAddResult::StaticStruct();
}
struct Z_Construct_UScriptStruct_FInventoryAddResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/InventoryAddResult.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OperationStatus_MetaData[] = {
		{ "Category", "InventoryAddResult" },
		{ "ModuleRelativePath", "Public/InventoryAddResult.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequestedQuantity_MetaData[] = {
		{ "Category", "InventoryAddResult" },
		{ "ModuleRelativePath", "Public/InventoryAddResult.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AcceptedQuantity_MetaData[] = {
		{ "Category", "InventoryAddResult" },
		{ "ModuleRelativePath", "Public/InventoryAddResult.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RemainingQuantity_MetaData[] = {
		{ "Category", "InventoryAddResult" },
		{ "ModuleRelativePath", "Public/InventoryAddResult.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureReason_MetaData[] = {
		{ "Category", "InventoryAddResult" },
		{ "ModuleRelativePath", "Public/InventoryAddResult.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_OperationStatus_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OperationStatus;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_RequestedQuantity;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_AcceptedQuantity;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_RemainingQuantity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FailureReason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventoryAddResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FInventoryAddResult_Statics::NewProp_OperationStatus_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FInventoryAddResult_Statics::NewProp_OperationStatus = { "OperationStatus", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddResult, OperationStatus), Z_Construct_UEnum_PackSystemPlugin_EInventoryOperationStatus, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OperationStatus_MetaData), NewProp_OperationStatus_MetaData) }; // 159790102
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FInventoryAddResult_Statics::NewProp_RequestedQuantity = { "RequestedQuantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddResult, RequestedQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequestedQuantity_MetaData), NewProp_RequestedQuantity_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FInventoryAddResult_Statics::NewProp_AcceptedQuantity = { "AcceptedQuantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddResult, AcceptedQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AcceptedQuantity_MetaData), NewProp_AcceptedQuantity_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FInventoryAddResult_Statics::NewProp_RemainingQuantity = { "RemainingQuantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddResult, RemainingQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RemainingQuantity_MetaData), NewProp_RemainingQuantity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInventoryAddResult_Statics::NewProp_FailureReason = { "FailureReason", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddResult, FailureReason), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureReason_MetaData), NewProp_FailureReason_MetaData) }; // 1298103297
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventoryAddResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddResult_Statics::NewProp_OperationStatus_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddResult_Statics::NewProp_OperationStatus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddResult_Statics::NewProp_RequestedQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddResult_Statics::NewProp_AcceptedQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddResult_Statics::NewProp_RemainingQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddResult_Statics::NewProp_FailureReason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventoryAddResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
	nullptr,
	&NewStructOps,
	"InventoryAddResult",
	Z_Construct_UScriptStruct_FInventoryAddResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddResult_Statics::PropPointers),
	sizeof(FInventoryAddResult),
	alignof(FInventoryAddResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FInventoryAddResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FInventoryAddResult()
{
	if (!Z_Registration_Info_UScriptStruct_InventoryAddResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_InventoryAddResult.InnerSingleton, Z_Construct_UScriptStruct_FInventoryAddResult_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_InventoryAddResult.InnerSingleton;
}
// End ScriptStruct FInventoryAddResult

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddResult_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EInventoryOperationStatus_StaticEnum, TEXT("EInventoryOperationStatus"), &Z_Registration_Info_UEnum_EInventoryOperationStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 159790102U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FInventoryAddResult::StaticStruct, Z_Construct_UScriptStruct_FInventoryAddResult_Statics::NewStructOps, TEXT("InventoryAddResult"), &Z_Registration_Info_UScriptStruct_InventoryAddResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInventoryAddResult), 2976956780U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddResult_h_1674283823(TEXT("/Script/PackSystemPlugin"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddResult_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddResult_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddResult_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryAddResult_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
