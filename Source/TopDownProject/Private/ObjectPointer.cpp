// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectPointer.h"

// Sets default values
AObjectPointer::AObjectPointer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointerText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("NameOfObject"));

}

// Called when the game starts or when spawned
void AObjectPointer::BeginPlay()
{
	Super::BeginPlay();
	PointerText->SetText(FText::FromString("Hit Me"));
	
}

// Called every frame
void AObjectPointer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

