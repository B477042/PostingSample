// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Actor/GasPlayerController.h"

#include "GAS/Actor/GasCharacter.h"

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

void AGasPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AGasPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	
}

void AGasPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
	
}
