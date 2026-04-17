#include "GasPresenter.h"

#include "SystemHolder.h"
#include "GAS/GasGameInstance.h"
#include "Kismet/GameplayStatics.h"

FGasPresenter::FGasPresenter()
{
}

FGasPresenter::~FGasPresenter()
{
	gasModelWeakPtr.Reset();
	gasViewWeakPtr.Reset();
}

void FGasPresenter::Initialize()
{
	// gasModelWeakPtr = gasModel;
	// gasViewWeakPtr = gasView;
}

TArray<UBaseGameplayAbility*> FGasPresenter::GetPlayerDefaultAbility()
{
	TArray<UBaseGameplayAbility*> retVal;
	TSharedPtr<IGasModel> gasModel = gasModelWeakPtr.Pin();
	if (!gasModel.IsValid())
	{
		return MoveTemp(retVal);
	}
	
	TArray<E_GameAbilityType> defaultAbilityTypes = gasModel->GetPlayerDefaultAbilityType();
	// load ability type
	
	return MoveTemp(retVal);
}
