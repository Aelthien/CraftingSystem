// Fill out your copyright notice in the Description page of Project Settings.

#include "CraftingSystem/Public/Widgets/Game/Items/ItemButton.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "CraftingSystem/Public/Assets/CSAssetManager.h"
#include "CraftingSystem/Public/Data/RecipeDefinition.h"

void UItemButton::NativeConstruct()
{
	Super::NativeConstruct();

	ItemButton->OnClicked.AddDynamic(this, &UItemButton::OnItemButtonClicked);
}

void UItemButton::SetItem(const FInventoryItem& InItem)
{
	Item = InItem;
	ItemDefinition = UCSAssetManager::Get().LoadItemDefinition(InItem.ItemDefinition);

	ItemName->SetText(FText::FromString(ItemDefinition->Name));

	if (ItemDefinition->bIsStackable)
		ItemCount->SetText(FText::FromString(FString::FromInt(InItem.Quantity)));
}

void UItemButton::Clear()
{
	UCSAssetManager::Get().UnloadPrimaryAsset(ItemDefinition->GetPrimaryAssetId());

	ItemName->SetText(FText::FromString(""));
	ItemCount->SetText(FText::FromString(""));

	ItemDefinition = nullptr;
}

void UItemButton::OnItemButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ItemButtonClicked: %s"), *ItemDefinition->Name);
}
