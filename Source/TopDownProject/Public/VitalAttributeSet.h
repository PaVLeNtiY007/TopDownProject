// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../TopDownAttributeSet.h"
#include "VitalAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNPROJECT_API UVitalAttributeSet : public UTopDownAttributeSet
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Energy;
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, Energy);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxEnergy;
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, MaxEnergy);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Money;
	ATTRIBUTE_ACCESSORS(UVitalAttributeSet, Money);
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};
