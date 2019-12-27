// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/IPPawn.h"

// Sets default values
AIPPawn::AIPPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIPPawn::BeginPlay()
{
	Super::BeginPlay();
	
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

}

