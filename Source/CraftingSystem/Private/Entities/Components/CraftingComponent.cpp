// Fill out your copyright notice in the Description page of Project Settings.

#include "Entities/Components/CraftingComponent.h"

#include "Assets/CSAssetManager.h"
#include "Data/RecipeDefinition.h"
#include "Entities/Components/InventoryComponent.h"
#include "Widgets/Game/GameHUD.h"
#include "Widgets/Game/GameWidget.h"
#include "Widgets/Game/Crafting/CraftingWidget.h"

UCraftingComponent::UCraftingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCraftingComponent::AddRecipe(TSoftObjectPtr<URecipeDefinition> Recipe)
{
	Recipes.Add(Recipe);
	
	AGameHUD::GetInstance()->GameWidget->CraftingWidget->AddRecipe(Recipe);

	UE_LOG(LogTemp, Warning, TEXT("Recipe count: %d"), Recipes.Num());

	const FString Message = FString::Printf(TEXT("Recipe count: %d"), Recipes.Num());

	GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::White, Message);
}

bool UCraftingComponent::CraftRecipe(const TSoftObjectPtr<URecipeDefinition>& Recipe) const
{
	const URecipeDefinition* RecipeDefinition = UCSAssetManager::Get().LoadRecipeDefinition(Recipe);

	if (!InventoryComponent->HasItems(RecipeDefinition->RequiredItems.Items, true))
	{
		return false;
	}
	
	InventoryComponent->RemoveItems(RecipeDefinition->RequiredItems.Items);
	InventoryComponent->AddItems(RecipeDefinition->Products);

	return true;
}

void UCraftingComponent::BeginPlay()
{
	Super::BeginPlay();

	InventoryComponent = GetOwner()->FindComponentByClass<UInventoryComponent>();
}

void UCraftingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}