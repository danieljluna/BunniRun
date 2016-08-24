// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Edible_Pickup.generated.h"

UCLASS()
class BUNNIRUN_API AEdible_Pickup : public AActor
{
	GENERATED_BODY()
	
public:	
    UPROPERTY(EditAnywhere)
    float nutritionValue = 1000;

	// Sets default values for this actor's properties
	AEdible_Pickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

    // Collision Function
    UFUNCTION()
    void OnCollide(UPrimitiveComponent* OverlappedComponent, AActor* other, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    // The root of the actor
    UPROPERTY(EditAnywhere)
    USceneComponent* pickupRoot;

    // The collision component
    UPROPERTY(EditAnywhere)
    UShapeComponent* collisionBox;

	// The mesh for our pickup
    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* pickupMesh;

	
};
