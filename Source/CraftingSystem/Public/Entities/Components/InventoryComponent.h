// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/RecipeDefinition.h"
#include "Entities/ItemPickup.h"
#include "InventoryComponent.generated.h"


class UInventoryWidget;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRAFTINGSYSTEM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UInventoryComponent();

	TArray<FInventoryItem> GetItems() const { return Items; }

	void AddItem(const FInventoryItem& InItem);
	void AddItems(const TArray<FInventoryItem>& InItems);

	bool RemoveItem(const FInventoryItem& InItem);
	void RemoveItems(const TArray<FInventoryItem>& InItems);
	
	bool HasItem(const FInventoryItem& InItem, bool bCheckQuantity = false);
	bool HasItems(const TArray<FInventoryItem>& InItems, bool bCheckQuantity = false);

protected:

	virtual void BeginPlay() override;

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	TArray<FInventoryItem> Items;
};