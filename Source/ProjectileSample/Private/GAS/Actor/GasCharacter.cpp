// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Actor/GasCharacter.h"

#include "AbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GAS/Actor/GasPlayerController.h"
#include "GAS/DataAsset/PlayerInputDataAsset.h"
#include "GAS/Player/GasPlayerState.h"
#include "GAS/Attribute/GasBasicAttributeSet.h"
#include "GAS/C-class/SystemHolder.h"
// Sets default values
AGasCharacter::AGasCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGasCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGasCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGasCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!enhancedInputComponent)
	{
		return;
	}
	
	//プレイヤーのコントローラーからデータアセット
	if (const AGasPlayerController* gasPlayerController = Cast<AGasPlayerController>( GetController()))
	{
		const TWeakObjectPtr<UPlayerInputDataAsset> weakPlayerInputDataAsset = gasPlayerController->GetPlayerInputDataAsset();
		if ( weakPlayerInputDataAsset.Pin().IsValid() )
		{
			
			auto BindActionInputLambda = [weakPlayerInputDataAsset, enhancedInputComponent, this](E_CommonPlayerInputType CommonPlayerInput, 
				ETriggerEvent TriggerEventType, auto FunctionName)->void
			{
				if (UInputAction* loadedAction =  weakPlayerInputDataAsset->GetInputAction(CommonPlayerInput))
				{
					// BindAction(const UInputAction* Action, ETriggerEvent TriggerEvent, UObject* Object, FName FunctionName)
					enhancedInputComponent->BindAction(loadedAction, TriggerEventType, this, FunctionName);
				}
			};
			
			// binding action
			BindActionInputLambda(E_CommonPlayerInputType::Walk, ETriggerEvent::Triggered, &AGasCharacter::onCommonWalk);
			BindActionInputLambda(E_CommonPlayerInputType::Look, ETriggerEvent::Triggered, &AGasCharacter::onCommonLook);
			BindActionInputLambda(E_CommonPlayerInputType::Jump, ETriggerEvent::Started, &AGasCharacter::onCommonJump);
			BindActionInputLambda(E_CommonPlayerInputType::Interaction, ETriggerEvent::Started, &AGasCharacter::onCommonInteraction);
		}
	}
}

UAbilitySystemComponent* AGasCharacter::GetAbilitySystemComponent() const
{
	return abilitySystemComponent.Get();
}

void AGasCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	TSharedPtr<IGasView>gasView =  FSystemHolder::Get()->GetSystem<IGasView>();
	if (!gasView.IsValid())
	{
		return;
	}
	//プレイヤーの場合
	if (AGasPlayerController* gasPlayerController = Cast<AGasPlayerController>(NewController))
	{
		if (AGasPlayerState* gasPlayerState = Cast<AGasPlayerState>(GetPlayerState()))
		{
			abilitySystemComponent =  gasPlayerState->GetAbilitySystemComponent();
			gasPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(gasPlayerState,this);
			
			attributeSetBase =  gasPlayerState->GetAttributeSet();
			
			gasView->ReqLoadPlayerDefaultAbility();
			FGameplayAbilitySpec AbilitySpec;
			AbilitySpec.Ability = 
			abilitySystemComponent->GiveAbility()
		}
		
		
		
	}
	
}

void AGasCharacter::UnPossessed()
{
	Super::UnPossessed();
	if (UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>( InputComponent))
	{
		if (enhancedInputComponent->HasBindings())
		{
			enhancedInputComponent->ClearBindingsForObject(this);
		}
	}
}

void AGasCharacter::onCommonWalk(const FInputActionValue& Value)
{
	const FVector2D movementVector = Value.Get<FVector2D>();
	//Chara Movmement Component の状態を確認する必要があり
	AddMovementInput(GetActorForwardVector(),movementVector.Y);
	AddMovementInput(GetActorRightVector(),movementVector.X);
	
}

void AGasCharacter::onCommonLook(const FInputActionValue& Value)
{
	const FVector2D lookVector = Value.Get<FVector2D>();
	
	if (Controller)
	{
		AddControllerYawInput(lookVector.X);
		AddControllerPitchInput(lookVector.Y);
	}
}

void AGasCharacter::onCommonJump()
{
	
	GetCharacterMovement()->DoJump(false,5.0f);
	

}

void AGasCharacter::onCommonInteraction()
{
	// 他の物体と相互作用します
	
}

