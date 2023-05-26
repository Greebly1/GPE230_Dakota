// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGameMode.h"

void AMazeGameMode::InitGameState()
{
	Super::InitGameState();

	//if there is no override for the default pain
	if (DefaultPawnClass == ADefaultPawn::StaticClass()) {
		//Set the default pawn to my pawn
		DefaultPawnClass = DefaultPlayerCharacter;
	}

}
