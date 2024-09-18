// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vase.generated.h"

UCLASS()
class PROD_UE_API AVase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Wobble();

	UFUNCTION(BlueprintCallable)
	void Break();
	
private:
	UPROPERTY(EditAnywhere)
	USoundBase* WobbleSound;

	UPROPERTY(EditAnywhere)
	USoundBase* BreakSound;
	
	UPROPERTY(VisibleAnywhere)
	bool IsWobbling;

	UPROPERTY(VisibleAnywhere)
	bool IsBroken;
};
