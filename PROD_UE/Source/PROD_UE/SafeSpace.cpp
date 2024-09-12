// Fill out your copyright notice in the Description page of Project Settings.


#include "SafeSpace.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASafeSpace::ASafeSpace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASafeSpace::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASafeSpace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("Is Player safe? %s"), bIsPlayerOverlapping ?  TEXT("True") : TEXT("False"));
}

void ASafeSpace::BeginOverlap(AActor* OtherActor)
{
	if (OtherActor == Cast<AActor>(UGameplayStatics::GetPlayerPawn(this, 0)))
	{
		bIsPlayerOverlapping = true;
	}
}

void ASafeSpace::EndOverlap(AActor* OtherActor)
{
	if (OtherActor == Cast<AActor>(UGameplayStatics::GetPlayerPawn(this, 0)))
	{
		bIsPlayerOverlapping = false;
	}
}