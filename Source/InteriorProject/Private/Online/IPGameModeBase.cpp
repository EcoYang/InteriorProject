// Fill out your copyright notice in the Description page of Project Settings.


#include "Online/IPGameModeBase.h"
#include "Gameplay/IPLayoutZoneManager.h"
#include <Engine/World.h>

void AIPGameModeBase::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	 
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Instigator = GetInstigator();
	SpawnInfo.ObjectFlags |= RF_Transient;	// We never want to save game states or network managers into a map									

	// Fallback to default GameState if none was specified.
	if (ZoneManagerClass == nullptr)
	{
		UE_LOG(LogGameMode, Warning, TEXT("No ZoneManagerClass was specified in %s (%s)"), *GetName(), *GetClass()->GetName());
		ZoneManagerClass = AIPLayoutZoneManager::StaticClass();
	}

	UWorld* World = GetWorld();
	ZoneManager = World->SpawnActor<AIPLayoutZoneManager>(ZoneManagerClass, SpawnInfo);  
}