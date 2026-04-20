// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/DataAsset/GameAbilityDataAsset.h"

#include "GAS/Ability/BaseGameplayAbility.h"


UGameAbilityDataAsset::UGameAbilityDataAsset()
{
	
	
}

TSoftClassPtr<UBaseGameplayAbility> UGameAbilityDataAsset::GetAbilityFromType(E_GameAbilityType Type)
{
	return GasAbilityClasses[Type];
}
