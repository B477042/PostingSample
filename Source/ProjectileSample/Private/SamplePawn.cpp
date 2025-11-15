// Fill out your copyright notice in the Description page of Project Settings.


#include "SamplePawn.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "SampleProjectileActor.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Input/WeaponFireInputAction.h"

// Sets default values
ASamplePawn::ASamplePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	boxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	springArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));


	SetRootComponent(boxComponent);
	staticMeshComponent->SetupAttachment(RootComponent);
	
	cameraComponent->SetupAttachment(springArmComponent);
	springArmComponent->SetupAttachment(RootComponent);
	

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

	// この場合はマウスの左ボタンを押した時にイベントが発生します。
	inputComponent->BindAction(inputAction,ETriggerEvent::Started,this,&ASamplePawn::OnClickMouse);
	

	//inputComponent->BindAction(FName(TEXT("IA_WeaponFire")),ETriggerEvent::Triggered,this,&ASamplePawn::OnClickMouse);
	//inputComponent->BindAction(nullptr,ETriggerEvent::Started,this,&ASamplePawn::OnClickMouse);

	
}

void ASamplePawn::OnClickMouse()
{
	// タイマーを確認
	GEngine->AddOnScreenDebugMessage(0,2.0f,FColor::Green,TEXT("OnClickMouse"));
	
	TObjectPtr<ASampleProjectileActor> toShotProjectile = makeProjectile();
	
	
	
	// 基本的には下のように作成さればNGですが…
	switch (moveFunctionMode)
	{
		case E_MoveFunctionMode::MoveComponent:
			{
				const FVector fireDirection = GetActorForwardVector().RotateAngleAxis(45.f,FVector::RightVector)*40000.f;
				toShotProjectile->ReadyToFireUsingMoveComponent(this,fireDirection);
			}
		break;
		case E_MoveFunctionMode::Interpolation:
			{
				
			}
		break;
		
		
	}
	
}

void ASamplePawn::SwitchMoveFunctionMode()
{
	moveFunctionMode == E_MoveFunctionMode::MoveComponent? moveFunctionMode = E_MoveFunctionMode::Interpolation : moveFunctionMode = E_MoveFunctionMode::MoveComponent;
}

TObjectPtr<ASampleProjectileActor> ASamplePawn::makeProjectile()
{
	TObjectPtr<ASampleProjectileActor> retObject = nullptr;
	if (UWorld* world = GetWorld())
	{

		FVector spawnLocation = GetActorLocation() + GetActorForwardVector() * 10.0f + FVector(0.0f,0.0f,230.f);
		FRotator spawnRotation = GetActorRotation();
		
		retObject = world->SpawnActor<ASampleProjectileActor>(projectileClass.Get());
		retObject->SetActorLocationAndRotation(spawnLocation,spawnRotation);
		
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("UWorld is Invalid"));
	}

	return retObject;
}

