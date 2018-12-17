// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "BaianoCameraMgr.generated.h"

/**
 * 
 */
UCLASS()
class BROHALLA_API ABaianoCameraMgr : public APlayerCameraManager
{
	GENERATED_BODY()
	
public:
	ABaianoCameraMgr();
	virtual void Tick(float DeltaTime) override;

};
