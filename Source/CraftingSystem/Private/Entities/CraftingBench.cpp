// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/CraftingBench.h"

#include "Entities/Components/CraftingComponent.h"
#include "Entities/Components/InventoryComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/Game/GameHUD.h"
#include "Widgets/Game/GameWidget.h"
#include "Widgets/Game/Crafting/CraftingWidget.h"
#include "Widgets/Game/Inventory/InventoryWidget.h"

ACraftingBench::ACraftingBench()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACraftingBench::BeginPlay()
{
	Super::BeginPlay();
}

void ACraftingBench::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACraftingBench::OnObjectClicked(AActor* ClickedActor, FKey ButtonPressed)
{
	UE_LOG(LogTemp, Warning, TEXT("Clicked actor: %s"), *ClickedActor->GetName());
	
	const AGameHUD* GameHUD = AGameHUD::GetInstance();

	const ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	const UInventoryComponent* InventoryComponent = PlayerCharacter->FindComponentByClass<UInventoryComponent>();
	const UCraftingComponent* CraftingComponent = PlayerCharacter->FindComponentByClass<UCraftingComponent>();

	UE_LOG(LogTemp, Warning, TEXT("Recipe number: %d"), CraftingComponent->GetRecipes().Num());

	GameHUD->GameWidget->InventoryWidget->Show(InventoryComponent->GetItems());
	GameHUD->GameWidget->CraftingWidget->Show(CraftingComponent->GetRecipes());
}