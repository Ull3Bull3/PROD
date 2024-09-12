// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PROD_UE/Key_Pickup.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKey_Pickup() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
PROD_UE_API UClass* Z_Construct_UClass_AKey_Pickup();
PROD_UE_API UClass* Z_Construct_UClass_AKey_Pickup_NoRegister();
UPackage* Z_Construct_UPackage__Script_PROD_UE();
// End Cross Module References

// Begin Class AKey_Pickup
void AKey_Pickup::StaticRegisterNativesAKey_Pickup()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AKey_Pickup);
UClass* Z_Construct_UClass_AKey_Pickup_NoRegister()
{
	return AKey_Pickup::StaticClass();
}
struct Z_Construct_UClass_AKey_Pickup_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Key_Pickup.h" },
		{ "ModuleRelativePath", "Key_Pickup.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AKey_Pickup>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AKey_Pickup_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_PROD_UE,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AKey_Pickup_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AKey_Pickup_Statics::ClassParams = {
	&AKey_Pickup::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AKey_Pickup_Statics::Class_MetaDataParams), Z_Construct_UClass_AKey_Pickup_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AKey_Pickup()
{
	if (!Z_Registration_Info_UClass_AKey_Pickup.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AKey_Pickup.OuterSingleton, Z_Construct_UClass_AKey_Pickup_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AKey_Pickup.OuterSingleton;
}
template<> PROD_UE_API UClass* StaticClass<AKey_Pickup>()
{
	return AKey_Pickup::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AKey_Pickup);
AKey_Pickup::~AKey_Pickup() {}
// End Class AKey_Pickup

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_islu9578_Documents_GitHub_PROD_PROD_UE_Source_PROD_UE_Key_Pickup_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AKey_Pickup, AKey_Pickup::StaticClass, TEXT("AKey_Pickup"), &Z_Registration_Info_UClass_AKey_Pickup, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AKey_Pickup), 586348319U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_islu9578_Documents_GitHub_PROD_PROD_UE_Source_PROD_UE_Key_Pickup_h_2654879690(TEXT("/Script/PROD_UE"),
	Z_CompiledInDeferFile_FID_Users_islu9578_Documents_GitHub_PROD_PROD_UE_Source_PROD_UE_Key_Pickup_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_islu9578_Documents_GitHub_PROD_PROD_UE_Source_PROD_UE_Key_Pickup_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
