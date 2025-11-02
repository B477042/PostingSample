// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SamplePawn.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS(BlueprintType, Blueprintable)
class PROJECTILESAMPLE_API ASamplePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASamplePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void OnClickMouse();
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Input",meta=(AllowPrivateAccess=true))
	UInputAction* inputAction;
};
