// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SamplePlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class PROJECTILESAMPLE_API ASamplePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ASamplePlayerController();
	
	virtual void OnPossess(APawn* InPawn) override;

protected:
	UPROPERTY(BlueprintReadWrite,EditAnywhere,meta=(AllowPrivateAccess=true),Category="Input")
	TSoftObjectPtr<UInputMappingContext> pawnKeyMapping;
	
	
};
