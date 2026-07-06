// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GasCharacterAnimInstance.generated.h"

class UGasCharacterMovementComponent;
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
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetCurrentSpeed();
	
private:
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Character",meta=(AllowPrivateAccess=true))
	TObjectPtr<UGasCharacterMovementComponent> characterMovementComponent;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="character",meta=(AllowPrivateAccess=true))
	FVector CurrentAcceleration;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="character",meta=(AllowPrivateAccess=true))
	float CurrentSpeed;
};
