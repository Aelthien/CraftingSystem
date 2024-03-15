// Fill out your copyright notice in the Description page of Project Settings.

#include "CraftingSystem/Public/Widgets/Game/Crafting/RecipeButton.h"

#include "Assets/CSAssetManager.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Data/RecipeDefinition.h"
#include "Entities/Components/CraftingComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

URecipeButton::URecipeButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void URecipeButton::NativeConstruct()
{
	Super::NativeConstruct();

	RecipeButton->OnClicked.AddDynamic(this, &URecipeButton::OnRecipeButtonClicked);
}

void URecipeButton::SetRecipe(const TSoftObjectPtr<URecipeDefinition>& InRecipeDefinition)
{
	RecipeDefinition = UCSAssetManager::Get().LoadRecipeDefinition(InRecipeDefinition);

	RecipeName->SetText(FText::FromString(RecipeDefinition->Name));
}

void URecipeButton::Clear()
{
	UCSAssetManager::Get().UnloadPrimaryAsset(RecipeDefinition->GetPrimaryAssetId());

	RecipeName->SetText(FText::FromString(""));

	RecipeDefinition = nullptr;
}

void URecipeButton::OnRecipeButtonClicked()
{
	UCraftingComponent* CraftingComponent = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->FindComponentByClass<UCraftingComponent>();

	if (CraftingComponent->CraftRecipe(RecipeDefinition))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Crafted recipe: %s"), *RecipeDefinition->Name));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Failed to craft recipe: %s"), *RecipeDefinition->Name));
	}
}