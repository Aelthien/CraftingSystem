// Fill out your copyright notice in the Description page of Project Settings.

#include "CraftingSystem/Public/Entities/GameObject.h"

AGameObject::AGameObject()
{
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	RootComponent = MeshComponent;
}

void AGameObject::BeginPlay()
{
	Super::BeginPlay();

	OnClicked.AddDynamic(this, &AGameObject::OnObjectClicked);
}

void AGameObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGameObject::OnObjectClicked(AActor* ClickedActor, FKey ButtonPressed)
{
	
}