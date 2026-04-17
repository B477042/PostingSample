#include "SystemHolder.h"

#include "GasModel.h"
#include "GasPresenter.h"
#include "GasView.h"


FSystemHolder::FSystemHolder()
{
}

FSystemHolder::~FSystemHolder()
{
}

void FSystemHolder::InitSystemHolder() 
{
	TSharedPtr<FGasModel> sharedGasModel = MakeShared<FGasModel>();
	setSystem<IGasModel> ( sharedGasModel);
	
	TSharedPtr<FGasPresenter> sharedGasPresenter = MakeShared<FGasPresenter>();
	setSystem<IGasPresenter>(sharedGasPresenter);
	
	TSharedPtr<FGasView> sharedGasView = MakeShared<FGasView>();
	setSystem<IGasView>(sharedGasView);

	gasModel->Initialize();
	gasPresenter->Initialize();
	gasView->Initialize();
	
}

void FSystemHolder::ResetSystemHolder()
{
	gasModel.Reset();
	gasPresenter.Reset();
	gasView.Reset();
}

void FSystemHolder::setGasModel(TSharedPtr<IGasModel> newGasModel) 
{
	gasModel = newGasModel;
}

