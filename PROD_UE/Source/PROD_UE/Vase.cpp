// Fill out your copyright notice in the Description page of Project Settings.


#include "Vase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AVase::AVase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and initialize the StaticMeshComponent
	VaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VaseMeshComponent"));
    
	// Set it as the RootComponent or attach to another component
	RootComponent = VaseMeshComponent;
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

	if (IsFalling && PlayerCharacterMovementComponent)
	{
		if (UGameplayStatics::GetPlayerController(this, 0)->IsInputKeyDown(EKeys::LeftControl))
		{
			Catch(PlayerCharacterMovementComponent);
		}
	}
}

void AVase::Wobble(UCharacterMovementComponent* CharacterMovementComponent)
{
	PlayerCharacterMovementComponent = CharacterMovementComponent;
	
	if (WobbleSound && !IsBroken && !IsCaught && PlayerCharacterMovementComponent)
	{
		PlayerCharacterMovementComponent->StopMovementImmediately();
		PlayerCharacterMovementComponent->DisableMovement();
		UGameplayStatics::PlaySoundAtLocation(this, WobbleSound, GetActorLocation());
		IsWobbling = true;
		FTimerDelegate WobbleTimerDelegate;
		WobbleTimerDelegate.BindUFunction(this, "Fall", PlayerCharacterMovementComponent);
		GetWorld()->GetTimerManager().SetTimer(WobbleTimerHandle, WobbleTimerDelegate,WobbleTime, false);
	}
}

void AVase::Fall(UCharacterMovementComponent* CharacterMovementComponent)
{
	PlayerCharacterMovementComponent = CharacterMovementComponent;
	
	if (InteractableSound && PlayerCharacterMovementComponent)
	{
		FTimerDelegate FallTimerDelegate;
		FallTimerDelegate.BindUFunction(this, "Break", CharacterMovementComponent);
		GetWorld()->GetTimerManager().SetTimer(CatchTimerHandle, FallTimerDelegate,FallTime, false);
		UGameplayStatics::PlaySoundAtLocation(this, InteractableSound, GetActorLocation());
		IsWobbling = false;
		IsFalling = true;
		GetWorld()->GetTimerManager().ClearTimer(WobbleTimerHandle);
	}
}

void AVase::Catch(UCharacterMovementComponent* CharacterMovementComponent)
{
	PlayerCharacterMovementComponent = CharacterMovementComponent;

	if (CaughtSound && PlayerCharacterMovementComponent && VaseMeshComponent)
	{
		UGameplayStatics::PlaySoundAtLocation(this, CaughtSound, GetActorLocation());
		IsCaught = true;
		GetWorld()->GetTimerManager().ClearTimer(CatchTimerHandle);
		IsFalling = false;
        
		// Disable collision for the vase's static mesh
		VaseMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		// Set the character's movement mode to walking
		CharacterMovementComponent->SetMovementMode(MOVE_Walking);
	}
}

void AVase::Break(UCharacterMovementComponent* CharacterMovementComponent)
{
	PlayerCharacterMovementComponent = CharacterMovementComponent;

	if (BreakSound && PlayerCharacterMovementComponent && VaseMeshComponent)
	{
		UGameplayStatics::PlaySoundAtLocation(this, BreakSound, GetActorLocation());
		IsBroken = true;
		GetWorld()->GetTimerManager().ClearTimer(CatchTimerHandle);
		IsFalling = false;
		VaseMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		CharacterMovementComponent->SetMovementMode(MOVE_Walking);
	}
}