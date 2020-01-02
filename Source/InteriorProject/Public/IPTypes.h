#pragma once

#include "CoreMinimal.h" 
#include <Engine/DataTable.h>
#include "IPTypes.generated.h"

class UStaticMesh;

UENUM(BlueprintType)
enum class EFurnitureType : uint8 
{
	EComfort,
	ESurface,
	EProps
};

USTRUCT(BlueprintType)
struct FFurnitureDB : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Furniture")
	FName FurnitureName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Furniture")
	UStaticMesh * FurnitureStaticMesh;
	 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Furniture")
	EFurnitureType FurnitureType;
};