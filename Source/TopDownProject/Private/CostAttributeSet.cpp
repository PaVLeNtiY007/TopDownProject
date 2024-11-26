// Fill out your copyright notice in the Description page of Project Settings.


#include "CostAttributeSet.h"

void UCostAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);
    if (Attribute == GetActionCostAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, 999999999);
    }
}