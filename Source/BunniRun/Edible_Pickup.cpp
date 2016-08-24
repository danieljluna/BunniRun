// Fill out your copyright notice in the Description page of Project Settings.

#include "BunniRun.h"
#include "Edible_Pickup.h"


// Sets default values
AEdible_Pickup::AEdible_Pickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    // Initialize CollisionBox
    pickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("pickupRoot"));
    RootComponent = pickupRoot;


    // Initialize Mesh
    pickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("pickupMesh"));
    pickupMesh->AttachToComponent(pickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

    // Set up Collision Box
    collisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("collisionBox"));
    collisionBox->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
    collisionBox->bGenerateOverlapEvents = true;
    collisionBox->OnComponentBeginOverlap.AddDynamic(this, &AEdible_Pickup::OnCollide);
    collisionBox->AttachToComponent(pickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
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

void AEdible_Pickup::OnCollide(UPrimitiveComponent * OverlappedComponent, AActor * other, UPrimitiveComponent * otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) {
    Destroy();
}

