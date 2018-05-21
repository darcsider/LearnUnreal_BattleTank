// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
	Locked,
	Reloading,
	Aiming
};

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

protected:
	// Called when the game starts
	UTankBarrel* TankBarrel = nullptr;
	UTankTurret* TankTurret = nullptr;

	UPROPERTY(BlueprintReadOnly)
	EFiringStatus FiringStatus = EFiringStatus::Aiming;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 100000; // sensible starting value of 1000 m/s

	void MoveBarrelTowards(FVector AimDirection);
};