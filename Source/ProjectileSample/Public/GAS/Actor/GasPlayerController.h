// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerController.h"
#include "GasPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTILESAMPLE_API AGasPlayerController : public APlayerController, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AGasPlayerController();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;
};
