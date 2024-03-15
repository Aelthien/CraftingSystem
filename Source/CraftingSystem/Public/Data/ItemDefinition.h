// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CraftingSystem/Public/Assets/CSAssetManager.h"
#include "Engine/DataAsset.h"
#include "ItemDefinition.generated.h"

UENUM(BlueprintType	)
enum EItemCategory
{
	IC_Weapon UMETA(DisplayName = "Weapon"),
	IC_Armor UMETA(DisplayName = "Armor"),
	IC_Consumable UMETA(DisplayName = "Consumable"),
	IC_Misc UMETA(DisplayName = "Misc"),
	IC_CraftingComponent UMETA(DisplayName = "CraftingComponent")
};

UCLASS(BlueprintType)
class CRAFTINGSYSTEM_API UItemDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "General")
	FString Name;

	UPROPERTY(EditAnywhere, Category = "General")
	FString Description;

	UPROPERTY(EditAnywhere, Category = "General")
	TEnumAsByte<EItemCategory> ItemCategory;

	UPROPERTY(EditAnywhere, Category = "General")
	bool bIsStackable;

	UPROPERTY(EditAnywhere, Category = "General")
	float Weight;

	UPROPERTY(EditAnywhere, Category = "General")
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, Category = "General")
	TSoftObjectPtr<UStaticMesh> Mesh;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override { return FPrimaryAssetId(UCSAssetManager::ItemDefinition, GetFName()); }};