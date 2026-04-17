// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GasGameInstance.generated.h"

class FSystemHolder;
/**
 * 
 */
UCLASS()
class PROJECTILESAMPLE_API UGasGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UGasGameInstance();
	
	virtual void Init() override;
	virtual void Shutdown() override;
	
	const TSharedPtr<FSystemHolder> GetSystemHolder() const;

private:
	TSharedPtr<FSystemHolder> systemHolder;
};
