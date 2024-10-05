// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "TopDownPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNPROJECT_API ATopDownPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ATopDownPlayerState();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAbilitySystemComponent* AbilitySystemComponent;
};
