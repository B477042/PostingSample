// Fill out your copyright notice in the Description page of Project Settings.


#include "SamplePawn.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Input/WeaponFireInputAction.h"

// Sets default values
ASamplePawn::ASamplePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASamplePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASamplePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASamplePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	TObjectPtr<UEnhancedInputComponent> inputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!inputComponent)
	{
		return;
	}
	
	 inputComponent->BindAction(inputAction,ETriggerEvent::Triggered,this,&ASamplePawn::OnClickMouse);
	//inputComponent->BindAction(FName(TEXT("IA_WeaponFire")),ETriggerEvent::Triggered,this,&ASamplePawn::OnClickMouse);
	//inputComponent->BindAction(nullptr,ETriggerEvent::Started,this,&ASamplePawn::OnClickMouse);

	
}

void ASamplePawn::OnClickMouse()
{
	// タイマーを確認
	GEngine->AddOnScreenDebugMessage(0,2.0f,FColor::Green,TEXT("OnClickMouse"));
}

