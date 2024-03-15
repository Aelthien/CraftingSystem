// Fill out your copyright notice in the Description page of Project Settings.

#include "CraftingSystem/Public/Widgets/Game/Crafting/CraftingWidget.h"

#include "CraftingSystem/Public/Widgets/Game/Crafting/RecipeButton.h"

#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"

UCraftingWidget::UCraftingWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	static const ConstructorHelpers::FClassFinder<URecipeButton> RecipeButtonBPClass(TEXT("/Game/Widgets/Game/Crafting/WBP_RecipeButton"));
	RecipeButtonClass = RecipeButtonBPClass.Class;
}

void UCraftingWidget::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);

	const int32 NumRecipes = RecipeButtons.Num();
	
	for (int i = 0; i < NumRecipes; i++)
	{
		RecipeButtons[i]->RemoveFromParent();
	}

	RecipeButtons.Empty();
}

void UCraftingWidget::Show(const TArray<TSoftObjectPtr<URecipeDefinition>>& Recipes)
{
	const int32 NumRecipes = Recipes.Num();

	for (int i = 0; i < NumRecipes; i++)
	{
		URecipeButton* RecipeButton = CreateWidget<URecipeButton>(this, RecipeButtonClass);

		RecipeButton->SetRecipe(Recipes[i]);
		
		UVerticalBoxSlot* VerticalBoxSlot = RecipesList->AddChildToVerticalBox(RecipeButton);
		
		VerticalBoxSlot->SetHorizontalAlignment(HAlign_Fill);
		VerticalBoxSlot->SetVerticalAlignment(VAlign_Top);
		VerticalBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));

		RecipeButtons.Add(RecipeButton);
	}
	
	SetVisibility(ESlateVisibility::Visible);
}

void UCraftingWidget::AddRecipe(const TSoftObjectPtr<URecipeDefinition>& Recipe)
{
	if (!IsVisible())
	{
		return;
	}
	
	URecipeButton* RecipeButton = CreateWidget<URecipeButton>(this, RecipeButtonClass);

	RecipeButton->SetRecipe(Recipe);
	
	UVerticalBoxSlot* VerticalBoxSlot = RecipesList->AddChildToVerticalBox(RecipeButton);
	
	VerticalBoxSlot->SetHorizontalAlignment(HAlign_Fill);
	VerticalBoxSlot->SetVerticalAlignment(VAlign_Top);
	VerticalBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));

	RecipeButtons.Add(RecipeButton);
}