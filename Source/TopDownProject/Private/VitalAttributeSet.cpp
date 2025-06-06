// Fill out your copyright notice in the Description page of Project Settings.


#include "VitalAttributeSet.h"

void UVitalAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
    if (Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
    }

    if (Attribute == GetEnergyAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxEnergy());
    }

    if (Attribute == GetMoneyAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, 9999);
    }
}
