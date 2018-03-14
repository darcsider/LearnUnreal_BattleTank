// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (ControlledTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessed: %s"), *ControlledTank->GetName())
	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("No Tank possessed"))
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"))
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}