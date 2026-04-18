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
	TWeakPtr<FSystemHolder> systemHolder = FSystemHolder::Get();
	
	gasPresenterWeakPtr = systemHolder.Pin()->GetSystem<IGasPresenter>();
}


const TArray<TSubclassOf<UBaseGameplayAbility>> FGasView::ReqLoadPlayerDefaultAbility()
{
	TArray<TSubclassOf<UBaseGameplayAbility>> retVal;
	//
	if (TSharedPtr<IGasPresenter> gasPresenter = gasPresenterWeakPtr.Pin())
	{
		retVal = gasPresenter->GetPlayerDefaultAbility();
		
	}
	
	
	return MoveTemp(retVal);
}
