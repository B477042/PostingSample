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
	virtual float GetMaxSpeed() const override;
	
	void StartSprinting();
	void StopSprinting();
	FORCEINLINE bool IsSprinting() const;
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Sprint|ValueOption",meta=(AllowPrivateAccess=true))
	float SprintSpeedMagnitude;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Sprint|ValueOption",meta=(AllowPrivateAccess=true))
	uint8 bIsSprinting:1;
	
	// UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ValueOption",meta=(AllowPrivateAccess=true))
	// float SprintLerpToStartSprint;
	// UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ValueOption",meta=(AllowPrivateAccess=true))
	// float SprintLerpToEndSprint;
};
