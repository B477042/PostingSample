// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "AbilitySystemInterface.h"

#include "GasCharacter.generated.h"

class UGasBasicAttributeSet;
struct FInputActionValue;


UCLASS(Blueprintable)
class PROJECTILESAMPLE_API AGasCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGasCharacter(const class FObjectInitializer& ObjectInitializer);
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
protected:
	// Input Actionへ対応して使える関数
	
	void onCommonWalk(const FInputActionValue& Value);
	void onCommonLook(const FInputActionValue& Value);
	void onCommonJump();
	void onCommonInteraction();
	protected:
	// 原本はPlayerStateに存在しています。
	TWeakObjectPtr<UAbilitySystemComponent> abilitySystemComponent;
	TWeakObjectPtr<UGasBasicAttributeSet> attributeSetBase;
	
protected:
	
};
