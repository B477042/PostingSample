// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Actor/GasCharacter.h"
// Sets default values
AGasCharacter::AGasCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGasCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGasCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGasCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* AGasCharacter::GetAbilitySystemComponent() const
{
	return abilitySystemComponent.Get();
}

void AGasCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (NewController->IsA(APlayerController::StaticClass()))
	{
		GetPlayerState();
	}
	
}

