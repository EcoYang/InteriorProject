// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/IPLayout.h"

#include <Components/StaticMeshComponent.h>

// Sets default values
AIPLayout::AIPLayout(const class FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{
	LayoutStaticMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Root Static Mesh"));
	RootComponent = LayoutStaticMesh;

	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AIPLayout::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIPLayout::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

