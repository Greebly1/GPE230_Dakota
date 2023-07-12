// Fill out your copyright notice in the Description page of Project Settings.


#include "speedPickup.h"

void AspeedPickup::powerUp(AMazeCharacter* player)
{
	player->enableSpeedBoost(boostDuration);
}

bool AspeedPickup::canApplyPowerup(AMazeCharacter* player)
{
	return !(player->getSpeedBoostEnabled());
}
