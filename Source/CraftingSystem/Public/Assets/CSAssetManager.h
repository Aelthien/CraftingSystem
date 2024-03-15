// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "CSAssetManager.generated.h"

class URecipeDefinition;
class UItemDefinition;

UCLASS()
class CRAFTINGSYSTEM_API UCSAssetManager : public UAssetManager
{
	GENERATED_BODY()

	
public:
	
	static const FPrimaryAssetType ItemIcon;
	
	static const FPrimaryAssetType InputAction;

	static const FPrimaryAssetType StaticMesh;

	static const FPrimaryAssetType ItemDefinition;
	static const FPrimaryAssetType RecipeDefinition;
	
	UCSAssetManager();

	UTexture2D* LoadItemIcon(const FString& Name);
	
	UStaticMesh* LoadStaticMesh(const FString& Name);

	UItemDefinition* LoadItemDefinition(const TSoftObjectPtr<UItemDefinition>& Pointer);

	URecipeDefinition* LoadRecipeDefinition(const TSoftObjectPtr<URecipeDefinition>& Pointer);

	virtual void StartInitialLoading() override;

	static UCSAssetManager& Get();
	
	template <typename T>
	T* LoadAsset(const FString& AssetName, const FPrimaryAssetType& AssetType, const FStreamableDelegate& Delegate = FStreamableDelegate())
	{
		UObject* Asset = nullptr;
		TArray<FPrimaryAssetId> AssetIds;
		GetPrimaryAssetIdList(AssetType, AssetIds);

		for (FPrimaryAssetId AssetId : AssetIds)
		{
			if (AssetId.PrimaryAssetName.ToString().Equals(AssetName))
			{
				Asset = GetPrimaryAssetObject(AssetId);

				if (!Asset)
				{
					const FSoftObjectPath AssetPath = GetPrimaryAssetPath(AssetId);

					if (Delegate.IsBound())
					{
						StreamableManager.RequestAsyncLoad(AssetPath, Delegate);
					}
					else
					{
						Asset = StreamableManager.LoadSynchronous(AssetPath);
					}
				}

				break;
			}
		}

		return Cast<T>(Asset);
	}
};