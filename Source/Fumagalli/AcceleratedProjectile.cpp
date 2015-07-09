// Fill out your copyright notice in the Description page of Project Settings.

#include "Fumagalli.h"
#include "AcceleratedProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
AAcceleratedProjectile::AAcceleratedProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

	// Create mesh component for the projectile sphere
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->AttachTo(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("AcceleratedProjectile");
	RootComponent = ProjectileMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 300.f;
	ProjectileMovement->MaxSpeed = 300.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity

	Velocity = FVector(0.0f, 0.0f, 0.0f);
	Acceleration = FVector(0.0f, 100.0f, 0.0f);

}

// Called when the game starts or when spawned
void AAcceleratedProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAcceleratedProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	Velocity += Acceleration * DeltaTime;

	RootComponent->MoveComponent(Velocity * DeltaTime, Velocity.Rotation(), true);

}

