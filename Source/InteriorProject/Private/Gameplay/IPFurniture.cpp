// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/IPFurniture.h"

#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>

// Sets default values
AIPFurniture::AIPFurniture(const class FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{ 
	CollisionComponent  = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("Root Collision Component"));
	CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	RootComponent = CollisionComponent;

	FurnitureStaticMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Furniture Static Mesh"));
	FurnitureStaticMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	FurnitureStaticMesh->SetupAttachment(RootComponent);

	UpdateFurnitureBound();

	PrimaryActorTick.bCanEverTick = true;
}

void AIPFurniture::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UpdateFurnitureBound();
}

// Called when the game starts or when spawned
void AIPFurniture::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIPFurniture::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIPFurniture::UpdateFurnitureBound()
{
	if (!CollisionComponent) return;

	CollisionComponent->SetBoxExtent(GetComponentsBoundingBox().GetExtent(), false);
}

#if WITH_EDITOR
void AIPFurniture::PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent)
{
	const FName & PropertyName = PropertyChangedEvent.Property ? PropertyChangedEvent.GetPropertyName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(AIPFurniture, FurnitureStaticMesh) && FurnitureStaticMesh)
	{ 
		UpdateFurnitureBound();
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void AIPFurniture::PostEditMove(bool bFinished)
{
	if (bFinished)
	{ 
		UpdateFurnitureBound();
	}

	MarkComponentsRenderStateDirty();
	Super::PostEditMove(bFinished);
}

void AIPFurniture::PostEditUndo()
{
	Super::PostEditUndo();

	UpdateFurnitureBound();
}
#endif
