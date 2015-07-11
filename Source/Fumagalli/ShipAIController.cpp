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
	if (PossessedPawn == nullptr)
	{
		return;
	}

	pawn = dynamic_cast<AFumagalliPawn *>(PossessedPawn);
}

void AShipAIController::UnPossess()
{
	SetPawn(nullptr);
}

void AShipAIController::Tick(float DeltaTime)
{
	if (pawn == nullptr)
	{
		return;
	}

	pawn->FireShot(FVector::ForwardVector);
}

