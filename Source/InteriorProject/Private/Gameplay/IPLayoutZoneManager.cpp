// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/IPLayoutZoneManager.h"
#include "Gameplay/IPLayoutZone.h"

DEFINE_LOG_CATEGORY(LogLayoutZoneManager);

void AIPLayoutZoneManager::RegisterZone(AIPLayoutZone * LayoutZone)
{
	if (!IsValid(LayoutZone)) return;

#if WITH_EDITOR
	for (AIPLayoutZone * Zone : SetOfLayoutZone) 
	{
		if (Zone != LayoutZone) continue;

		UE_LOG(LogLayoutZoneManager, Error, TEXT("(%s) : Existed in (%s)"), *Zone->GetName(), *GetName());
	}
#endif

	LayoutZone->OnEndPlay.AddDynamic(this, &AIPLayoutZoneManager::DeregisterZone);
	SetOfLayoutZone.Add(LayoutZone);
}

void AIPLayoutZoneManager::DeregisterZone(AActor * Zone, EEndPlayReason::Type EndPlayReason)
{
	if (!IsValid(Zone)) return;

	UE_LOG(LogLayoutZoneManager, Log, TEXT("Removing : ($s)"), *Zone->GetName() );
	SetOfLayoutZone.Remove(Cast<AIPLayoutZone>(Zone));
}
