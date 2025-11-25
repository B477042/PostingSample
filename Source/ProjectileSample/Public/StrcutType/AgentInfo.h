// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


/**
 * 
 */

UENUM(BlueprintType)
enum class EAgentInteractionType : uint8
{
	None = 0,
	Push,
	Conversation,
	Movable
	
};

USTRUCT(BlueprintType)
struct FAgentInfo
{

	GENERATED_BODY()
	
	FAgentInfo();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Data")
	FString agentName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Data")
	int32 agentId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Data")
	EAgentInteractionType interactionType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Data")
	int32 questId;
};



