// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemDefinition.h"
#include "CraftingSystem/Public/Assets/CSAssetManager.h"
#include "Engine/DataAsset.h"
#include "Entities/ItemPickup.h"
#include "RecipeDefinition.generated.h"

class UItemDefinition;

USTRUCT(BlueprintType)
struct FRequiredItems
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Recipe")
	TArray<FInventoryItem> Items;
};

UCLASS(BlueprintType)
class CRAFTINGSYSTEM_API URecipeDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
	FString Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
	TEnumAsByte<EItemCategory> Category;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
	TArray<FInventoryItem> Products;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Requirements")
	FRequiredItems RequiredItems;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override { return FPrimaryAssetId(UCSAssetManager::RecipeDefinition, GetFName()); }
};