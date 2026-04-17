#pragma once
#include "IGasPresenter.h"
#include "GAS/Ability/BaseGameplayAbility.h"


class IGasView
{
public:
	IGasView();
	virtual ~IGasView(){}
	
	virtual void Initialize() = 0;
	virtual const TArray<UBaseGameplayAbility*> ReqLoadPlayerDefaultAbility() = 0;
};
