// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/Game/GameHUD.h"

#include "Blueprint/UserWidget.h"
#include "Widgets/Game/GameWidget.h"

AGameHUD* AGameHUD::Instance = nullptr;

AGameHUD::AGameHUD()
{
	static ConstructorHelpers::FClassFinder<UGameWidget> GameWidgetBPClass(TEXT("/Game/Widgets/Game/WBP_GameWidget"));
	GameWidgetClass = GameWidgetBPClass.Class;
}

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	Instance = this;

	GameWidget = CreateWidget<UGameWidget>(GetWorld(), GameWidgetClass);
	GameWidget->AddToViewport();
}
