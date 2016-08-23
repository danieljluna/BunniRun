// Fill out your copyright notice in the Description page of Project Settings.

#include "BunniRun.h"
#include "Edible_Pickup.h"


// Sets default values
AEdible_Pickup::AEdible_Pickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //Initialize Mesh
    pickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("pickupMesh"));


}

// Called when the game starts or when spawned
void AEdible_Pickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEdible_Pickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

