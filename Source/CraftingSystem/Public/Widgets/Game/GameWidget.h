// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameWidget.generated.h"

class UCraftingWidget;
class UInventoryWidget;

UCLASS()
class CRAFTINGSYSTEM_API UGameWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(meta = (BindWidget))
	UCraftingWidget* CraftingWidget;

	UPROPERTY(meta = (BindWidget))
	UInventoryWidget* InventoryWidget;
};