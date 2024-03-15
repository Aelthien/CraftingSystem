// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CraftingComponent.generated.h"


class UInventoryComponent;
class URecipeDefinition;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRAFTINGSYSTEM_API UCraftingComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UCraftingComponent();

	TArray<TSoftObjectPtr<URecipeDefinition>> GetRecipes() const { return Recipes; }

	void AddRecipe(TSoftObjectPtr<URecipeDefinition> Recipe);

	bool CraftRecipe(const TSoftObjectPtr<URecipeDefinition>& Recipe) const;
	
protected:

	virtual void BeginPlay() override;

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY()
	TArray<TSoftObjectPtr<URecipeDefinition>> Recipes;

	UPROPERTY()
	UInventoryComponent* InventoryComponent;
};