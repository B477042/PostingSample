// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Ability/SprintAbility.h"

#include "AbilitySystemInterface.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GAS/GasComponent.h"
#include "GAS/Actor/Component/GasCharacterMovementComponent.h"

USprintAbility::USprintAbility()
{
	AbilityInputID = E_GasAbilityInputID::Sprint;
	AbilityID = E_GasAbilityInputID::Sprint;
	
}



bool USprintAbility::CanActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                        const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags,
                                        const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const
{
	const bool bSuperResult = Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
	if (!bSuperResult)
	{
		return false;
	}
	
	TStrongObjectPtr<AActor> ownerActor = ActorInfo->OwnerActor.Pin();
	if (!ownerActor.IsValid())
	{
		return false;
	}
	const IAbilitySystemInterface* ASI = Cast<IAbilitySystemInterface>(ownerActor.Get());
	TObjectPtr<UGasComponent> gasComponent = Cast<UGasComponent>( ASI->GetAbilitySystemComponent());
	return true;
}

void USprintAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);
	auto actorInfoMovement = ActorInfo->MovementComponent.Pin();
	if (actorInfoMovement.IsValid())
	{
		OwningMovementComponentWeakPtr = Cast<UGasCharacterMovementComponent>(actorInfoMovement.Get());
		if (OwningMovementComponentWeakPtr.IsValid())
		{
			// Log
			UE_LOG(LogTemp,Log,TEXT("SprintAbility Owning Component set"));
		}
	}
}

void USprintAbility::OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnRemoveAbility(ActorInfo, Spec);
	
	OwningMovementComponentWeakPtr.Reset();
}

void USprintAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                     const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                     const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	// 簡単にmovement　componentを値を操作しましょう。
	TStrongObjectPtr<UGasCharacterMovementComponent> movementComponent = OwningMovementComponentWeakPtr.Pin();
	if (!movementComponent.IsValid())
	{
		UE_LOG(LogTemp,Warning,TEXT("SprintAbility Movement Component is NULL"));
		return;
	}
	
	bIsActivating = true;
	// 
	
	//movementCompoennt->
	
}

void USprintAbility::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
	Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
}

bool USprintAbility::CanBeCanceled() const
{
	return Super::CanBeCanceled();
}