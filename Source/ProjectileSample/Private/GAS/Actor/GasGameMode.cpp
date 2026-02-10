// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Actor/GasGameMode.h"

#include "GAS/Actor/GasCharacter.h"
#include "GAS/Actor/GasPlayerController.h"

AGasGameMode::AGasGameMode()
{
	DefaultPawnClass = AGasCharacter::StaticClass();
	PlayerControllerClass = AGasPlayerController::StaticClass();
	
}
