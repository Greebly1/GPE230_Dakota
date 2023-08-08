// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "MazeCharacter.h"
#include "Components/ShapeComponent.h"
#include "Kismet/GameplayStatics.h"

APickup::APickup()
{
	//bind checkactortype to the overlap event
	OnActorBeginOverlap.AddDynamic(this, &APickup::checkActorType);
	triggerBox = GetCollisionComponent();
	enabled = true;
}

//Check if the overlapping actor is a player
void APickup::checkActorType(AActor* OverlappedActor, AActor* Otheractor)
{
	//cast the other actor to amazecharacter
	AMazeCharacter* player = Cast<AMazeCharacter>(Otheractor);
	//if the pointer is not null then targetActor is aMazeCharacter
	if (player != nullptr) {

		//if we can apply the powerup
		if (canApplyPowerup(player)) {
			//apply the powerup
			powerUp(player);
			UGameplayStatics::PlaySound2D(GetWorld(), Sound_Pickup, 1.0f, 1.0f);
			//disable this powerup
			disablePickup();
		}
	}
}

//Heal the player
void APickup::powerUp(AMazeCharacter* player)
{
		player->addHealth(healAmount);
}

//turn off collision and visibility
void APickup::disablePickup()
{
	if (enabled) {
		if (infiniteRespawn) {
			//stop overlap events & hide actor
			triggerBox->SetGenerateOverlapEvents(false);
			this->SetActorHiddenInGame(true);

			enabled = false;
			GetWorld()->GetTimerManager().SetTimer(respawnDelayTimerHandle, this, &APickup::enablePickup, respawnTime, false);
		}
		else if (respawns > 1) {
			//stop overlap events & hide actor
			triggerBox->SetGenerateOverlapEvents(false);
			this->SetActorHiddenInGame(true);
			respawns--;
			enabled = false;
			GetWorld()->GetTimerManager().SetTimer(respawnDelayTimerHandle, this, &APickup::enablePickup, respawnTime, false);
		}
		else {
			this->Destroy();
		}
	}
}

//turn on collision and visibility
void APickup::enablePickup()
{
	triggerBox->SetGenerateOverlapEvents(true);
	this->SetActorHiddenInGame(false);
	enabled = true;

	//Clear the timer
	GetWorld()->GetTimerManager().ClearTimer(respawnDelayTimerHandle);
}

//used to check if the player meets the requirements to take the powerup
bool APickup::canApplyPowerup(AMazeCharacter* player)
{
	//if the player is not at max health
	if (player->getCurrentHealth() < player->getMaxHealth()) {
		return true;
	}
	else return false;
}
