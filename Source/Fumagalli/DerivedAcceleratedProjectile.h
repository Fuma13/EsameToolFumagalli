// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FumagalliProjectile.h"
#include "DerivedAcceleratedProjectile.generated.h"

/**
 * 
 */
UCLASS()
class FUMAGALLI_API ADerivedAcceleratedProjectile : public AFumagalliProjectile
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	FVector Acceleration;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	FVector Velocity;
public:
	// Sets default values for this actor's properties
	ADerivedAcceleratedProjectile(const FObjectInitializer& ObjectInitializer);
	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	
};
