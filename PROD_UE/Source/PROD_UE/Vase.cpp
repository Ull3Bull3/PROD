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
	
	if (UGameplayStatics::GetPlayerController(this, 0)->IsInputKeyDown(EKeys::F) && WobbleTimerHandle.IsValid() && PlayerCharacterMovementComponent)
	{
		InvalidCatch = true;
		Break(PlayerCharacterMovementComponent);
	}
	else if (UGameplayStatics::GetPlayerController(this, 0)->IsInputKeyDown(EKeys::F) && IsFalling && PlayerCharacterMovementComponent && !InvalidCatch)
		Catch(PlayerCharacterMovementComponent);
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
		switch(FMath::RandRange(0, 4))
		{
		case 0:
			UGameplayStatics::PlaySound2D(this, CloseOneSound);
			break;
		case 1:
			UGameplayStatics::PlaySound2D(this, GotchaSound);
			break;
		case 2:
			UGameplayStatics::PlaySound2D(this, IGotItSound);
			break;
		case 3:
			UGameplayStatics::PlaySound2D(this, SavedItSound);
			break;
		case 4:
			UGameplayStatics::PlaySound2D(this, StayThereSound);
			break;
		default:
			UE_LOG(LogTemp, Warning, TEXT("Hello World"));
		}
		GetWorld()->GetTimerManager().ClearTimer(CatchTimerHandle);
		VaseMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		CharacterMovementComponent->SetMovementMode(MOVE_Walking);
		IsCaught = true;
		IsFalling = false;
		InvalidCatch = false;
		GetWorld()->GetTimerManager().SetTimer(ConclusionTimerHandle, this, &AVase::Conclusion, ConclusionTime, false);
	}
}

void AVase::Break(UCharacterMovementComponent* CharacterMovementComponent)
{
	PlayerCharacterMovementComponent = CharacterMovementComponent;

	if (BreakSound && PlayerCharacterMovementComponent && VaseMeshComponent)
	{
		UGameplayStatics::PlaySoundAtLocation(this, BreakSound, GetActorLocation());
		GetWorld()->GetTimerManager().ClearTimer(WobbleTimerHandle);
		GetWorld()->GetTimerManager().ClearTimer(CatchTimerHandle);
		VaseMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		CharacterMovementComponent->SetMovementMode(MOVE_Walking);
		IsBroken = true;
		IsFalling = false;
		GetWorld()->GetTimerManager().SetTimer(ConclusionTimerHandle, this, &AVase::Conclusion, ConclusionTime, false);
	}
}

void AVase::Conclusion()
{
	if (IsCaught)
	{
		UGameplayStatics::PlaySoundAtLocation(this, CaughtSound, GetActorLocation());
	}
	else if (InvalidCatch)
	{
		switch(FMath::RandRange(0, 4))
		{
		case 0:
			UGameplayStatics::PlaySound2D(this, MissedItSound);
			break;
		case 1:
			UGameplayStatics::PlaySound2D(this, TimeItSound);
			break;
		case 2:
			UGameplayStatics::PlaySound2D(this, TooHastySound);
			break;
		case 3:
			UGameplayStatics::PlaySound2D(this, TooSoonSound);
			break;
		case 4:
			UGameplayStatics::PlaySound2D(this, TryAgainSound);
			break;
		default:
			UE_LOG(LogTemp, Warning, TEXT("Hello World"));
		}
	}
	
	GetWorld()->GetTimerManager().ClearTimer(ConclusionTimerHandle);
}
