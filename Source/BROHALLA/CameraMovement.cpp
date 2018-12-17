// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraMovement.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UCameraMovement::UCameraMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCameraMovement::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCameraMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	APlayerController* p = UGameplayStatics::GetPlayerController(this, 0);

	float x, y;

	p->GetMousePosition(x, y);

	UE_LOG(LogTemp, Warning, TEXT("Teste: %f , %f"), x, y);

	FVector Location = GetOwner()->GetActorLocation();
	
	if (x < 50)
	{
		Location -= FVector(Speed * DeltaTime, 0, 0);
	}
	if (x > 1000)
	{
		Location += FVector(Speed * DeltaTime, 0, 0);
	}
	if (y < 50)
	{
		Location -= FVector(0, Speed * DeltaTime, 0);
	}
	if (y > 550)
	{
		Location += FVector(0, Speed * DeltaTime, 0);
	}
	GetOwner()->SetActorLocation(Location);
}

