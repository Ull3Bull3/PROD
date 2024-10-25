// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReadWriteTextFile.generated.h"

/**
 * 
 */
UCLASS()
class PROD_UE_API UReadWriteTextFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


	UFUNCTION(BlueprintCallable, Category = "ReadWriteFile")
	static FString ReadStringFromFile(FString Path);

	UFUNCTION(BlueprintCallable, Category = "ReadWriteFile")
	static void WriteStringToFile(FString Path, FString String);
};
