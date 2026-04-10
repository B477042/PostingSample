// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(Blueprintable)
enum class E_GasAbilityInputID : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Sprint = 1 UMETA(DisplayName = "Sprint"),
	Jump = 2 UMETA(DisplayName = "Jump"),
	Walk = 3 UMETA(DisplayName = "Walk")
	
};