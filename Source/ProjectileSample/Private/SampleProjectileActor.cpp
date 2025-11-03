// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleProjectileActor.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ASampleProjectileActor::ASampleProjectileActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	projectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	sphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	SetRootComponent(sphereComponent);
	meshComponent->AttachToComponent(sphereComponent,FAttachmentTransformRules::KeepRelativeTransform);
	

	
	//sphereComponent->SetCollisionProfileName(TEXT("OverlapAll"));
	
}

// Called when the game starts or when spawned
void ASampleProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASampleProjectileActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	projectileMovementComponent->SetUpdatedComponent(sphereComponent);
	sphereComponent->OnComponentBeginOverlap.AddDynamic(this,&ASampleProjectileActor::OnSphereOverlapped);
}

// Called every frame
void ASampleProjectileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASampleProjectileActor::OnSphereOverlapped(	UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor)
	{
		return;
	}

	if (OtherActor == GetOwner())
	{
		return;
	}
	
	
	GEngine->AddOnScreenDebugMessage(0,2.0f,FColor::Red,TEXT("OnShpereOverlaped"));
	sphereComponent->OnComponentBeginOverlap.Clear();

	
	//Destroy();
}

void ASampleProjectileActor::ReadyToFireUsingInterpolation(TObjectPtr<AActor> ShooterActor, const FVector TargetToFire)
{

	SetOwner(ShooterActor);

	//UGameplayStatics::PredictProjectilePath();
	projectileMovementComponent->MoveInterpolationTarget(TargetToFire,GetActorRotation());
	//MeshComponentのマテリアルのカーラを変わってより認識やすくなるために
	if(UMaterialInterface* material = meshComponent->GetMaterial(0))
	{
		FName paramName = FName(TEXT("MainColor"));
		FLinearColor materialColor; 
		material->GetVectorParameterValue(paramName,materialColor);
		materialColor = FLinearColor::Red;
	}
	
}

void ASampleProjectileActor::ReadyToFireUsingMoveComponent(TObjectPtr<AActor> ShooterActor, const FVector Direction)
{
	SetOwner(ShooterActor);
	projectileMovementComponent->MoveUpdatedComponent(Direction,GetActorRotation(),true);
	//MeshComponentのマテリアルのカーラを変わってより認識やすくなるために
    if(UMaterialInterface* material = meshComponent->GetMaterial(0))
    {
    	FName paramName = FName(TEXT("MainColor"));
    	FLinearColor materialColor; 
    	material->GetVectorParameterValue(paramName,materialColor);
    	materialColor = FLinearColor::Blue;
    }
}

