// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameAbilityDataAsset.generated.h"

class UBaseGameplayAbility;
/**
 * 
 */

UENUM(BlueprintType)
enum class E_GameAbilityType : uint8
{
	Default = 0,
	Sprint = 1,
	Jump = 2
};

UCLASS(Blueprintable)
class PROJECTILESAMPLE_API UGameAbilityDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UGameAbilityDataAsset();
	
	TSoftClassPtr<UBaseGameplayAbility> GetAbilityFromType(E_GameAbilityType Type);
	
protected:
	UPROPERTY(EditAnywhere,blueprintReadWrite,meta=(AllowPrivateAccess=true))
	TMap<E_GameAbilityType, TSoftClassPtr<UBaseGameplayAbility>> GasAbilityClasses;
};
