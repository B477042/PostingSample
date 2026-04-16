#pragma once
#include "Interface/IGasModel.h"

class FGasModel :  public TSharedFromThis<FGasModel> , public IGasModel 
{
public:
	FGasModel();
	virtual ~FGasModel() override;
	
	
	virtual void Initialize() override;
};
