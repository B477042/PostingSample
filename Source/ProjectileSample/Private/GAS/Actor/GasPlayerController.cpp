// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Actor/GasPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "GAS/Actor/GasCharacter.h"
#include "GAS/DataAsset/PlayerInputDataAsset.h"

AGasPlayerController::AGasPlayerController()
{
}

UAbilitySystemComponent* AGasPlayerController::GetAbilitySystemComponent() const
{	
	if (AGasCharacter* gasChara  = Cast<AGasCharacter>(GetPawn()))
	{
		return gasChara->GetAbilitySystemComponent();
	}
	
	return nullptr;
}

TWeakObjectPtr<UPlayerInputDataAsset> AGasPlayerController::GetPlayerInputDataAsset() const
{
	return DA_PlayerInputData;
}

void AGasPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AGasPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	
	//この段階で入力設定を実行
	if (ULocalPlayer* localPlayer =  GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* localEISystem = localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			// 自分で作成したMappingContextを増加
			localEISystem->AddMappingContext(CommonPlayerInputContext.LoadSynchronous(),0);
			//
		}
	}
}

void AGasPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
	
}
