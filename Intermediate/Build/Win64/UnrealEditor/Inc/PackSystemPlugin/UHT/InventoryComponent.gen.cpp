// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PackSystemPlugin/Public/InventoryComponent.h"
#include "PackSystemPlugin/Public/InventoryEntry.h"
#include "PackSystemPlugin/Public/InventoryEntryArray.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryComponent();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
PACKSYSTEMPLUGIN_API UClass* Z_Construct_UClass_UInventoryItemInstance_NoRegister();
PACKSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryEntry();
PACKSYSTEMPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryEntryArray();
UPackage* Z_Construct_UPackage__Script_PackSystemPlugin();
// End Cross Module References

// Begin Class UInventoryComponent Function GetAllEntries
struct Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics
{
	struct InventoryComponent_eventGetAllEntries_Parms
	{
		TArray<FInventoryEntry> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// TODO: \xe8\x8e\xb7\xe5\xbe\x97\xe5\x85\xa8\xe9\x83\xa8\xe7\x9a\x84""Entry\n" },
#endif
		{ "ModuleRelativePath", "Public/InventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "TODO: \xe8\x8e\xb7\xe5\xbe\x97\xe5\x85\xa8\xe9\x83\xa8\xe7\x9a\x84""Entry" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FInventoryEntry, METADATA_PARAMS(0, nullptr) }; // 3483008653
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventGetAllEntries_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3483008653
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "GetAllEntries", nullptr, nullptr, Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::PropPointers), sizeof(Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::InventoryComponent_eventGetAllEntries_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::InventoryComponent_eventGetAllEntries_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_GetAllEntries()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_GetAllEntries_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execGetAllEntries)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FInventoryEntry>*)Z_Param__Result=P_THIS->GetAllEntries();
	P_NATIVE_END;
}
// End Class UInventoryComponent Function GetAllEntries

// Begin Class UInventoryComponent Function LootItem
struct Z_Construct_UFunction_UInventoryComponent_LootItem_Statics
{
	struct InventoryComponent_eventLootItem_Parms
	{
		UInventoryItemInstance* ItemInstance;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/InventoryComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemInstance;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::NewProp_ItemInstance = { "ItemInstance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventLootItem_Parms, ItemInstance), Z_Construct_UClass_UInventoryItemInstance_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryComponent_eventLootItem_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryComponent_eventLootItem_Parms), &Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::NewProp_ItemInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "LootItem", nullptr, nullptr, Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::PropPointers), sizeof(Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::InventoryComponent_eventLootItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::InventoryComponent_eventLootItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_LootItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_LootItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execLootItem)
{
	P_GET_OBJECT(UInventoryItemInstance,Z_Param_ItemInstance);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->LootItem(Z_Param_ItemInstance);
	P_NATIVE_END;
}
// End Class UInventoryComponent Function LootItem

// Begin Class UInventoryComponent
void UInventoryComponent::StaticRegisterNativesUInventoryComponent()
{
	UClass* Class = UInventoryComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetAllEntries", &UInventoryComponent::execGetAllEntries },
		{ "LootItem", &UInventoryComponent::execLootItem },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInventoryComponent);
UClass* Z_Construct_UClass_UInventoryComponent_NoRegister()
{
	return UInventoryComponent::StaticClass();
}
struct Z_Construct_UClass_UInventoryComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Inventory" },
		{ "IncludePath", "InventoryComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/InventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialEntryCount_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/InventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntryArray_MetaData[] = {
		{ "Category", "InventoryComponent" },
		{ "ModuleRelativePath", "Public/InventoryComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_InitialEntryCount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EntryArray;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryComponent_GetAllEntries, "GetAllEntries" }, // 286636017
		{ &Z_Construct_UFunction_UInventoryComponent_LootItem, "LootItem" }, // 923536528
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_InitialEntryCount = { "InitialEntryCount", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponent, InitialEntryCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialEntryCount_MetaData), NewProp_InitialEntryCount_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_EntryArray = { "EntryArray", nullptr, (EPropertyFlags)0x0020088000020801, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponent, EntryArray), Z_Construct_UScriptStruct_FInventoryEntryArray, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntryArray_MetaData), NewProp_EntryArray_MetaData) }; // 37586296
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_InitialEntryCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_EntryArray,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UInventoryComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_PackSystemPlugin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryComponent_Statics::ClassParams = {
	&UInventoryComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UInventoryComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UInventoryComponent()
{
	if (!Z_Registration_Info_UClass_UInventoryComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryComponent.OuterSingleton, Z_Construct_UClass_UInventoryComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryComponent.OuterSingleton;
}
template<> PACKSYSTEMPLUGIN_API UClass* StaticClass<UInventoryComponent>()
{
	return UInventoryComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryComponent);
UInventoryComponent::~UInventoryComponent() {}
// End Class UInventoryComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryComponent, UInventoryComponent::StaticClass, TEXT("UInventoryComponent"), &Z_Registration_Info_UClass_UInventoryComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryComponent), 1701859140U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryComponent_h_1300863741(TEXT("/Script/PackSystemPlugin"),
	Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealLab_PackSystem_Plugins_PackSystemPlugin_Source_PackSystemPlugin_Public_InventoryComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
