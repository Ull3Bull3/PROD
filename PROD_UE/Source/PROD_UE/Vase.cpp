// Fill out your copyright notice in the Description page of Project Settings.


#include "Vase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

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

	if (WobbleTime > 0.0f && IsWobbling)
	{
		WobbleTime = UKismetMathLibrary::Clamp(WobbleTime - UGameplayStatics::GetWorldDeltaSeconds(this), 0.0, WobbleTime);
		
		if (UGameplayStatics::GetPlayerController(this, 0)->IsInputKeyDown(EKeys::F))
		{
			Save();
			WobbleTime = 0.0f;
		}
	}
	else if (IsWobbling && !IsBroken && WobbleTime <= 0.0f)
	{
		Break();
	}
}

void AVase::Wobble()
{
	if (WobbleSound && !IsBroken)
	{
		UGameplayStatics::PlaySoundAtLocation(this, WobbleSound, GetActorLocation());
		IsWobbling = true;
	}
}

void AVase::Save()
{
	if (SaveSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, SaveSound, GetActorLocation());
		IsWobbling = false;
		IsSaved = true;
	}
}

void AVase::Break()
{
	if (BreakSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, BreakSound, GetActorLocation());
		IsWobbling = false;
		IsBroken = true;
	}
}