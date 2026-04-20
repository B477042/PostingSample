// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GasCharacterMovementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTILESAMPLE_API UGasCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGasCharacterMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ValueOption",meta=(AllowPrivateAccess=true))
	float SprintSpeedMagnitude;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ValueOption",meta=(AllowPrivateAccess=true))
	float SprintLerpToStartSprint;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ValueOption",meta=(AllowPrivateAccess=true))
	float SprintLerpToEndSprint;
};
