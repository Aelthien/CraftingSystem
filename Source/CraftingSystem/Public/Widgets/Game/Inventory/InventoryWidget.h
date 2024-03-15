// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Entities/ItemPickup.h"
#include "InventoryWidget.generated.h"

class UItemButton;
class UVerticalBox;

UCLASS()
class CRAFTINGSYSTEM_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UInventoryWidget(const FObjectInitializer& ObjectInitializer);

	void Show(const TArray<FInventoryItem>& Items);
	
	void Hide();
	void AddItem(const FInventoryItem& Item);

	void RemoveItem(const FInventoryItem& Item);

private:
	
	TSubclassOf<UUserWidget> ItemButtonClass;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* ItemsList;

	UPROPERTY()
	TArray<UItemButton*> ItemButtons;
};