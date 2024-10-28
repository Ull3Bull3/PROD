// Fill out your copyright notice in the Description page of Project Settings.


#include "ReadWriteTextFile.h"

FString UReadWriteTextFile::ReadStringFromFile(FString Path)
{
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*Path))
	{
		return "";
	}

	FString ReturnString = "";

	if (!FFileHelper::LoadFileToString(ReturnString, *Path))
	{
		return "";
	}
	
	return ReturnString;
}

void UReadWriteTextFile::WriteStringToFile(FString Path, FString String)
{
	FString TempString = ReadStringFromFile(Path);
	TempString.Append("\n");
	TempString.Append(String);
	
	FFileHelper::SaveStringToFile(TempString, *Path);
}