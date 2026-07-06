// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Actor/Animation/GasCharacterAnimInstance.h"

#include "GAS/Actor/Component/GasCharacterMovementComponent.h"


UGasCharacterAnimInstance::UGasCharacterAnimInstance()
{
}

void UGasCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	AActor* owingActor = GetOwningActor();
	if (!owingActor)
	{
		return;
	}
	
	characterMovementComponent = owingActor->GetComponentByClass<UGasCharacterMovementComponent>();
	if (!characterMovementComponent)
	{
		return;
	}
}



void UGasCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	if (characterMovementComponent)
	{
		CurrentAcceleration = characterMovementComponent->GetCurrentAcceleration();
		CurrentSpeed = characterMovementComponent->Velocity.Size();
	}
}

float UGasCharacterAnimInstance::GetCurrentSpeed()
{
	return characterMovementComponent ? CurrentSpeed : 0.f;
}
