// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileSmapleEditor/Public/ClassType/FMyActorDetail.h"

#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "SWidget/SExtendedAgentWindow.h"

TSharedRef<IDetailCustomization> FMyActorDetail::MakeInstance()
{
	return MakeShareable(new FMyActorDetail);
}

void FMyActorDetail::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	//Get member that contains agents
	// auto& it = DetailBuilder.EditCategory(TEXT("Agnets"));
	// it.AddCustomRow(
	// 	
	// );
	hideDefaultActorCategories(DetailBuilder);
	
	// data category
	designDataCategory(DetailBuilder);
	
}

void FMyActorDetail::hideDefaultActorCategories(IDetailLayoutBuilder& DetailBuilder)
{
	TArray<FName> categoriesToHide;
	DetailBuilder.GetCategoryNames(categoriesToHide);
	for (const FName& category : categoriesToHide)
	{
		if (category == FName("Data"))
		{
			continue;
		}
		DetailBuilder.HideCategory(category);
	}
	 IDetailCategoryBuilder& transformCategory = DetailBuilder.EditCategory(FName("TransformCommon"));
	transformCategory.SetCategoryVisibility(false);
}

void FMyActorDetail::designDataCategory(IDetailLayoutBuilder& DetailBuilder)
{
	IDetailCategoryBuilder& dataCategoryBuilder = DetailBuilder.EditCategory(FName("Data"));
	IDetailsView* detailsview = DetailBuilder.GetDetailsView();
	
	
	dataCategoryBuilder.AddCustomRow(FText::FromString(FString::Printf(TEXT("따라ㄸㅏ라라라"))))
	.NameWidget
	[
		SNew(SButton)
		.Text(FText::FromString(TEXT("推してウィンドウをひろく")))
		.OnClicked_Lambda([]()->FReply
		{
			// TSharedRef<SWindow> newPopup = SNew(SWindow)
			// .Type(EWindowType::Normal)
			// .IsPopupWindow(false)
			// .SupportsMaximize(true)
			// .SupportsMinimize(true)
			// .HasCloseButton(true)
			// .CreateTitleBar(true)
			// .ClientSize(FVector2D(800.0f, 800.0f))
			// .Title(FText::FromString(TEXT("Hello")))
			// 	[
			// 		SNew(SBorder)
			// 		[
			// 			SNew(STextBlock)
			// 			.Text(FText::FromString(TEXT("Hellowindow")))
			// 		]
			// 	]
			// ; 
			TSharedRef<SExtendedAgentInfoWidget> newPopup = SExtendedAgentInfoWidget::MakeExtendedAgentInfoWidget();
			
			
			
			TSharedPtr<SWindow> ParentWindow = FSlateApplication::Get().FindBestParentWindowForDialogs(nullptr);
			ParentWindow.IsValid()?
			FSlateApplication::Get().AddWindowAsNativeChild(newPopup,ParentWindow.ToSharedRef()):
			FSlateApplication::Get().AddWindow(newPopup);
			
			return FReply::Handled();
		})
	]
	.ValueWidget	
	;
	
	IDetailPropertyRow& agentListPropertyRow= dataCategoryBuilder.AddProperty("AgentList");
	agentListPropertyRow.DisplayName(FText::FromString(FString::Printf(TEXT("CUSTOM NAME"))));
	TSharedPtr<IPropertyHandle> agentListPropertyHandle =  agentListPropertyRow.GetPropertyHandle();
	agentListPropertyHandle->SetPropertyDisplayName(FText::FromString(FString::Printf(TEXT("PropertyDisplayName"))));
	TSharedRef<SWidget> valuewidget = agentListPropertyHandle->CreatePropertyValueWidget();
	valuewidget=SNew(STextBlock).Text(FText::FromString(FString::Printf(TEXT("uwnfisik"))));
}

