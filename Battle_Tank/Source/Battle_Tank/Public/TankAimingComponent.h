// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;        //  Forward Declaration


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	//  TODO add set turret Reference

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	
private:

	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
