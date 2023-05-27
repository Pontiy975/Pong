// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	_baseLocation = GetActorLocation();

	Reset();
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
}

void ABall::Move(float DeltaTime)
{
	FVector location = GetActorLocation();
	location += _direction * DeltaTime * _speed;
	SetActorLocation(location);
}

void ABall::Reset()
{
	SetActorLocation(_baseLocation);

	_direction = FMath::VRand();
	_direction.Z = 0;
}