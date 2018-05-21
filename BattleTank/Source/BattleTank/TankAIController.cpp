// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankAimingComponent.h"

ATankAIController::ATankAIController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (ensure(PlayerTank && ControlledTank))
	{
		return;
	}
	
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(AimingComponent))
	{
		return;
	}

	MoveToActor(PlayerTank, AcceptanceRadius);

	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// TODO Fix Firing
	//ControlledTank->Fire(); // TODO Limit Firing Rate
}