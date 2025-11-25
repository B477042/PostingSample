// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileSmapleEditor/Public/ClassType/FMyActorDetail.h"

#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"

TSharedPtr<IDetailCustomization> FMyActorDetail::MakeInstance()
{
	return MakeShared<FMyActorDetail>();
}

void FMyActorDetail::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	//Get member that contains agents
	auto& it = DetailBuilder.EditCategory(TEXT("Agnets"));
	it.AddCustomRow(
		
	);
}

