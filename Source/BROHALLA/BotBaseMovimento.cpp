// Fill out your copyright notice in the Description page of Project Settings.

#include "BotBaseMovimento.h"

ABotBaseMovimento::ABotBaseMovimento() 
{
	PrimaryActorTick.bCanEverTick = true;	

	SetMobility(EComponentMobility::Movable);
}

void ABotBaseMovimento::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void ABotBaseMovimento::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JourneyTraveled = (Location - GlobalStartLocation).Size();

		if (JourneyTraveled >= JourneyLength)
		{
			FVector Swap = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = Swap;
		}
		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		Location += Direction * Speed * DeltaTime;
		SetActorLocation(Location);
	}
}


