// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraMovement.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"

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

	ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
	
	screenValue = ViewportSize.X * percentage / 100;
}


// Called every frame
void UCameraMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	APlayerController* p = UGameplayStatics::GetPlayerController(this, 0);

	p->bShowMouseCursor = true;
	p->bEnableClickEvents = true;
	p->bEnableMouseOverEvents = true;

	float x, y;

	p->GetMousePosition(x, y);

	FVector Location = GetOwner()->GetActorLocation();
	
	if (!paused) 
	{
		if (x < screenValue)
		{
			Location -= FVector(Speed * DeltaTime, 0, 0);
		}
		if (x > ViewportSize.X - screenValue)
		{
			Location += FVector(Speed * DeltaTime, 0, 0);
		}
		if (y < screenValue)
		{
			Location -= FVector(0, Speed * DeltaTime, 0);
		}
		if (y > ViewportSize.Y - screenValue)
		{
			Location += FVector(0, Speed * DeltaTime, 0);
		}
	}
	GetOwner()->SetActorLocation(Location);
}

