// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerInputDataAsset.generated.h"

class UInputAction;
/**
 * 
 */

UENUM(Blueprintable)
enum E_CommonPlayerInputType:uint8
{
	None = 0 UMETA(DisplayName="None"),
	Walk = 1 UMETA(DisplayName="Walk"),
	Jump = 2 UMETA(DisplayName="Jump"),
	Look = 3 UMETA(DisplayName="Look"),
	Interaction = 4 UMETA(DisplayName="Interaction"),
	Sprint = 5 UMETA(DisplayName="Sprint")
	
};

UCLASS(Blueprintable)
class PROJECTILESAMPLE_API UPlayerInputDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPlayerInputDataAsset();
	
	const TObjectPtr<UInputAction> GetInputAction(E_CommonPlayerInputType PlayerInputType) const;
protected:

protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,meta=(AllowPrivateAccess = true))
	TMap<TEnumAsByte<E_CommonPlayerInputType>, TObjectPtr<UInputAction>>InputContainer;
};
