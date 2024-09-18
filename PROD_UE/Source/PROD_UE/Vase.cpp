// Fill out your copyright notice in the Description page of Project Settings.


#include "Vase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AVase::AVase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVase::Wobble()
{
	if (WobbleSound && !IsBroken)
	{
		IsWobbling = true;
		UGameplayStatics::PlaySoundAtLocation(this, WobbleSound, GetActorLocation());
	}
}

void AVase::Break()
{
	if (BreakSound)
	{
		IsWobbling = false;
		IsBroken = true;
		UGameplayStatics::PlaySoundAtLocation(this, BreakSound, GetActorLocation());
	}
}
