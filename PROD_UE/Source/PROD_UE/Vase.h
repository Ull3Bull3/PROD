// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/StaticMeshComponent.h"
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
	void Wobble(UCharacterMovementComponent* CharacterMovementComponent);

	UFUNCTION(BlueprintCallable)
	void Fall(UCharacterMovementComponent* CharacterMovementComponent);

	UFUNCTION(BlueprintCallable)
	void Catch(UCharacterMovementComponent* CharacterMovementComponent);

	UFUNCTION(BlueprintCallable)
	void Break(UCharacterMovementComponent* CharacterMovementComponent);

	void Conclusion();

	// Reference to the static mesh component of the vase
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* VaseMeshComponent;
	
private:
	UPROPERTY(EditAnywhere)
	USoundBase* WobbleSound;

	UPROPERTY(EditAnywhere)
	USoundBase* InteractableSound;

	UPROPERTY(EditAnywhere)
	USoundBase* CaughtSound;

	UPROPERTY(EditAnywhere)
	USoundBase* BreakSound;

	UPROPERTY(EditAnywhere)
	USoundBase* NotYetSound;

	UPROPERTY(EditAnywhere)
	USoundBase* GotchaSound;

	UPROPERTY(EditAnywhere)
	USoundBase* TooHastySound;

	UPROPERTY(EditAnywhere)
	USoundBase* TooSoonSound;

	UPROPERTY(EditAnywhere)
	float WobbleTime;
	
	UPROPERTY(EditAnywhere)
	float FallTime;

	UPROPERTY(EditAnywhere)
	float BreakTime;
	
	UPROPERTY(VisibleAnywhere)
	bool IsWobbling;
	
	UPROPERTY(VisibleAnywhere)
	bool IsFalling;

	UPROPERTY(VisibleAnywhere)
	bool IsCaught;

	UPROPERTY(VisibleAnywhere)
	bool IsBroken;

	UPROPERTY(VisibleAnywhere)
	bool InvalidCatch;

	FTimerHandle WobbleTimerHandle;
	FTimerHandle CatchTimerHandle;
	FTimerHandle BreakTimerHandle;
	
	UCharacterMovementComponent* PlayerCharacterMovementComponent;
};
