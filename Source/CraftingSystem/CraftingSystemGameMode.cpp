// Copyright Epic Games, Inc. All Rights Reserved.

#include "CraftingSystemGameMode.h"
#include "CraftingSystemPlayerController.h"
#include "CraftingSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Widgets/Game/GameHUD.h"

ACraftingSystemGameMode::ACraftingSystemGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ACraftingSystemPlayerController::StaticClass();

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}

	HUDClass = AGameHUD::StaticClass();
}