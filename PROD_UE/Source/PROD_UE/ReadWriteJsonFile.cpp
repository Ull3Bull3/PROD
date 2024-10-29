// Fill out your copyright notice in the Description page of Project Settings.


#include "ReadWriteJsonFile.h"

#include "JsonObjectConverter.h"
#include "ReadWriteTextFile.h"


FPlayTestVariableStruct UReadWriteJsonFile::ReadStructFromJsonFile(FString Path)
{
	TSharedPtr<FJsonObject> JsonObject = ReadJson(Path);

	if (JsonObject == nullptr)
	{
		return FPlayTestVariableStruct();
	}

	FPlayTestVariableStruct ReturnStruct;

	if (!FJsonObjectConverter::JsonObjectToUStruct<FPlayTestVariableStruct>(JsonObject.ToSharedRef(), &ReturnStruct))
	{
		return FPlayTestVariableStruct();
	}

	return ReturnStruct;
}

void UReadWriteJsonFile::WriteStructToJsonFile(FString Path, FPlayTestVariableStruct Struct)
{
	TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject(Struct);

	if (JsonObject == nullptr)
	{
		return;
	}

	WriteJson(Path,JsonObject);
}


TSharedPtr<FJsonObject> UReadWriteJsonFile::ReadJson(FString Path)
{
	FString JsonString = UReadWriteTextFile::ReadStringFromFile(Path);
	if (JsonString.IsEmpty())
	{
		return nullptr;
	}

	TSharedPtr<FJsonObject> ReturnedJsonObject;

	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(JsonString), ReturnedJsonObject))
	{
		return nullptr;
	}

	return ReturnedJsonObject;
}

void UReadWriteJsonFile::WriteJson(FString Path, TSharedPtr<FJsonObject> JsonObject)
{
	FString JsonString;

	if (!FJsonSerializer::Serialize(JsonObject.ToSharedRef(), TJsonWriterFactory<>::Create(&JsonString, 0)))
	{
		return;
	}

	UReadWriteTextFile::WriteStringToFile(Path, JsonString);
}
