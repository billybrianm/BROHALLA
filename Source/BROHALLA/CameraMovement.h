// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraMovement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BROHALLA_API UCameraMovement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCameraMovement();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	float Speed = 5;

	UPROPERTY(EditAnywhere)
	bool paused = false;

	UPROPERTY(EditAnywhere)
	float percentage = 3.0f;
	
private:
	UPROPERTY()
	float screenValue;

	UPROPERTY()
	FVector2D ViewportSize;
};
