// Fill out your copyright notice in the Description page of Project Settings.

#include "Entities/ItemPickup.h"

#include "Entities/Components/InventoryComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/Game/GameHUD.h"
#include "Widgets/Game/GameWidget.h"
#include "Widgets/Game/Inventory/InventoryWidget.h"

AItemPickup::AItemPickup()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AItemPickup::BeginPlay()
{
	Super::BeginPlay();
}

void AItemPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItemPickup::OnObjectClicked(AActor* ClickedActor, FKey ButtonPressed)
{
	UInventoryComponent* InventoryComponent = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->FindComponentByClass<UInventoryComponent>();

	InventoryComponent->AddItem(Item);

	Destroy();
}