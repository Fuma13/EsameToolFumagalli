// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Fumagalli.h"
#include "FumagalliGameMode.h"
#include "FumagalliPawn.h"

AFumagalliGameMode::AFumagalliGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// set default pawn class to our character class
	DefaultPawnClass = AFumagalliPawn::StaticClass();
}

