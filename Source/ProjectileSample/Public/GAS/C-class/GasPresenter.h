#pragma once
#include "Interface/IGasPresenter.h"


class FGasPresenter : public TSharedFromThis<FGasPresenter>, public IGasPresenter
{
public:
	FGasPresenter();

	virtual ~FGasPresenter() override;
	
	virtual void Initialize() override;
	virtual TArray<TSubclassOf<UBaseGameplayAbility>> GetPlayerDefaultAbility() override;

private:
	
	
	TWeakPtr<IGasModel> gasModelWeakPtr;
	TWeakPtr<IGasView> gasViewWeakPtr;
};
