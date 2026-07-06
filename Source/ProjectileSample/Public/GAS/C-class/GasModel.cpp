#include "GasModel.h"

#include "GAS/DataAsset/GameAbilityDataAsset.h"

FGasModel::FGasModel()
{
}

FGasModel::~FGasModel()
{
}

void FGasModel::Initialize()
{
	defaultAbilityForPlayer.Add(E_GameAbilityType::Sprint);
}

const TArray<E_GameAbilityType>& FGasModel::GetPlayerDefaultAbilityType()
{
	return defaultAbilityForPlayer;
}


