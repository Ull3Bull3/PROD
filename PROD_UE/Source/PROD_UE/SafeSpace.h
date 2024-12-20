// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"

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


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* MySphereComponent;
	
private:

	
	
	bool bIsPlayerOverlapping;
	
	//void BeginOverlap(AActor* OtherActor);
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult &SweepResult);

	UFUNCTION()
	void EndOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
};
