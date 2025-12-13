#pragma once
#include "CoreMinimal.h"
#include "IDetailCustomization.h"


class FExtendedAgentWindowDetail : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();
	
public:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
		
};
