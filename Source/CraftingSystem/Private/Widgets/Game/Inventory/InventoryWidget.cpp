// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/Game/Inventory/InventoryWidget.h"

#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Entities/ItemPickup.h"
#include "Widgets/Game/Items/ItemButton.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	static const ConstructorHelpers::FClassFinder<UItemButton> ItemButtonBPClass(TEXT("/Game/Widgets/Game/Items/WBP_ItemButton"));
	ItemButtonClass = ItemButtonBPClass.Class;
}

void UInventoryWidget::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
	
	for (int i = 0; i < ItemButtons.Num(); i++)
	{
		ItemButtons[i]->RemoveFromParent();
	}

	ItemButtons.Empty();
}

void UInventoryWidget::Show(const TArray<FInventoryItem>& Items)
{
	const int32 NumItems = Items.Num();
	
	for (int i = 0; i < NumItems; i++)
	{
		UItemButton* ItemButton = CreateWidget<UItemButton>(this, ItemButtonClass);

		ItemButton->SetItem(Items[i]);

		UVerticalBoxSlot* VerticalBoxSlot = ItemsList->AddChildToVerticalBox(ItemButton);
		
		VerticalBoxSlot->SetHorizontalAlignment(HAlign_Fill);
		VerticalBoxSlot->SetVerticalAlignment(VAlign_Top);
		VerticalBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));

		ItemButtons.Add(ItemButton);
	}
	
	SetVisibility(ESlateVisibility::Visible);
}

void UInventoryWidget::AddItem(const FInventoryItem& Item)
{
	if (!IsVisible())
	{
		return;
	}

	UItemButton* ItemButton = CreateWidget<UItemButton>(this, ItemButtonClass);

	ItemButton->SetItem(Item);
	
	UVerticalBoxSlot* VerticalBoxSlot = ItemsList->AddChildToVerticalBox(ItemButton);

	VerticalBoxSlot->SetHorizontalAlignment(HAlign_Fill);
	VerticalBoxSlot->SetVerticalAlignment(VAlign_Top);
	VerticalBoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));

	ItemButtons.Add(ItemButton);
}

void UInventoryWidget::RemoveItem(const FInventoryItem& Item)
{
	if (!IsVisible())
	{
		return;
	}
	
	for (int i = 0; i < ItemButtons.Num(); i++)
	{
		if (ItemButtons[i]->GetItem() == Item)
		{
			ItemButtons[i]->Clear();
			ItemButtons[i]->RemoveFromParent();
			ItemButtons.RemoveAt(i);
			break;
		}
	}
}