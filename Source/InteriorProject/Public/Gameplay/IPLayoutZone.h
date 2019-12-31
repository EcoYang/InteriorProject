// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IPLayoutZone.generated.h"

class UBoxComponent;
class UTextRenderComponent;

UCLASS()
class INTERIORPROJECT_API AIPLayoutZone : public AActor
{
	GENERATED_UCLASS_BODY()
	
protected:
	//~ Start AActor Interface
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//~ End AActor Interface

protected:
	// Root Component for Zone Layout
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Zone")
	UBoxComponent * ZoneLayout;

#if WITH_EDITORONLY_DATA
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Zone")
	UTextRenderComponent * TextComponent;

#endif

public:	

};
