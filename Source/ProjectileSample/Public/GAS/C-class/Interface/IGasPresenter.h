#pragma once
#include "IGasModel.h"
#include "IGasView.h"
#include "GAS/Ability/BaseGameplayAbility.h"


class IGasPresenter
{
public:
	IGasPresenter();
	virtual ~IGasPresenter(){}
	
	virtual void Initialize() = 0;
	
	virtual TArray<TSubclassOf<UBaseGameplayAbility>> GetPlayerDefaultAbility()=0;
};
