// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealClass/MainCameraPawn.h"

// Sets default values
AMainCameraPawn::AMainCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

