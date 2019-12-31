// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/IPLayoutZone.h"
#include <Components/BoxComponent.h>

#if WITH_EDITORONLY_DATA
#include <Components/TextRenderComponent.h>
#endif

// Sets default values
AIPLayoutZone::AIPLayoutZone(const class FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{
	ZoneLayout = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("Layout Zone Box"));
	RootComponent = ZoneLayout;

#if WITH_EDITORONLY_DATA
	TextComponent = ObjectInitializer.CreateEditorOnlyDefaultSubobject<UTextRenderComponent>(this, TEXT("Text Components"));
	if (TextComponent) 
	{
		TextComponent->SetupAttachment(RootComponent);
	}
#endif

	PrimaryActorTick.bCanEverTick = true;
}

void AIPLayoutZone::PostInitializeComponents()
{
	Super::PostInitializeComponents();

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

