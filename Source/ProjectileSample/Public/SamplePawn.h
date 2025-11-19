// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SamplePawn.generated.h"

class UCharacterMovementComponent;
struct FInputActionValue;
class UBoxComponent;
class USpringArmComponent;
class UCameraComponent;
class ASampleProjectileActor;
class UInputAction;
class UInputMappingContext;

UCLASS(BlueprintType, Blueprintable)
class PROJECTILESAMPLE_API ASamplePawn : public APawn
{
	GENERATED_BODY()
public:
	// 
	enum class E_MoveFunctionMode :uint8
	{
		MoveComponent = 0,
		Interpolation
	};

	
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

	UFUNCTION(BlueprintCallable)
	void SwitchMoveFunctionMode();

protected:
	
	TObjectPtr<ASampleProjectileActor> makeProjectile();
	
	void movePawn(const FInputActionValue& Value);
	void lookUp(const FInputActionValue& Value);
protected:
	
	UPROPERTY(EditAnywhere,blueprintReadWrite,Category="Input",meta=(AllowPrivateAccess=true))
	UInputMappingContext* pawnBasicInputMapping;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Input",meta=(AllowPrivateAccess=true))
	UInputAction* inputAction;
	
	UPROPERTY(editAnywhere, BlueprintReadWrite, Category="Input", meta=(AllowPrivateAccess=true))
	UInputAction* moveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input", meta=(AllowPrivateAccess=true))
	UInputAction* lookAction;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera",meta=(AllowPrivateAccess=true))
	UCameraComponent* cameraComponent;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera",meta=(AllowPrivateAccess=true))
	USpringArmComponent* springArmComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* staticMeshComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(AllowPrivateAccess=true))
	UBoxComponent* boxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Class", meta=(AllowPrivateAccess=true))
	TSubclassOf<ASampleProjectileActor> projectileClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta=(AllowPrivateAccess=true))
	UCharacterMovementComponent* characterMovementComponent;
	
	E_MoveFunctionMode moveFunctionMode = E_MoveFunctionMode::MoveComponent;
};
