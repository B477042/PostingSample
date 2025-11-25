// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AgentInfoList.generated.h"

struct FAgentInfo;

UCLASS(Blueprintable)
class PROJECTILESAMPLE_API AAgentInfoList : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAgentInfoList();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	TMap<int32,FAgentInfo> agentList;
};



