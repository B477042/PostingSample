// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Player/GasPlayerState.h"

#include "GAS/GasComponent.h"
#include "GAS/Attribute/GasBasicAttributeSet.h"

//#define GETTER_CODE_MACRO

AGasPlayerState::AGasPlayerState()
{
	gasComponent = CreateDefaultSubobject<UGasComponent>(TEXT("GasComponent"));
	gasBasicAttributeSet = CreateDefaultSubobject<UGasBasicAttributeSet>(TEXT("GasBasicAttributeSet"));
}

UAbilitySystemComponent* AGasPlayerState::GetAbilitySystemComponent() const
{
	return gasComponent;
}

UGasBasicAttributeSet* AGasPlayerState::GetAttributeSet() const
{
	return gasBasicAttributeSet;
}

void AGasPlayerState::BeginPlay()
{
	Super::BeginPlay();
}

void AGasPlayerState::bindAttributesChangedDelegate()
{
	//gasComponent->value
}

int32 AGasPlayerState::GetHealthPoint() const
{
	return gasBasicAttributeSet->GetHealthPoint();
}

void AGasPlayerState::OnHealthPointChanged(const FOnAttributeChangeData& Data)
{
	
}