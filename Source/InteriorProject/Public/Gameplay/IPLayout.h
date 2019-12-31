// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IPLayout.generated.h"

UCLASS()
class INTERIORPROJECT_API AIPLayout : public AActor
{
	GENERATED_UCLASS_BODY()
	
protected:
	//~ Start AActor Interface
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//~ End AActor Interface

protected:
	/** Layout Root Static Mesh Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Static Mesh")
	UStaticMeshComponent * LayoutStaticMesh;
	

};
