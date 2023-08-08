// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Sound/SoundWave.h"
#include "LockAndKey.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_DAKOTA_API ALockAndKey : public ATriggerBox
{
	GENERATED_BODY()

			
	
public:
	ALockAndKey();

	UFUNCTION()
		void CheckActorType(class AActor* OverlappedActor, class AActor* Otheractor);
	UFUNCTION()
		void OpenTheDoor();
	UPROPERTY(EditAnywhere)
		USoundBase* Sound_Pickup;
};
