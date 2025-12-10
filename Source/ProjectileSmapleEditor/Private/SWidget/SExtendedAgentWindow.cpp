// Fill out your copyright notice in the Description page of Project Settings.


#include "SWidget/SExtendedAgentWindow.h"

#include "Widgets/SCanvas.h"

FText MakeText(const FString& Text)
{
	return FText::FromString(Text);
}

SExtendedAgentInfoWidget::SExtendedAgentInfoWidget()
{
	Type = EWindowType::Normal;
	bIsPopupWindow = false;
	SizingRule = ESizingRule::Autosized;
	Title = MakeText(TEXT("Agent Info"));
	SetForegroundColor(FSlateColor(FLinearColor::Yellow));
	bHasCloseButton = true;
	bHasMaximizeButton = true;
	bHasMinimizeButton = true;
	bFocusWhenFirstShown = true;
	bIsPopupWindow = false;
	bCreateTitleBar = true;
	
}

SExtendedAgentInfoWidget::~SExtendedAgentInfoWidget()
{
}

TSharedRef<SExtendedAgentInfoWidget> SExtendedAgentInfoWidget::MakeExtendedAgentInfoWidget()
{
	TSharedRef<SExtendedAgentInfoWidget> newWindow = SNew(SExtendedAgentInfoWidget)
		.ClientSize(FVector2d(1024.f, 1024.f))
		[
			SNew(SBorder)
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("New Agent")))
			]
						
		];
	
	return newWindow;
}
