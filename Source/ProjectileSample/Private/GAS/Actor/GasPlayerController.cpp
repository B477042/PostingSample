// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Actor/GasPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Camera/CameraActor.h"
#include "GAS/Actor/GasCameraActor.h"
#include "GAS/Actor/GasCharacter.h"
#include "GAS/DataAsset/PlayerInputDataAsset.h"
#include "Kismet/GameplayStatics.h"

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

AGasCameraActor* AGasPlayerController::GetCameraActor() const
{
	return CameraActor;
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
	
	// カメラコンポーネントをつけてみましょう
	{
		if (CameraActor.IsNull())
		{
			const FTransform& transform = aPawn->GetTransform();
			CameraActor = Cast<AGasCameraActor>(GetWorld()->SpawnActor(AGasCameraActor::StaticClass()));
			//CameraActor->SetActorTransform(transform);
			
		}
		
		SetViewTarget(CameraActor);
		
		CameraActor->AttachToActor(aPawn,FAttachmentTransformRules::KeepWorldTransform);
		CameraActor->SetActorRelativeLocation(FVector(0.f,0.f,90.f));
	}
}

void AGasPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
	
	{
		CameraActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	}
}
