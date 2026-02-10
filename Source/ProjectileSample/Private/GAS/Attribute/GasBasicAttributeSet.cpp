// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Attribute/GasBasicAttributeSet.h"


#define REPFUNCTION_DEFINE(PropertyName) \
void UGasBasicAttributeSet::OnRep_##PropertyName(const FGameplayAttributeData& Old##PropertyName) \
{\
GAMEPLAYATTRIBUTE_REPNOTIFY(UGasBasicAttributeSet, ##PropertyName, Old##PropertyName); \
}\

UGasBasicAttributeSet::UGasBasicAttributeSet()
{
}

REPFUNCTION_DEFINE(HealthPoint)