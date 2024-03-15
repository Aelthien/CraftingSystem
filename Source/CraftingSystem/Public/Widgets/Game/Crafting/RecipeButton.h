// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RecipeButton.generated.h"

class UTextBlock;
class UButton;
class URecipeDefinition;

UCLASS()
class CRAFTINGSYSTEM_API URecipeButton : public UUserWidget
{
	GENERATED_BODY()

public:

	URecipeButton(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	void SetRecipe(const TSoftObjectPtr<URecipeDefinition>& InRecipeDefinition);

	void Clear();

private:

	UPROPERTY(meta = (BindWidget))
	UButton* RecipeButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* RecipeName;

	UPROPERTY()
	URecipeDefinition* RecipeDefinition;

	UFUNCTION()
	void OnRecipeButtonClicked();
};
