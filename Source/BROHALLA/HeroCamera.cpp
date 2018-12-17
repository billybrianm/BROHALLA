// Fill out your copyright notice in the Description page of Project Settings.

#include "HeroCamera.h"

#include "Kismet/GameplayStatics.h"

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

	APlayerController* p = UGameplayStatics::GetPlayerController(this, 0);

	p->SetViewTarget(ViewTarget);
}

// Called every frame
void AHeroCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}