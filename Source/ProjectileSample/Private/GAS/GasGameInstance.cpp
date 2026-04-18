// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GasGameInstance.h"

#include "GAS/C-class/SystemHolder.h"

UGasGameInstance::UGasGameInstance()
{
	
	
}

void UGasGameInstance::Init()
{
	Super::Init();
	
	systemHolder = FSystemHolder::Get();
	if (systemHolder.IsValid())
	{
		systemHolder.Pin()->InitSystemHolder();
	}
	
}

void UGasGameInstance::Shutdown()
{
	Super::Shutdown();
	if (systemHolder.IsValid())
	{
		systemHolder.Pin()->ResetSystemHolder();
		systemHolder.Reset();
	}
	
}

UGameAbilityDataAsset* UGasGameInstance::GetGasAbilityDataAsset() const
{
	return gameAbilityDataAsset;
}

UGasGameInstance* UGasGameInstance::GetGameInstance()
{
	if (!GEngine)
	{
		return nullptr;
	}
	// GEngineからゲームワールドを探して
	for (const FWorldContext& worldContext : GEngine->GetWorldContexts())
	{
		if (worldContext.WorldType == EWorldType::Game || worldContext.WorldType == EWorldType::PIE)
		{
			if (UWorld* world = worldContext.World())
			{
				return Cast<UGasGameInstance>(world->GetGameInstance());
			}
		}
	}
	return nullptr;
}


