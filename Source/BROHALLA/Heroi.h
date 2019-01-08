// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/InputComponent.h"
#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "CameraMovement.h"
#include "Heroi.generated.h"

UCLASS()
class BROHALLA_API AHeroi : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHeroi();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;

	UPROPERTY(EditAnywhere)
	UCameraComponent* OurCamera;

	UPROPERTY(VisibleAnywhere)
	UCameraMovement* pComponent;

	void Pause();
};
