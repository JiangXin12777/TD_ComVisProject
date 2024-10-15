// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "YaksueComponent.generated.h"

UENUM(BlueprintType)
enum class ECoordinateSpaceType : uint8
{
	ECST_Local,
	ECST_World,
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TESTCOMPVIS_API UYaksueComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UYaksueComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
