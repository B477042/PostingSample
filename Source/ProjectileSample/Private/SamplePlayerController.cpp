// Fill out your copyright notice in the Description page of Project Settings.


#include "SamplePlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

ASamplePlayerController::ASamplePlayerController()
{
	
}

void ASamplePlayerController::OnPossess(APawn* InPawn)
{

	Super::OnPossess(InPawn);
	
	// Enhanced Input 初期化
	if (ULocalPlayer* localPlayer =  GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* localEISystem = localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			// 自分で作成したMappingContextを増加
			localEISystem->AddMappingContext(pawnKeyMapping.LoadSynchronous(),0);
			
		}
		
		
	}
		
	
}
