// Fill out your copyright notice in the Description page of Project Settings.

#include "Entities/Components/InventoryComponent.h"

#include "Widgets/Game/GameHUD.h"
#include "Widgets/Game/GameWidget.h"
#include "Widgets/Game/Inventory/InventoryWidget.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInventoryComponent::AddItem(const FInventoryItem& Item)
{
	if (Items.Contains(Item))
	{
		Items[Items.Find(Item)].Quantity += Item.Quantity;
	}
	else
	{
		Items.Add(Item);
		AGameHUD::GetInstance()->GameWidget->InventoryWidget->AddItem(Item);
	}

	UE_LOG(LogTemp, Warning, TEXT("Items count: %d"), Items.Num());

	const FString Message = FString::Printf(TEXT("Item added: %s"), *Item.ItemDefinition.GetAssetName());

	GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::White, Message);
}

void UInventoryComponent::AddItems(const TArray<FInventoryItem>& InItems)
{
	for (const FInventoryItem& Item : InItems)
	{
		AddItem(Item);
	}
}

bool UInventoryComponent::RemoveItem(const FInventoryItem& InItem)
{
	if (Items.Contains(InItem))
	{
		FInventoryItem& Item = Items[Items.Find(InItem)];

		Item.Quantity -= InItem.Quantity;

		if (Item.Quantity <= 0)
		{
			Items.RemoveAt(Items.Find(InItem));
			AGameHUD::GetInstance()->GameWidget->InventoryWidget->RemoveItem(InItem);

			return true;
		}
	}

	return false;
}

void UInventoryComponent::RemoveItems(const TArray<FInventoryItem>& InItems)
{
	for (const FInventoryItem& Item : InItems)
	{
		RemoveItem(Item);
	}
}

bool UInventoryComponent::HasItem(const FInventoryItem& InItem, bool bCheckQuantity)
{
	if (!Items.Contains(InItem))
	{
		return false;
	}

	if (bCheckQuantity && Items[Items.Find(InItem)].Quantity < InItem.Quantity)
	{
		return false;
	}

	return true;
}

bool UInventoryComponent::HasItems(const TArray<FInventoryItem>& InItems, bool bCheckQuantity)
{
	for (const FInventoryItem& Item : InItems)
	{
		if (!HasItem(Item, bCheckQuantity))
		{
			return false;
		}
	}

	return true;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}