// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "TestGasAbility.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PROJECTILESAMPLE_API UTestGasAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	
	UTestGasAbility();
	
	virtual void ApplyAbilityTagsToGameplayEffectSpec(FGameplayEffectSpec& Spec,
		FGameplayAbilitySpec* AbilitySpec) const override;
	
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr,
		FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;
	
	virtual void CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility) override;
	
};
