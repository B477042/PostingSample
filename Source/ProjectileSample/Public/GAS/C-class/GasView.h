#pragma once
#include "Interface/IGasView.h"

class FGasView : public TSharedFromThis<FGasView>, public IGasView
{
public:
	FGasView();
	virtual ~FGasView() override;
	
	virtual void Initialize() override;
	virtual void OnLoadPlayerAbility() override;
};
