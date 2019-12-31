// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IPPawn.generated.h"

class UPawnMovementComponent;
class USphereComponent;


UCLASS()
class INTERIORPROJECT_API AIPPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AIPPawn();

protected:
	//~ Start AActor Interface
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//~ End AActor Interface

protected:
	/** DefaultPawn movement component */
	UPROPERTY(Category = Pawn, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPawnMovementComponent* MovementComponent;

	/** DefaultPawn collision component */
	UPROPERTY(Category = Pawn, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USphereComponent* CollisionComponent;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void MoveForward(float Scale);
	void Turn(float Scale);
	void LookUp(float Scale);

	void RightClickMB();
protected:
	/** Base lookup rate, in deg/sec. Other scaling may affect final lookup rate. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn")
	float BaseLookUpRate; 

	/**  Movement Speed */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn")
	float MovementSpeed;
};
