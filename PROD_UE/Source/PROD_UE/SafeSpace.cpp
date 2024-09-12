// Fill out your copyright notice in the Description page of Project Settings.


#include "SafeSpace.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASafeSpace::ASafeSpace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MySphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere");
	MySphereComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASafeSpace::BeginPlay()
{
	Super::BeginPlay();
 
	//MySphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ASafeSpace::BeginOverlap);
	//MySphereComponent->OnComponentEndOverlap.AddDynamic(this, &ASafeSpace::EndOverlap);
}

// Called every frame
void ASafeSpace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Is player safe? %s"), bIsPlayerOverlapping? TEXT("TRUE") : TEXT("FALSE"));
}

void ASafeSpace::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult &SweepResult)
{
	if (OtherActor == Cast<AActor>(UGameplayStatics::GetPlayerPawn(this, 0)))
	{
		bIsPlayerOverlapping = true;
	}
}

void ASafeSpace::EndOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex)
{
	if (OtherActor == Cast<AActor>(UGameplayStatics::GetPlayerPawn(this, 0)))
	{
		bIsPlayerOverlapping = false;
	}
}