#pragma once
#include "Interface/IGasModel.h"

enum class E_GameAbilityType : uint8;

class FGasModel :  public TSharedFromThis<FGasModel> , public IGasModel 
{
public:
	FGasModel();
	virtual ~FGasModel() override;
	
	
	virtual void Initialize() override;

	virtual const TArray<E_GameAbilityType>& GetPlayerDefaultAbilityType() override;

private:
	TArray<E_GameAbilityType> defaultAbilityForPlayer;
	
};
