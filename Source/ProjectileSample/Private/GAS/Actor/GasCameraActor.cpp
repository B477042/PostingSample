// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Actor/GasCameraActor.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AGasCameraActor::AGasCameraActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("springArmComponent"));\

	
	CameraComponent -> SetupAttachment(SpringArmComponent);
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 220.f;
	SpringArmComponent->bDoCollisionTest = false;
	
}

// Called when the game starts or when spawned
void AGasCameraActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGasCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

