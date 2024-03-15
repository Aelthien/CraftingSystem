// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CraftingWidget.generated.h"

class UWeaponDesignWidget;
class UVerticalBox;
class URecipeDefinition;
class URecipeButton;
class UButton;

UCLASS()
class CRAFTINGSYSTEM_API UCraftingWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UCraftingWidget(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(meta = (BindWidget))
	UWeaponDesignWidget* WeaponDesignWidget;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* RecipesList;

	UPROPERTY(meta = (BindWidget))
	UButton* CraftButton;

	UPROPERTY()
	TArray<URecipeButton*> RecipeButtons;

	void Hide();
	
	void Show(const TArray<TSoftObjectPtr<URecipeDefinition>>& Recipes);
	
	void AddRecipe(const TSoftObjectPtr<URecipeDefinition>& Recipe);

private:
	
	TSubclassOf<URecipeButton> RecipeButtonClass;
};