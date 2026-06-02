// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Actor/Component/GasCharacterMovementComponent.h"


// Sets default values for this component's properties
UGasCharacterMovementComponent::UGasCharacterMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGasCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGasCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGasCharacterMovementComponent::StartSprinting()
{
	bIsSprinting = true;
}

void UGasCharacterMovementComponent::StopSprinting() 
{
	bIsSprinting = false;
}

bool UGasCharacterMovementComponent::IsSprinting() const
{
	return bIsSprinting;
}

float UGasCharacterMovementComponent::GetMaxSpeed() const
{
	float maxSpeed = Super::GetMaxSpeed();
	if ( bIsSprinting && (MovementMode == MOVE_Walking || MovementMode == MOVE_NavWalking))
	{
		maxSpeed *= SprintSpeedMagnitude;
	}
	
	return maxSpeed;
}

