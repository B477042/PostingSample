#pragma once
#include "Interface/IGasView.h"



class FGasView : public TSharedFromThis<FGasView>, public IGasView
{
public:
	FGasView();
	virtual ~FGasView() override;

	virtual void Initialize() override;
	virtual const TArray<TSubclassOf<UBaseGameplayAbility>> ReqLoadPlayerDefaultAbility() override;
	
private:
	//circular referenceを防止するため
	//毎回、Presenterを呼ぶのはコーストが存在するから
	TWeakPtr<IGasPresenter> gasPresenterWeakPtr;
};
