// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "BunniRunCharacter.generated.h"

UCLASS(Blueprintable)
class ABunniRunCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABunniRunCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

    //Deals with movement in the bunni

    /** Input handlers for movement. */
    void Move_XAxis(float axisValue);
    void Move_YAxis(float axisValue);

    //Stores movement data about the Bunny
    UPROPERTY(EditAnywhere)
    float maxSpeed = 1000.0f;
    FVector movementDir;

    //Used to gain nutrition
    void eatFood(float nutritionValue);
    
    //Stores size 
    UPROPERTY(EditAnywhere)
    float totalNutrition = 10;
    
    UPROPERTY(EditAnywhere)
    float consumptionEfficiency = 1.0f;

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

};

