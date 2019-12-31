// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/IPLayoutZone.h"
#include "Gameplay/IPLayoutZoneManager.h"
#include "Online/IPGameModeBase.h"

#include <Components/BoxComponent.h>
#include <Math/UnrealMathUtility.h>

#if WITH_EDITORONLY_DATA
#include <Components/TextRenderComponent.h>
#endif
 
AIPLayoutZoneManager * AIPLayoutZone::s_ZoneManager = nullptr;
int32 AIPLayoutZone::s_InstanceIndex = 0;

// Sets default values
AIPLayoutZone::AIPLayoutZone(const class FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{
	ZoneLayout = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("Layout Zone Box"));
	ZoneLayout->InitBoxExtent(FVector(250.f));
	ZoneLayout->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ZoneLayout->SetShouldUpdatePhysicsVolume(false);
	RootComponent = ZoneLayout;

	LayoutName = NSLOCTEXT("LayoutZoneName", "LayoutZoneName", "Layout Zone Name");

#if WITH_EDITORONLY_DATA
	TextComponent = ObjectInitializer.CreateEditorOnlyDefaultSubobject<UTextRenderComponent>(this, TEXT("Text Components"));
	if (TextComponent) 
	{
		TextComponent->VerticalAlignment = EVerticalTextAligment::EVRTA_TextCenter;
		TextComponent->HorizontalAlignment = EHorizTextAligment::EHTA_Center;  
		TextComponent->WorldSize = 128.f;
		TextComponent->Text = LayoutName;
		TextComponent->SetupAttachment(RootComponent);
	}
#endif

	PrimaryActorTick.bCanEverTick = false;
}

void AIPLayoutZone::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UWorld* World = GetWorld();
	if (!World || !World->IsGameWorld()) return;
	
	++s_InstanceIndex;

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
	s_InstanceIndex = FMath::Max(0, s_InstanceIndex - 1);

	if (s_InstanceIndex <= 0)
	{
		s_ZoneManager = nullptr;
		return;
	}
}

#if WITH_EDITOR
void AIPLayoutZone::PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent)
{
	const FName & PropertyName = PropertyChangedEvent.Property ? PropertyChangedEvent.GetPropertyName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(AIPLayoutZone, LayoutName) && TextComponent)
	{
		TextComponent->Text = LayoutName;
	}	

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

