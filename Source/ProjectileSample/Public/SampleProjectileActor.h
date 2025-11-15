// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SampleProjectileActor.generated.h"

class USphereComponent;
class UProjectileMovementComponent;


USTRUCT(blueprintType)
struct FMovementInitStruct
{
	GENERATED_BODY()
public:
	FMovementInitStruct(){}
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float initSpeed = 600.f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float maxSpeed = 1800.f;
};

UCLASS(Blueprintable,BlueprintType)
class PROJECTILESAMPLE_API ASampleProjectileActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASampleProjectileActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:
	virtual void PostInitializeComponents() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnSphereOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	// ProjectileMovementComponentの「MoveInterpolationTarget」関数を呼びます。
	void ReadyToFireUsingInterpolation(TObjectPtr<AActor>ShooterActor, const FVector TargetToFire);
	// ProjectileMovementComponentの「MoveUpdatedComponent」関数を呼びます。
	void ReadyToFireUsingMoveComponent(TObjectPtr<AActor>ShooterActor, const FVector Direction);
	
protected:
	UPROPERTY(BlueprintReadWrite,EditAnywhere,meta=(AllowPrivateAccess=true))
	TObjectPtr<UProjectileMovementComponent> projectileMovementComponent;

	// For collision
	UPROPERTY(BlueprintReadWrite,EditAnywhere,meta=(AllowPrivateAccess=true))
	TObjectPtr<USphereComponent> sphereComponent;
	
	// Shape
	UPROPERTY(BlueprintReadWrite,EditAnywhere,meta=(AllowPrivateAccess=true))
	TObjectPtr<UStaticMeshComponent> meshComponent;
	
	// projectile settings
	UPROPERTY(blueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
	FMovementInitStruct movementInitData;
};
