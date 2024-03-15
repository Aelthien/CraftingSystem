// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entities/GameObject.h"
#include "ItemPickup.generated.h"

class UItemDefinition;

USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
	TSoftObjectPtr<UItemDefinition> ItemDefinition;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
	int32 Quantity;

	bool operator==(const FInventoryItem& Other) const
	{
		return ItemDefinition.GetAssetName() == Other.ItemDefinition.GetAssetName();
	}
};

UCLASS()
class CRAFTINGSYSTEM_API AItemPickup : public AGameObject
{
	GENERATED_BODY()

public:
	
	AItemPickup();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Crafting")
	FInventoryItem Item;

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

private:
	
	virtual void OnObjectClicked(AActor* ClickedActor, FKey ButtonPressed) override;
};