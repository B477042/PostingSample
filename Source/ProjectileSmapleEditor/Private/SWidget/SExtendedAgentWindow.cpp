// Fill out your copyright notice in the Description page of Project Settings.


#include "SWidget/SExtendedAgentWindow.h"

#include "DetailsViewObjectFilter.h"
#include "ISinglePropertyView.h"
#include "PropertyCustomizationHelpers.h"
#include "ClassType/AgentInfoList.h"
#include "ClassType/ExtendedAgentWindowDetail.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "StrcutType/AgentInfo.h"
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
	SetForegroundColor(FSlateColor(FLinearColor::Yellow));
	bHasCloseButton = true;
	bHasMaximizeButton = true;
	bHasMinimizeButton = true;
	bFocusWhenFirstShown = true;
	bCreateTitleBar = true;
	
	Title = MakeText(TEXT("Agent Info sadf"));
	CloseButtonToolTipText = MakeText(TEXT("This is from construct"));
	TitleBarSize = 64.f;
	
}

SExtendedAgentInfoWidget::~SExtendedAgentInfoWidget()
{
}

void SExtendedAgentInfoWidget::Construct(const FArguments&)
{
	if (UWorld* editorWorld = GEditor->GetEditorWorldContext().World())
	{
		agentInfoList = Cast<AAgentInfoList>(UGameplayStatics::GetActorOfClass(editorWorld,AAgentInfoList::StaticClass()));		
	}
	
	// detail panel
	FPropertyEditorModule& propertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs detailsViewArgs;
	detailsViewArgs.bUpdatesFromSelection = false;
	detailsViewArgs.bLockable            = false;
	detailsViewArgs.bAllowSearch         = false;
	detailsViewArgs.bHideSelectionTip    = true;

	
	
	agentInfoDetailView = propertyEditorModule.CreateDetailView(detailsViewArgs);
	//このクラスの転用レイアウトを適用
	agentInfoDetailView->RegisterInstancedCustomPropertyLayout(AAgentInfoList::StaticClass(),
	FOnGetDetailCustomizationInstance::CreateLambda([]()
	{
		return MakeShared<FExtendedAgentWindowDetail>();
	}));
	
	agentInfoDetailView->SetObject(agentInfoList.Get());
	

	
	SWindow::Construct(SWindow::FArguments()
		.ClientSize(FVector2D(1024.f,1024.f))
		.Title(MakeText(TEXT("Extended Agent Info")))
		
		[
			SNew(SBorder)
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.AutoHeight()
				[
					// SNew(STextBlock)
					// .Text(MakeText(TEXT("Show Agent Info")));
					
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot().FillWidth(1.f)
					[
						SNew(STextBlock)
						.Text(INVTEXT("Show Agent Info"))
					]
					
					+ SHorizontalBox::Slot().AutoWidth()
					[
						SNew(SButton)
						.Text(INVTEXT("Refresh"))
						
					]
					
					+ SHorizontalBox::Slot().AutoWidth()
					[
						SNew(SButton)
						.Text(INVTEXT("Close"))
						
					]
				] // top bar slot
				
				+SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SBorder)
					.ColorAndOpacity(FColor::Cyan)
					[
						agentInfoDetailView.ToSharedRef()
					]
					//SNew(STextBlock).Text(MakeText(TEXT("NOENO")))
				
					
				]		
			]
		]);
	
}

TSharedRef<SExtendedAgentInfoWidget> SExtendedAgentInfoWidget::MakeExtendedAgentInfoWidget()
{

	
	
	
	
	TSharedRef<SExtendedAgentInfoWidget> newWindow = SNew(SExtendedAgentInfoWidget);
		// .Title(MakeText(TEXT("Extended Agent Info")))		
		// .ClientSize(FVector2d(1024.f, 1024.f))
		//
		// [
		// 	SNew(SBorder)
		// 	[
		// 		SNew(SVerticalBox)
		// 		+SVerticalBox::Slot()
		// 		.AutoHeight()
		// 		[
		// 			// SNew(STextBlock)
		// 			// .Text(MakeText(TEXT("Show Agent Info")));
		// 			
		// 			SNew(SHorizontalBox)
		// 			+ SHorizontalBox::Slot().FillWidth(1.f)
		// 			[
		// 				SNew(STextBlock)
		// 				.Text(INVTEXT("Show Agent Info"))
		// 			]
		// 			
		// 			+ SHorizontalBox::Slot().AutoWidth()
		// 			[
		// 				SNew(SButton)
		// 				.Text(INVTEXT("Refresh"))
		// 				
		// 			]
		// 			
		// 			+ SHorizontalBox::Slot().AutoWidth()
		// 			[
		// 				SNew(SButton)
		// 				.Text(INVTEXT("Close"))
		// 				
		// 			]
		// 		] // top bar slot
		// 		
		// 		+SVerticalBox::Slot()
		// 		.FillHeight(1.f)
		// 		[
		// 			
		// 			
		// 			
		// 		]
		// 		
		// 		
		// 	]
		// 	
		// 				
		// ];
	
	return newWindow;
}
