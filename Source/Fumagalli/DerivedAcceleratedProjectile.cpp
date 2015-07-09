// Fill out your copyright notice in the Description page of Project Settings.

#include "Fumagalli.h"
#include "DerivedAcceleratedProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
ADerivedAcceleratedProjectile::ADerivedAcceleratedProjectile(const FObjectInitializer& ObjectInitializer)
	: AFumagalliProjectile(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set slower speed to see acceleration effects
	Super::ProjectileMovement->InitialSpeed = 300.f;
	Super::ProjectileMovement->MaxSpeed = 300.f;

	Velocity = FVector(0.0f, 0.0f, 0.0f);
	Acceleration = FVector(0.0f, 100.0f, 0.0f);
}

// Called every frame
void ADerivedAcceleratedProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Velocity += Acceleration * DeltaTime;

	RootComponent->MoveComponent(Velocity * DeltaTime, Velocity.Rotation(), true);

}
