// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/IPLayoutZone.h"
#include "Gameplay/IPLayoutZoneManager.h"
#include "Online/IPGameModeBase.h"

#include <Components/BoxComponent.h>

#if WITH_EDITORONLY_DATA
#include <Components/TextRenderComponent.h>
#endif
 
AIPLayoutZoneManager * AIPLayoutZone::s_ZoneManager = nullptr;
uint32 AIPLayoutZone::s_InstanceIndex = 0;

// Sets default values
AIPLayoutZone::AIPLayoutZone(const class FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{
	ZoneLayout = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("Layout Zone Box"));
	ZoneLayout->InitBoxExtent(FVector(250.f));
	ZoneLayout->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ZoneLayout->SetShouldUpdatePhysicsVolume(false);
	RootComponent = ZoneLayout;

#if WITH_EDITORONLY_DATA
	TextComponent = ObjectInitializer.CreateEditorOnlyDefaultSubobject<UTextRenderComponent>(this, TEXT("Text Components"));
	if (TextComponent) 
	{
		TextComponent->VerticalAlignment = EVerticalTextAligment::EVRTA_TextCenter;
		TextComponent->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
		TextComponent->SetupAttachment(RootComponent);
	}
#endif

	PrimaryActorTick.bCanEverTick = true;
}

void AIPLayoutZone::PostInitializeComponents()
{
	++s_InstanceIndex;
	Super::PostInitializeComponents();

	UWorld* World = GetWorld();
	if (!World) return;

	AIPGameModeBase * IPGameMode = CastChecked<AIPGameModeBase>(World->GetAuthGameMode());

	if(!IsValid(s_ZoneManager))
	{
		s_ZoneManager = IPGameMode->GetZoneManager();
	}

	ensure(s_ZoneManager);
	s_ZoneManager->RegisterZone(this);
}

// Called when the game starts or when spawned
void AIPLayoutZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIPLayoutZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIPLayoutZone::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (s_InstanceIndex <= 0 || !IsValid(s_ZoneManager))
	{
		s_ZoneManager = nullptr;
		return;
	}

	--s_InstanceIndex;
}

