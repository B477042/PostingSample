// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GasGameInstance.h"

#include "GAS/C-class/SystemHolder.h"

UGasGameInstance::UGasGameInstance()
{
	
	
}

void UGasGameInstance::Init()
{
	Super::Init();
	
	systemHolder = MakeShared<FSystemHolder>();
	if (systemHolder.IsValid())
	{
		systemHolder->InitSystemHolder();
	}
	
}

void UGasGameInstance::Shutdown()
{
	Super::Shutdown();
	if (systemHolder.IsValid())
	{
		systemHolder->ResetSystemHolder();
		systemHolder.Reset();
	}
	
}

const TSharedPtr<FSystemHolder> UGasGameInstance::GetSystemHolder() const
{
	return systemHolder;
}

