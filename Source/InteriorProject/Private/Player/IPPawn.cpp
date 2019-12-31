// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/IPPawn.h"

#include <GameFramework/PawnMovementComponent.h>
#include <GameFramework/FloatingPawnMovement.h>
#include <GameFramework/PlayerInput.h>
#include <GameFramework/PlayerController.h>
#include <Components/SphereComponent.h>

// Sets default values
AIPPawn::AIPPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision Component"));
	CollisionComponent->InitSphereRadius(35.0f); 

	CollisionComponent->CanCharacterStepUpOn = ECB_No;
	CollisionComponent->SetShouldUpdatePhysicsVolume(true);
	CollisionComponent->SetCanEverAffectNavigation(false);
	CollisionComponent->bDynamicObstacle = true;

	RootComponent = CollisionComponent;

	MovementComponent = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("Movement Component"));
	MovementComponent->UpdatedComponent = CollisionComponent;

	BaseLookUpRate = 45.f;
	MovementSpeed = 45.f;
}

// Called when the game starts or when spawned
void AIPPawn::BeginPlay()
{
	Super::BeginPlay();

	AddControllerPitchInput(25.f);
}

// Called every frame
void AIPPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AIPPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AIPPawn::MoveForward);
	PlayerInputComponent->BindAxis("LookUp", this, &AIPPawn::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &AIPPawn::Turn); 
}

void AIPPawn::MoveForward(float Scale)
{
	if (!FMath::IsNearlyZero(Scale, 0.02f) && !Controller)
	{
		return;
	}

	const FRotator & ControlSpaceRot = GetActorRotation(); 
	AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), MovementSpeed * Scale * GetWorld()->GetDeltaSeconds() * CustomTimeDilation);
}

void AIPPawn::Turn(float Scale)
{
}

void AIPPawn::LookUp(float Scale)
{
	AddControllerPitchInput(Scale * BaseLookUpRate * GetWorld()->GetDeltaSeconds() * CustomTimeDilation); 
}

void AIPPawn::RightClickMB()
{
}

