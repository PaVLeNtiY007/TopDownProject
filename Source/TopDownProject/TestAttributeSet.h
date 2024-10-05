// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "TopDownAttributeSet.h"
#include "TestAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNPROJECT_API UTestAttributeSet : public UTopDownAttributeSet
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData TestAttribute;
	ATTRIBUTE_ACCESSORS(UTestAttributeSet, TestAttribute);
};
