// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto FinalThrottle = FMath::Clamp<float>(Throttle, -1, +1);

	auto ForceApplied = GetForwardVector() * FinalThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}