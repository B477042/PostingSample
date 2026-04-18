#pragma once
#include "IGasPresenter.h"
#include "GAS/Ability/BaseGameplayAbility.h"


class IGasView
{
public:
	IGasView();
	virtual ~IGasView(){}
	
	virtual void Initialize() = 0;
	virtual const TArray<TSubclassOf<UBaseGameplayAbility>> ReqLoadPlayerDefaultAbility() = 0;
};
