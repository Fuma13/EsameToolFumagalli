// Fill out your copyright notice in the Description page of Project Settings.

#include "Fumagalli.h"
#include "ShipAIController.h"
#include "FumagalliPawn.h"

AShipAIController::AShipAIController(const FObjectInitializer & OI) : Super(OI)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AShipAIController::Possess(APawn* PossessedPawn)
{
	SetPawn(PossessedPawn);
}

void AShipAIController::UnPossess()
{
	SetPawn(nullptr);
}

void AShipAIController::Tick(float DeltaTime)
{
	APawn *p = GetPawn();
	if (p == nullptr)
	{
		return;
	}

	AFumagalliPawn *cp = dynamic_cast<AFumagalliPawn *>(p);
	cp->FireShot(FVector::ForwardVector);
}

