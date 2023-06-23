// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MazeCharacter.generated.h"

UCLASS()
class GPE230_DAKOTA_API AMazeCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	/// <summary>
	/// The maximum health of this character
	/// </summary>
	UPROPERTY(EditAnywhere)
		float maxHealth;

protected:
	/// <summary>
	/// Current health, set to max health at runtime
	/// </summary>
	float currentHealth;

private:
	UPROPERTY(EditAnywhere)
		float moveSpeed;
	UPROPERTY(EditAnywhere)
		float rotationSpeed;
	UPROPERTY(EditAnywhere)
	UAnimSequence* _deathAnim;

	bool _isDead = false;

public:
	// Sets default values for this character's properties
	AMazeCharacter();

private:
	void MoveFB(float value);
	void MoveLR(float value);
	void Rotation(float value);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	virtual void Die(); 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
