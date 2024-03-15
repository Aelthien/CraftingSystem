// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entities/GameObject.h"
#include "RecipePickup.generated.h"

class URecipeDefinition;

UCLASS()
class CRAFTINGSYSTEM_API ARecipePickup : public AGameObject
{
	GENERATED_BODY()

public:

	ARecipePickup();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Crafting")
	TSoftObjectPtr<URecipeDefinition> Recipe;

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	virtual void OnObjectClicked(AActor* ClickedActor, FKey ButtonPressed) override;
};
