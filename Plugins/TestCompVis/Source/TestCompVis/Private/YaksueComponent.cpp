// Fill out your copyright notice in the Description page of Project Settings.

#include "YaksueComponent.h"

// Sets default values for this component's properties
UYaksueComponent::UYaksueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	//四个顶点位置：
	Points.Add(FVector(0, 0, 100));
	Points.Add(FVector(100, 0, 0));
	Points.Add(FVector(-50, -86, 0));
	Points.Add(FVector(-50, 86, 0));
}


// Called when the game starts
void UYaksueComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UYaksueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

