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
	
	projectileMovementComponent->InitialSpeed = movementInitData.initSpeed;
	projectileMovementComponent->MaxSpeed = movementInitData.maxSpeed;
	//projectileMovementComponent->ProjectileGravityScale=0.f;
	
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
	
	
	GEngine->AddOnScreenDebugMessage(1,2.0f,FColor::Red,TEXT("OnShpereOverlaped"));
	sphereComponent->OnComponentBeginOverlap.Clear();

	
	//Destroy();
}

void ASampleProjectileActor::ReadyToFireUsingInterpolation(TObjectPtr<AActor> ShooterActor, const FVector TargetToFire)
{

	SetOwner(ShooterActor);

	//UGameplayStatics::PredictProjectilePath();
	projectileMovementComponent->MoveInterpolationTarget(TargetToFire,GetActorRotation());
	//MeshComponentのマテリアルのカーラを変わってより認識やすくなるために
	if(UMaterialInstanceDynamic* material = meshComponent->CreateDynamicMaterialInstance(0))
	{
		const FName paramName = FName(TEXT("MainColor"));
		material->SetVectorParameterValue(paramName,FLinearColor::Blue);
    	
	}
	
}

void ASampleProjectileActor::ReadyToFireUsingMoveComponent(TObjectPtr<AActor> ShooterActor, const FVector Direction)
{
	SetOwner(ShooterActor);
	//projectileMovementComponent->MoveUpdatedComponent(Direction,GetActorRotation(),true);

	projectileMovementComponent->AddForce(Direction*100000.f);
	//MeshComponentのマテリアルのカーラを変わってより認識やすくなるために
    if(UMaterialInstanceDynamic* material = meshComponent->CreateDynamicMaterialInstance(0))
    {
    	const FName paramName = FName(TEXT("MainColor"));
    	material->SetVectorParameterValue(paramName,FLinearColor::Red);
    	
    }
}

