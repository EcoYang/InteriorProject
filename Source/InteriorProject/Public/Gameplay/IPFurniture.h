// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IPFurniture.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class INTERIORPROJECT_API AIPFurniture : public AActor
{
	GENERATED_UCLASS_BODY()
	 
protected:
	//~ Start AActor Interface
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//~ End AActor Interface

protected:
	/** Furniture Static Mesh */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Static Mesh")
	UStaticMeshComponent * FurnitureStaticMesh; 

	/** Collision Component */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
	UBoxComponent * CollisionComponent;

};
