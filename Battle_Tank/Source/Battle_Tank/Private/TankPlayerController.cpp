// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Battle_Tank.h"


//  Tick
	// Super


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possesing: %s"), *(ControlledTank->GetName()));
	}
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;         //  Out Parameter
	if (GetSightRayhitLocation(HitLocation))        //  Has Side-effect  is going to line trace
	{
		//  UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
		
		//  TODO tell controlled tank to aim at this point
	}
}


//  Get world location if linetrace through crosshair true if hits landscape
bool ATankPlayerController::GetSightRayhitLocation(FVector& HitLocation) const
{
	//  find the Crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	


	//  de-project the screen position of the crosshair to the world direction
	//  Line-trace along the look direction and see what we hit (Up to a max range)
	return true;
}