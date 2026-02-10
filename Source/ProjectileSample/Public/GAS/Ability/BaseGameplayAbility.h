// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GAS/GasEnumDef.h"
#include "BaseGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTILESAMPLE_API UBaseGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UBaseGameplayAbility();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=TEXT("Ability"))
	E_GasAbilityInputID AbilityInputID = E_GasAbilityInputID::None;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=TEXT("Ability"))
	E_GasAbilityInputID AbilityID = E_GasAbilityInputID::None;
	
	
	
};
