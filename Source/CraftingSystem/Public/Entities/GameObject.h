// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameObject.generated.h"

UCLASS()
class CRAFTINGSYSTEM_API AGameObject : public AActor
{
	GENERATED_BODY()

public:

	AGameObject();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	UStaticMeshComponent* MeshComponent;

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

private:

	UFUNCTION()
	virtual void OnObjectClicked(AActor* ClickedActor, FKey ButtonPressed);
};