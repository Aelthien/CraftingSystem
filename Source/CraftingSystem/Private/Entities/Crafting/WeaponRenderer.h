// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponRenderer.generated.h"

UCLASS()
class CRAFTINGSYSTEM_API AWeaponRenderer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeaponRenderer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	USceneCaptureComponent2D* SceneCaptureComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};