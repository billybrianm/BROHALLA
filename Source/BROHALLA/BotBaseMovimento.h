// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "BotBaseMovimento.generated.h"

/**
 * 
 */
UCLASS()
class BROHALLA_API ABotBaseMovimento : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	ABotBaseMovimento();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float Speed = 20;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;	

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;
};
