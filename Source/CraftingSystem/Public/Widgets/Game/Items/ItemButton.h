// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Entities/ItemPickup.h"
#include "ItemButton.generated.h"

class UTextBlock;
class UImage;
class URecipeDefinition;
class UButton;

UCLASS()
class CRAFTINGSYSTEM_API UItemButton : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void SetItem(const FInventoryItem& InItem);
	FInventoryItem& GetItem() { return Item; }

	void Clear();

private:

	UPROPERTY(meta = (BindWidget))
	UButton* ItemButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemCount;

	UPROPERTY()
	UItemDefinition* ItemDefinition;

	FInventoryItem Item;

	UFUNCTION()
	void OnItemButtonClicked();
};