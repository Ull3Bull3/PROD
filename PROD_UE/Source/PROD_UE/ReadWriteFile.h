// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
/**
 * 
 */
class PROD_UE_API ReadWriteFile
{
public:
	ReadWriteFile();
	~ReadWriteFile();

	UFUNCTION(BlueprintCallable, Category = "ReadWriteFile")
	static FString ReadStringFromFile(FString path);

	UFUNCTION(BlueprintCallable, Category = "ReadWriteFile")
	static void WriteStringToFile(FString path, FString string);
};
