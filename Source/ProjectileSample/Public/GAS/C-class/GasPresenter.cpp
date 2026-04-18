#include "GasPresenter.h"

#include "SystemHolder.h"
#include "Engine/AssetManager.h"
#include "GAS/GasGameInstance.h"
#include "GAS/DataAsset/GameAbilityDataAsset.h"
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
	TWeakPtr<FSystemHolder> systemHolder = FSystemHolder::Get();
	gasModelWeakPtr = systemHolder.Pin()->GetSystem<IGasModel>();
	gasViewWeakPtr = systemHolder.Pin()->GetSystem<IGasView>();
}

TArray<TSubclassOf<UBaseGameplayAbility>> FGasPresenter::GetPlayerDefaultAbility()
{
	TArray<TSubclassOf<UBaseGameplayAbility>> retVal;
	TSharedPtr<IGasModel> gasModel = gasModelWeakPtr.Pin();
	if (!gasModel.IsValid())
	{
		return MoveTemp(retVal);
	}
	
	TArray<E_GameAbilityType> defaultAbilityTypes = gasModel->GetPlayerDefaultAbilityType();
	// load ability type
	
	UGasGameInstance* gameInstance = UGasGameInstance::GetGameInstance();
	if (!gameInstance)
	{
		return MoveTemp(retVal);
	}
	TObjectPtr<UGameAbilityDataAsset> gameAbilityDataAsset = gameInstance->GetGasAbilityDataAsset();
	if (!gameAbilityDataAsset)
	{
		return MoveTemp(retVal);
	}
	
	for (const E_GameAbilityType abilityType :defaultAbilityTypes)
	{
		TSubclassOf<UBaseGameplayAbility>classPtr = gameAbilityDataAsset->GetAbilityFromType(abilityType);
		
	}
	
	
	return MoveTemp(retVal);
}
