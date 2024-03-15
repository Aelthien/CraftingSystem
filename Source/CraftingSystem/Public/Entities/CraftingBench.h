// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entities/GameObject.h"
#include "CraftingBench.generated.h"

class UCraftingComponent;

UCLASS()
class CRAFTINGSYSTEM_API ACraftingBench : public AGameObject
{
	GENERATED_BODY()

public:

	ACraftingBench();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

private:

	virtual void OnObjectClicked(AActor* ClickedActor, FKey ButtonPressed) override;
};