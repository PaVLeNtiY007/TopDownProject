// Copyright by GameDone Studio

#include "AbilityInputSubsystem.h"
#include "Runtime/CoreUObject/Public/UObject/Object.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "TopDownPlayerState.h"
#include "AbilitySystemComponent.h"
#include "InputTriggers.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"




UAbilityInputSubsystem::UAbilityInputSubsystem()
{

}

int32 UAbilityInputSubsystem::GetAbilityInputID(UInputAction* InputAction)
{
	if (InputAction == nullptr)
	{
		
		return -1;
	}

	if (int32* FoundInputID = InputMapping.Find(InputAction))
	{
		return *FoundInputID;
	}

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	UEnhancedInputComponent* InputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);
	if (!InputComponent)
	{
		return -1;
	}
	int32 CurrentInputID = InputMapping.Add(InputAction, NextInputID);
	++NextInputID;

	InputComponent->BindAction(InputAction, ETriggerEvent::Triggered, this, &UAbilityInputSubsystem::InputTriggerAbility, CurrentInputID);
	InputComponent->BindAction(InputAction, ETriggerEvent::Completed, this, &UAbilityInputSubsystem::InputCompletedAbility, CurrentInputID);
	
	return CurrentInputID;
}

void UAbilityInputSubsystem::InputTriggerAbility(int32 InputID)
{
	if (ATopDownPlayerState* PlayerState = Cast<ATopDownPlayerState>(UGameplayStatics::GetPlayerState(GetWorld(), 0)))
	{
		if (UAbilitySystemComponent* AbilitySystem = PlayerState->GetAbilitySystemComponent())
		{
			AbilitySystem->PressInputID(InputID);
		}
	}
}

void UAbilityInputSubsystem::InputCompletedAbility(int32 InputID)
{
	if (ATopDownPlayerState* PlayerState = Cast<ATopDownPlayerState>(UGameplayStatics::GetPlayerState(GetWorld(), 0)))
	{
		if (UAbilitySystemComponent* AbilitySystem = PlayerState->GetAbilitySystemComponent())
		{
			AbilitySystem->ReleaseInputID(InputID);
		}
	}
}

void UAbilityInputSubsystem::RebindAllInputs()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	UEnhancedInputComponent* InputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);
	if (!InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("EnhancedInputComponent not found."));
		return;
	}

	for (const TPair<UInputAction*, int32>& Pair : InputMapping)
	{
		UInputAction* Action = Pair.Key;
		int32 InputID = Pair.Value;

		InputComponent->BindAction(Action, ETriggerEvent::Triggered, FInputActionHandlerSignature::CreateLambda(
			[this, InputID](const FInputActionInstance& Instance)
			{
				InputTriggerAbility(InputID);
			}
		));

		InputComponent->BindAction(Action, ETriggerEvent::Completed, FInputActionHandlerSignature::CreateLambda(
			[this, InputID](const FInputActionInstance& Instance)
			{
				InputCompletedAbility(InputID);
			}
		));

	}
}




