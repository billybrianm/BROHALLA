// Fill out your copyright notice in the Description page of Project Settings.

#include "HeroCamera.h"

// Sets default values
AHeroCamera::AHeroCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHeroCamera::BeginPlay()
{
	Super::BeginPlay();

	this->PlayerController = this->GetWorld()->GetFirstPlayerController();
	if (this->PlayerController && this->ViewTarget)
	{
		this->PlayerController->SetViewTarget(this->ViewTarget);
	}
}

// Called every frame
void AHeroCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}