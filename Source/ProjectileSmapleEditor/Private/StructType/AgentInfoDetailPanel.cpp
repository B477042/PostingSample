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
	HeaderRow.NameContent()
	[
		PropertyHandle->CreatePropertyNameWidget()	
	]
	.ValueContent()
	[
		PropertyHandle->CreatePropertyValueWidget()
	];
	
}

void FAgentInfoDetailPanel::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle,
	IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	
}
