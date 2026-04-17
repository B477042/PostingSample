#include "GasView.h"

#include "SystemHolder.h"


FGasView::FGasView()
{
}

FGasView::~FGasView()
{
	gasPresenterWeakPtr.Reset();
}

void FGasView::Initialize()
{
	//gasPresenterWeakPtr = GasPresenter;
}


const TArray<UBaseGameplayAbility*> FGasView::ReqLoadPlayerDefaultAbility()
{
	TArray<UBaseGameplayAbility*> retVal;
	//
	if (TSharedPtr<IGasPresenter> gasPresenter = gasPresenterWeakPtr.Pin())
	{
		retVal = gasPresenter->GetPlayerDefaultAbility();
		
	}
	
	
	return MoveTemp(retVal);
}
