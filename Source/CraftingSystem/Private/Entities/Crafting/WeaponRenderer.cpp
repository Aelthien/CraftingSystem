// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponRenderer.h"

#include "Components/SceneCaptureComponent2D.h"


// Sets default values
AWeaponRenderer::AWeaponRenderer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = SceneCaptureComponent = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCaptureComponent"));
}

// Called when the game starts or when spawned
void AWeaponRenderer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponRenderer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

