// Fill out your copyright notice in the Description page of Project Settings.

#include "Heroi.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AHeroi::AHeroi()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//AutoPossessPlayer = EAutoReceiveInput::Player0;
	
	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	// Create a camera and a visible object
	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	// Attach our camera and visible object to our root component. Offset and rotate the camera.
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 900.0f));
	OurCamera->SetRelativeRotation(FRotator(-60.0f, -90.0f, 0.0f));
	OurVisibleComponent->SetupAttachment(RootComponent);
	
	pComponent = NewObject<UCameraMovement>(OurCamera);
	pComponent->Speed = 1000;
	OurVisibleComponent->SetStaticMesh();
}

// Called when the game starts or when spawned
void AHeroi::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeroi::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHeroi::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Pause", IE_Pressed, this, &AHeroi::Pause);
}

void AHeroi::Pause() 
{
	AActor* act = OurCamera->GetOwner();
	UCameraMovement* cammov = Cast<UCameraMovement>(act->GetComponentByClass(UCameraMovement::StaticClass()));
	cammov->paused = !cammov->paused;

	if (!cammov->paused) {
		UE_LOG(LogTemp, Warning, TEXT("Jogo despausado"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Jogo pausado"));
	}

}