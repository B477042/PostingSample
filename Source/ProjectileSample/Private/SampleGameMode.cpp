// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleGameMode.h"

#include "SamplePawn.h"
#include "SamplePlayerController.h"

ASampleGameMode::ASampleGameMode()
{
	DefaultPawnClass = ASamplePawn::StaticClass();
	PlayerControllerClass = ASamplePlayerController::StaticClass();
	
}
