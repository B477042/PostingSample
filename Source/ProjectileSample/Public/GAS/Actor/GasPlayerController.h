// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerController.h"
#include "GasPlayerController.generated.h"

class AGasCameraActor;
class UPlayerInputDataAsset;
class UInputMappingContext;
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
	TWeakObjectPtr<UPlayerInputDataAsset> GetPlayerInputDataAsset() const;
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE AGasCameraActor* GetCameraActor() const;
	
protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input", meta=(AllowPrivateAccess="true"))
	TSoftObjectPtr<UInputMappingContext> CommonPlayerInputContext;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category="Input", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UPlayerInputDataAsset> DA_PlayerInputData;
	
	// OnPossessを初めて呼び出したら生成します。
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera",meta=(AllowPrivateAccess="true"))
	TObjectPtr<AGasCameraActor> CameraActor;
};
