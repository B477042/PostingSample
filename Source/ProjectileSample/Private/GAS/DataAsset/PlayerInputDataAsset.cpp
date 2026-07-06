// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/DataAsset/PlayerInputDataAsset.h"

UPlayerInputDataAsset::UPlayerInputDataAsset()
{
}


const TObjectPtr<UInputAction> UPlayerInputDataAsset::GetInputAction(E_CommonPlayerInputType PlayerInputType) const 
{
	return InputContainer.Contains(PlayerInputType) ? InputContainer[PlayerInputType] : nullptr;
}
