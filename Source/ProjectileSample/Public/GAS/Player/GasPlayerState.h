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
struct FOnAttributeChangeData;

#define ATTRIBUTE_CODE_GEN(GetterType, PropertyName) \
public: \
UFUNCTION(BlueprintCallable,Category="PlayerState|Attributes") \
GetterType Get##PropertyName() const; \
protected: \
FDelegateHandle On##PropertyNameChangedHandle; \
virtual void  On##PropertyName##Changed(const FOnAttributeChangeData& Data); \


UCLASS(Blueprintable)
class PROJECTILESAMPLE_API AGasPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AGasPlayerState();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UGasBasicAttributeSet* GetAttributeSet() const;
	
protected:
	virtual void BeginPlay() override;
	void bindAttributesChangedDelegate();
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="GAS")
	UGasComponent* gasComponent;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="GAS")
	UGasBasicAttributeSet* gasBasicAttributeSet;

	// Attribute Macro
	ATTRIBUTE_CODE_GEN(int32, HealthPoint)
};
