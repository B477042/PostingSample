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
	static TSharedPtr<IDetailCustomization> MakeInstance();
	
public:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
	
	
};
