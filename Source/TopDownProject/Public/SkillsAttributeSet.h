// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../TopDownAttributeSet.h"
#include "SkillsAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNPROJECT_API USkillsAttributeSet : public UTopDownAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData DashLenght;
	ATTRIBUTE_ACCESSORS(USkillsAttributeSet, DashLenght);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData DashWidth;
	ATTRIBUTE_ACCESSORS(USkillsAttributeSet, DashWidth);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData DashCost;
	ATTRIBUTE_ACCESSORS(USkillsAttributeSet, DashCost);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData DashDamage;
	ATTRIBUTE_ACCESSORS(USkillsAttributeSet, DashDamage);
};
