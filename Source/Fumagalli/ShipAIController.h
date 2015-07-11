// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "ShipAIController.generated.h"

/**
*
*/
UCLASS()
class AShipAIController : public AAIController
{
	GENERATED_BODY()
public:
	AShipAIController(const FObjectInitializer & OI);

private:
	virtual void Possess(APawn * p) override;
	virtual void UnPossess() override;

	void Tick(float DeltaTime) override;
};
