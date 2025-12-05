// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"


/**
 * 
 */

class  FMyActorDetail : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();
	
public:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
	
protected:
	void hideDefaultActorCategories(IDetailLayoutBuilder& DetailBuilder);
	
	void designDataCategory(IDetailLayoutBuilder& DetailBuilder);
};
