// Fill out your copyright notice in the Description page of Project Settings.

#include "LockAndKey.h"
#include "MazeCharacter.h"

ALockAndKey::ALockAndKey() {
	OnActorBeginOverlap.AddDynamic(this, &ALockAndKey::CheckActorType);
}

void ALockAndKey::CheckActorType(AActor* OverlappedActor, AActor* Otheractor)
{
	if (Otheractor->IsA(AMazeCharacter::StaticClass())) {
		OpenTheDoor();
	} else {
	}
}

void ALockAndKey::OpenTheDoor()
{
	this->Destroy();
}