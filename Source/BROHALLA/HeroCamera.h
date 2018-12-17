// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HeroCamera.generated.h"

UCLASS()
class BROHALLA_API AHeroCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHeroCamera();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "View Target")
		AActor* ViewTarget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Controller")
		APlayerController* PlayerController;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
