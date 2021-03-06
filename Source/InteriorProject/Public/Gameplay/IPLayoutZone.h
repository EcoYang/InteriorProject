// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IPLayoutZone.generated.h"

class UBoxComponent;
class UTextRenderComponent;
class AIPLayoutZoneManager;

UCLASS()
class INTERIORPROJECT_API AIPLayoutZone : public AActor
{
	GENERATED_UCLASS_BODY()
	
protected:
	//~ Start AActor Interface
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	//~ End AActor Interface

protected:
	/** Root Component for Zone Layout */ 
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Zone")
	UBoxComponent * ZoneLayout;

#if WITH_EDITORONLY_DATA
	/** Text Component Renderer For Zone Layout */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Zone")
	UTextRenderComponent * TextComponent; 
#endif
protected:
	/** Layout Name in Text */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Zone")
	FText LayoutName;
	
private:
	//~ Static Values
	static int32 s_InstanceIndex;
	static AIPLayoutZoneManager* s_ZoneManager; 
	//~ End Static Values
};
