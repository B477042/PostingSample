// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class AAgentInfoList;

class PROJECTILESAMPLEEDITOR_API SExtendedAgentInfoWidget : public SWindow
{
public:
	
	
SExtendedAgentInfoWidget();
	virtual ~SExtendedAgentInfoWidget() override;
public:
	SLATE_BEGIN_ARGS(SExtendedAgentInfoWidget)
		:_ClientSize( FVector2f::ZeroVector ){}
		SLATE_ARGUMENT( UE::Slate::FDeprecateVector2DParameter, ClientSize )
	SLATE_END_ARGS()
	void Construct(const FArguments&);
	
	static TSharedRef<SExtendedAgentInfoWidget> MakeExtendedAgentInfoWidget();
	
	//	TSharedPtr<ISinglePropertyView> agentInfoDetailView;
	TSharedPtr<IDetailsView> agentInfoDetailView;
	TWeakObjectPtr<AAgentInfoList> agentInfoList;
};
