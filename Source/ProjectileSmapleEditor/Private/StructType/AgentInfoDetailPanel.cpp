// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileSmapleEditor/Public/StructType/AgentInfoDetailPanel.h"

#include "DetailWidgetRow.h"

TSharedRef<IPropertyTypeCustomization> FAgentInfoDetailPanel::MakeInstance()
{
	return MakeShared<FAgentInfoDetailPanel>();
}

void FAgentInfoDetailPanel::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow,
	IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	TSharedRef<SWidget> nameWidget = PropertyHandle->CreatePropertyNameWidget();
	TSharedRef<SWidget> valueWidget = PropertyHandle->CreatePropertyValueWidget();
	nameWidget->SetToolTipText(FText::FromString(FString::Printf(TEXT("이것은 헤더여"))));
	valueWidget->SetToolTipText(FText::FromString(FString::Printf(TEXT("이것은 value"))));
	
	
	HeaderRow.NameContent()
	[
		nameWidget
		
	]
	.ValueContent()
	[
		valueWidget
	];
	
}

void FAgentInfoDetailPanel::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle,
	IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	
}

FAgentInfoDetailPanel::~FAgentInfoDetailPanel()
{
}
