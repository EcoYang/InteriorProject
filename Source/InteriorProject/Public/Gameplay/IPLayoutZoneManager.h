// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "IPLayoutZoneManager.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogLayoutZoneManager, Log, All);

class AIPLayoutZone;

/**
 * 
 */
UCLASS(notplaceable, BlueprintType, Blueprintable, Transient, hideCategories = (Info, Rendering, MovementReplication, Replication, Actor))
class INTERIORPROJECT_API AIPLayoutZoneManager : public AInfo
{
	GENERATED_BODY()
	
protected:
	// Only Unique Value Is available
	UPROPERTY(Transient, BlueprintReadOnly, VisibleAnywhere, Category = "Zone")
	TSet<AIPLayoutZone*> SetOfLayoutZone;

public:
	// Register Zone on PostInitialize
	UFUNCTION(BlueprintCallable, Category = "Zone")
	void RegisterZone(AIPLayoutZone * LayoutZone);

protected:
	UFUNCTION()
	void DeregisterZone(AActor* Actor, EEndPlayReason::Type EndPlayReason);
}; 