// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Key_Pickup.generated.h"

UCLASS()
class PROD_UE_API AKey_Pickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKey_Pickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	bool GetActive();

	void Touched();

	UPROPERTY(EditAnywhere, Category="Item")
	FString name;
	
	UPROPERTY(EditAnywhere, Category="Item")
	int amount;
	
	UPROPERTY(VisibleAnywhere, Category="Item")
	class UStaticMeshComponent* itemMesh;
	
	UPROPERTY()
	bool isInvisible;
};
