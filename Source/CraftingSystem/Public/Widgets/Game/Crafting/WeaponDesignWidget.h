﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WeaponDesignWidget.generated.h"

class UImage;

UCLASS()
class CRAFTINGSYSTEM_API UWeaponDesignWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UImage* WeaponView;
};