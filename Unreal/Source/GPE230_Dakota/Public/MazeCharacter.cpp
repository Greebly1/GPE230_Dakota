// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeCharacter.h"


void AMazeCharacter::MoveFB(float value)
{
	AddMovementInput(GetActorForwardVector(), value * moveSpeed);
} 

void AMazeCharacter::MoveLR(float value)
{
	AddMovementInput(GetActorRightVector(), value * moveSpeed);
}

void AMazeCharacter::Rotation(float value)
{
	AddControllerYawInput(value * rotationSpeed);
}

// Called to bind functionality to input
void AMazeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AMazeCharacter::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AMazeCharacter::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AMazeCharacter::Rotation);
}


void AMazeCharacter::addHealth(float deltaHealth)
{
	currentHealth += deltaHealth;
	if (currentHealth > maxHealth) currentHealth = maxHealth;
}

float AMazeCharacter::getCurrentHealth()
{
	return currentHealth;
}

float AMazeCharacter::getMaxHealth()
{
	return maxHealth;
}

void AMazeCharacter::spawnStunParticles()
{
	if (stunParticles) {
		USceneComponent* AttachComp = GetDefaultAttachComponent();

		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(stunParticles,
			AttachComp, NAME_None, FVector(0), FRotator(0),
			EAttachLocation::KeepRelativeOffset, true);

			NiagaraComp->Activate();
	}
}

// Sets default values
AMazeCharacter::AMazeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMazeCharacter::BeginPlay()
{
	Super::BeginPlay();
	currentHealth = maxHealth;
	
}

// Called every frame
void AMazeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AMazeCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) {
	if (!_isDead) {
		//subtracting incoming damage
		currentHealth -= DamageAmount;

		UE_LOG(LogTemp, Log, TEXT("Player took %f damage. currentHealth = %f"), DamageAmount, currentHealth);

		if (currentHealth <= 0) {
			currentHealth = 0;
			Die();
		}

		return DamageAmount;
	}
	else return 0;
}

void AMazeCharacter::Die() {
	_isDead = true;
	currentHealth = 0;
	moveSpeed = 0;
	rotationSpeed = 0;

	
	GetMesh()->PlayAnimation(_deathAnim, false);
}