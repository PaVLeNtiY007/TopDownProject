// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../TopDownAttributeSet.h"
#include "CostAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNPROJECT_API UCostAttributeSet : public UTopDownAttributeSet
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData ActionCost;
	ATTRIBUTE_ACCESSORS(UCostAttributeSet, ActionCost);

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};
