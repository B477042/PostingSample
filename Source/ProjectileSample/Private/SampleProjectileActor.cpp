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
	

	projectileMovementComponent->InitialSpeed = 500.f;
	projectileMovementComponent->MaxSpeed = 1500.f;
	projectileMovementComponent->bShouldBounce=false;
	projectileMovementComponent->bRotationFollowsVelocity = true;
	
	
	InitialLifeSpan = 10.0f;
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
	
	
	//projectileMovementComponent->ProjectileGravityScale=0.f;
	
}

// Called every frame
void ASampleProjectileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	
	GEngine->AddOnScreenDebugMessage(3,1.0f,FColor::Red,FString::Printf(TEXT("%s Velocity : %s"),*GetName(),*projectileMovementComponent->Velocity.ToString()));
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
	
	// この関数を使って発射体が向かう方面を変える。
	projectileMovementComponent->SetVelocityInLocalSpace(Direction.GetSafeNormal()*500.f);
	
	//MeshComponentのマテリアルのカーラを変わってより認識やすくなるために
    if(UMaterialInstanceDynamic* material = meshComponent->CreateDynamicMaterialInstance(0))
    {
    	const FName paramName = FName(TEXT("MainColor"));
    	material->SetVectorParameterValue(paramName,FLinearColor::Red);
    	
    }
}

