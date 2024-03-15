// Fill out your copyright notice in the Description page of Project Settings.

#include "Entities/RecipePickup.h"

#include "Entities/Components/CraftingComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/Game/GameHUD.h"
#include "Widgets/Game/GameWidget.h"
#include "Widgets/Game/Crafting/CraftingWidget.h"

ARecipePickup::ARecipePickup()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARecipePickup::BeginPlay()
{
	Super::BeginPlay();
}

void ARecipePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARecipePickup::OnObjectClicked(AActor* ClickedActor, FKey ButtonPressed)
{
	UCraftingComponent* CraftingComponent = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->FindComponentByClass<UCraftingComponent>();

	UE_LOG(LogTemp, Warning, TEXT("Recipe added: %s"), *Recipe.GetAssetName());

	CraftingComponent->AddRecipe(Recipe);

	Destroy();
}