// Fill out your copyright notice in the Description page of Project Settings.

#include "CraftingSystem/Public/Assets/CSAssetManager.h"

#include "CraftingSystem/Public/Data/ItemDefinition.h"
#include "CraftingSystem/Public/Data/RecipeDefinition.h"

const FPrimaryAssetType UCSAssetManager::ItemIcon(TEXT("ItemIcon"));

const FPrimaryAssetType UCSAssetManager::StaticMesh(TEXT("StaticMesh"));

const FPrimaryAssetType UCSAssetManager::ItemDefinition(TEXT("ItemDefinition"));
const FPrimaryAssetType UCSAssetManager::RecipeDefinition(TEXT("RecipeDefinition"));

UCSAssetManager::UCSAssetManager()
{
}

UTexture2D* UCSAssetManager::LoadItemIcon(const FString& Name)
{
	return LoadAsset<UTexture2D>("T_Icon_" + Name, ItemIcon);
}

UStaticMesh* UCSAssetManager::LoadStaticMesh(const FString& Name)
{
	return LoadAsset<UStaticMesh>("SM_" + Name, StaticMesh);
}

UItemDefinition* UCSAssetManager::LoadItemDefinition(const TSoftObjectPtr<UItemDefinition>& Pointer)
{
	return LoadAsset<UItemDefinition>(Pointer.GetAssetName(), ItemDefinition);
}

URecipeDefinition* UCSAssetManager::LoadRecipeDefinition(const TSoftObjectPtr<URecipeDefinition>& Pointer)
{
	return LoadAsset<URecipeDefinition>(Pointer.GetAssetName(), RecipeDefinition);
}

void UCSAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
}

UCSAssetManager& UCSAssetManager::Get()
{
	if (UCSAssetManager* This = Cast<UCSAssetManager>(GEngine->AssetManager))
	{
		return *This;
	}
	
	UE_LOG(LogTemp, Error, TEXT("Invalid AssetManager in DefaultEngine.ini, must be CSAssetManager"));
	
	return *NewObject<UCSAssetManager>();
}