// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "speedPickup.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_DAKOTA_API AspeedPickup : public APickup
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float boostDuration;
protected:
		virtual void powerUp(AMazeCharacter* player) override;

	    virtual bool canApplyPowerup(AMazeCharacter* player) override;
};
