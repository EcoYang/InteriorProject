// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/IPFurniture.h"

#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>

// Sets default values
AIPFurniture::AIPFurniture(const class FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{ 
	CollisionComponent  = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("Root Collision Component"));
	CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	RootComponent = CollisionComponent;

	FurnitureStaticMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Furniture Static Mesh"));
	FurnitureStaticMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	FurnitureStaticMesh->SetupAttachment(RootComponent);

	CollisionComponent->InitBoxExtent(GetComponentsBoundingBox().GetExtent());

	PrimaryActorTick.bCanEverTick = true;
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

