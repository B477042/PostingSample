// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GasCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PROJECTILESAMPLE_API UGasCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UGasCharacterAnimInstance();
	
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	
	
};
