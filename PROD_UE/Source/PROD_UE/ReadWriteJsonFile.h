// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReadWriteJsonFile.generated.h"

class FJsonObject;

USTRUCT(BlueprintType)
struct FPlayTestVariableStruct
{
	GENERATED_BODY()

	public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float PlayerMoveSpeedMultiplier = 1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float PlayerTurnSpeedMultiplier = 0.5f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimeToSaveVase = 3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float EnemySpeed = 900;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SafeZoneRadius = 320;
	
};


UCLASS()
class PROD_UE_API UReadWriteJsonFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static FPlayTestVariableStruct ReadStructFromJsonFile(FString Path);

	UFUNCTION(BlueprintCallable)
	static void WriteStructToJsonFile(FString Path, FPlayTestVariableStruct Struct);
	
	static TSharedPtr<FJsonObject> ReadJson(FString Path);

	static void WriteJson(FString Path, TSharedPtr<FJsonObject> JsonObject);
	
};
