// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownPlayerState.h"
#include "AbilitySystemComponent.h"

ATopDownPlayerState::ATopDownPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("Ability System Component"));
}
