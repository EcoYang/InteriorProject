// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "IPGameModeBase.generated.h"

class AIPLayoutZoneManager;

/**
 * 
 */
UCLASS()
class INTERIORPROJECT_API AIPGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	//~ Begin AActor Interface
	virtual void PreInitializeComponents() override;
	//~ End AActor Interface

protected: 
	/** Class of GameState associated with this GameMode. */
	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = Classes)
	TSubclassOf<AIPLayoutZoneManager> ZoneManagerClass;

	/** Zone Manager Instance */
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Zone")
	AIPLayoutZoneManager * ZoneManager;

public:
	/** Zone Managers */
	UFUNCTION(BlueprintPure, Category = "Zone")
	AIPLayoutZoneManager * GetZoneManager() const { return ZoneManager;  }

};
