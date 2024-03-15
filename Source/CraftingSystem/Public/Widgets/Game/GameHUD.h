// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

class UGameWidget;

UCLASS()
class CRAFTINGSYSTEM_API AGameHUD : public AHUD
{
	GENERATED_BODY()

public:

	AGameHUD();

	static AGameHUD* GetInstance() { return Instance; }
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGameWidget* GameWidget;
	
protected:
	
	virtual void BeginPlay() override;

private:

	static AGameHUD* Instance;

	TSubclassOf<UGameWidget> GameWidgetClass;
};