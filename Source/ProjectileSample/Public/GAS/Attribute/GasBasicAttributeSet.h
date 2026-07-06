// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "GasBasicAttributeSet.generated.h"

/**
 * 
 */


#define ATTRIBUTE_ACCESSORS_WITH_REP(ClassName, PropertyCategory, PropertyName) \
public: \
UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=#PropertyCategory , ReplicatedUsing = OnRep_##PropertyName) \
FGameplayAttributeData PropertyName; \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) \
protected: \
UFUNCTION() \
virtual void OnRep_##PropertyName(const FGameplayAttributeData& old##PropertyName); \
public: \


#define ATTRIBUTE_ACCESSORS_WITH(ClassName, PropertyCategory, PropertyName) \
public: \
UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=#PropertyCategory) \
FGameplayAttributeData PropertyName; \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) \




UCLASS(Blueprintable)
class PROJECTILESAMPLE_API UGasBasicAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	public:
	UGasBasicAttributeSet();
	ATTRIBUTE_ACCESSORS_WITH_REP(UGasBasicAttributeSet, Health, HealthPoint)
	
	ATTRIBUTE_ACCESSORS_WITH_REP(UGasBasicAttributeSet, ActionPoint, ActionPoint)
	
};
