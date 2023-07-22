// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

#include "MazeCharacter.generated.h"

UCLASS()
class GPE230_DAKOTA_API AMazeCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	/// <summary>
	/// The maximum health of this character
	/// </summary>
	

protected:
	
	
	UPROPERTY(EditAnywhere)
		float maxHealth;

private:
	UPROPERTY(EditAnywhere)
		float moveSpeed;
	UPROPERTY(EditAnywhere)
		float rotationSpeed;
	UPROPERTY(EditAnywhere)
	UAnimSequence* _deathAnim;

	// Current health is initialied to max health on startup
	float currentHealth;

	bool _isDead = false;

	UPROPERTY(EditAnywhere)
		UNiagaraSystem* stunParticles;

public:
	// Sets default values for this character's properties
	AMazeCharacter();

	UPROPERTY(EditAnywhere)
		float speedScalarforPowerup;
	UPROPERTY(EditAnywhere)
	bool speedBoostActive;

private:
	void MoveFB(float value);
	void MoveLR(float value);
	void Rotation(float value);
	//blueprint node that spawns stun particle system on pawn location
	UFUNCTION(BlueprintCallable)
		void spawnStunParticles();

	FTimerHandle speedBoostDurationTimerHandle;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	//sets movement scalars to 0 and plays death anim
	virtual void Die(); 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void addHealth(float deltaHealth);

	UFUNCTION(BlueprintCallable)
	float getCurrentHealth();

	UFUNCTION(BlueprintCallable)
	float getMaxHealth();

	void enableSpeedBoost(float duration);

	void disableSpeedBoost();

	bool getSpeedBoostEnabled();

};
