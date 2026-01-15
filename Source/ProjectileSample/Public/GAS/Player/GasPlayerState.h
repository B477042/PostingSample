// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "GasPlayerState.generated.h"

class UGasBasicAttributeSet;
class UGasComponent;
/**
 * 
 */
UCLASS(Blueprintable)
class PROJECTILESAMPLE_API AGasPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AGasPlayerState();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="GAS")
	UGasComponent* gasComponent;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="GAS")
	UGasBasicAttributeSet* gasBasicAttributeSet;
};
