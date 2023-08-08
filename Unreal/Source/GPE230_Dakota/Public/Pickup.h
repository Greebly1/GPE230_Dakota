// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MazeCharacter.h"
#include "Sound/Soundwave.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_DAKOTA_API APickup : public ATriggerBox
{
	GENERATED_BODY()
public:
	APickup();

	//Check if the overlapping actor is a player
	UFUNCTION()
		void checkActorType(AActor* OverlappedActor, AActor* Otheractor);

	//Heal the player
	UFUNCTION()
		virtual void powerUp(AMazeCharacter* player);
	
	//turn off collision and visibility, & start a timer to enable them
	UFUNCTION(BlueprintCallable)
		void disablePickup();

	//turn on collision and visibility
	UFUNCTION(BlueprintCallable)
		void enablePickup();

	//used to check if the player meets the requirements to take the powerup
	virtual bool canApplyPowerup(AMazeCharacter* player);

	FTimerHandle respawnDelayTimerHandle;

	UShapeComponent* triggerBox;
	
	UPROPERTY(EditAnywhere)
		bool infiniteRespawn;
	UPROPERTY(EditAnywhere)
		int respawns;
	UPROPERTY(EditAnywhere)
		float respawnTime;
	UPROPERTY(EditAnywhere)
		USoundBase* Sound_Pickup;

protected:

	UPROPERTY(EditAnywhere)
		float healAmount;
	UPROPERTY(EditAnywhere)
		bool enabled;

};
