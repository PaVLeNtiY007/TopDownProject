// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "ObjectPointer.generated.h"

UCLASS(Blueprintable)
class TOPDOWNPROJECT_API AObjectPointer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectPointer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UTextRenderComponent> PointerText;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
