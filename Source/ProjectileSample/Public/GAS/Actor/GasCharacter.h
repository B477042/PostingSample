// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "AbilitySystemInterface.h"

#include "GasCharacter.generated.h"

class UAttributeSetBase;

UCLASS(Blueprintable)
class PROJECTILESAMPLE_API AGasCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGasCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void PossessedBy(AController* NewController) override;

protected:
	// 原本はPlayerStateに存在しています。
	TWeakObjectPtr<UAbilitySystemComponent> abilitySystemComponent;
	TWeakObjectPtr<UAttributeSetBase> attributeSetBase;
};
