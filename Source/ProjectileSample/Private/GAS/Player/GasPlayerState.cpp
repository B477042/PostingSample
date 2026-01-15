// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Player/GasPlayerState.h"

#include "GAS/GasComponent.h"
#include "GAS/Attribute/GasBasicAttributeSet.h"

AGasPlayerState::AGasPlayerState()
{
	gasComponent = CreateDefaultSubobject<UGasComponent>(TEXT("GasComponent"));
	gasBasicAttributeSet = CreateDefaultSubobject<UGasBasicAttributeSet>(TEXT("GasBasicAttributeSet"));
}

UAbilitySystemComponent* AGasPlayerState::GetAbilitySystemComponent() const
{
	return gasComponent;
}
