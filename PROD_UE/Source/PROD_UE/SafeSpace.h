// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "SafeSpace.generated.h"


UCLASS()
class PROD_UE_API ASafeSpace : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASafeSpace();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool GetIsPlayerOverlapping() const{return bIsPlayerOverlapping;}
	
private:
	bool bIsPlayerOverlapping;
	
	void BeginOverlap(AActor* OtherActor);
	void EndOverlap(AActor* OtherActor);
};
