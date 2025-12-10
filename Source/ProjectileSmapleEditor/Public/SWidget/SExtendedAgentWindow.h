// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class PROJECTILESAMPLEEDITOR_API SExtendedAgentInfoWidget : public SWindow
{
public:
	
	
	SExtendedAgentInfoWidget();
	virtual ~SExtendedAgentInfoWidget() override;
public:
	static TSharedRef<SExtendedAgentInfoWidget> MakeExtendedAgentInfoWidget();
	
};