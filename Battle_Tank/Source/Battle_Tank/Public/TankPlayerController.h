// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h" 
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"       //  Must be the Last include

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

		ATank* GetControlledTank() const;
	
	
};
