// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCEnemy.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h "

// Sets default values
ANPCEnemy::ANPCEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPCEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPCEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Called using animnotify for outgoing attacks
void ANPCEnemy::DetectHit()
{
	//Used so spheretracemulti only calls once
	bool canDamage = true;

	//Location of fist
	const FVector PunchLocation = GetMesh()->GetSocketLocation(_PunchingHandSocket);

	//Array of actors ignored by spheretrace
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this); //ignore this controller
	ActorsToIgnore.Add(GetOwner()); //ignore this pawn

	//Array of actors hit by spheretrace
	TArray<FHitResult> HitArray;

	//Sphere trace located at fist
	const bool Hit = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), PunchLocation, PunchLocation, _TraceRadius,
		UEngineTypes::ConvertToTraceType(ECC_Camera), false, ActorsToIgnore, EDrawDebugTrace::None, HitArray,
		true, FLinearColor::Red, FLinearColor::Green, 2.0f);

	FString ownerName = this->GetName();

	if (Hit)
	{
		for (const FHitResult HitResult : HitArray)
		{
			if (canDamage)
			{
				FString hitActorName = HitResult.GetActor()->GetName();

				UE_LOG(LogTemp, Log, TEXT("NPCEnemy actor \"%s\" hit other actor \"%s\" , dealing %f damage."), *ownerName, *hitActorName, _HitDamage);
			
				//apply damage to target
				UGameplayStatics::ApplyDamage(HitResult.GetActor(), _HitDamage, GetController(), this, UDamageType::StaticClass());

				//Can't damage until next function call
				canDamage = false;
			}
		}
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("NPCEnemy actor \"%s\", hit no actor."), *ownerName);
	}
}

