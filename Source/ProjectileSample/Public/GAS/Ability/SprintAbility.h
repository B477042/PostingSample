// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseGameplayAbility.h"
#include "SprintAbility.generated.h"

class UGasCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class PROJECTILESAMPLE_API USprintAbility : public UBaseGameplayAbility
{
	GENERATED_BODY()
public:
	USprintAbility();
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr,
		FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;
	
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

public:
	virtual void CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility) override;
	virtual bool CanBeCanceled() const override;
	

private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=SprintAbility,meta=(AllowPrivateAccess = true))
	uint8 bIsActivating :1;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=SprintAbility,meta=(AllowPrivateAccess = true))
	TWeakObjectPtr<UGasCharacterMovementComponent> OwningMovementComponentWeakPtr;
};
