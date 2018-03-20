// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetControlledTank();
	auto PlayerControlledTank = GetPlayerController();

	if (AIControlledTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIContrlller Possessed: %s."), *AIControlledTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Tank possessed."))
	}

	if (PlayerControlledTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controlled Tank Found at: %s."), *PlayerControlledTank->GetActorLocation().ToString())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player Controlled Tank Found."))
	}

	UE_LOG(LogTemp, Warning, TEXT("AIContrlller Begin Play"))
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerController() const
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController != nullptr)
	{
		return Cast<ATank>(PlayerController->GetPawn());
	}
	else
	{
		return nullptr;
	}
}