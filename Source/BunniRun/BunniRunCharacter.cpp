// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BunniRun.h"
#include "BunniRunCharacter.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"

ABunniRunCharacter::ABunniRunCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

}

void ABunniRunCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    //Handle Velocity Movement
    if (!movementDir.IsZero()) {
        FVector newLocation = GetActorLocation() + (maxSpeed * DeltaSeconds * movementDir);
        SetActorLocation(newLocation);
    }
}

void ABunniRunCharacter::Move_XAxis(float axisValue) {
    if ((Controller != NULL) && (axisValue != 0.0f)) {
        // find out which way is right
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // get right vector 
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        // add movement in that direction
        AddMovementInput(Direction, axisValue);
    }
}

void ABunniRunCharacter::Move_YAxis(float axisValue) {
    if ((Controller != NULL) && (axisValue != 0.0f)) {
        // find out which way is forward
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // get forward vector
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, axisValue);
    }
}

void ABunniRunCharacter::eatFood(float nutritionValue) {
    
    //If we are large enough to eat it
    if (totalNutrition >= nutritionValue) {

        totalNutrition += nutritionValue / (GetActorScale3D().X);

        SetActorScale3D(FVector(totalNutrition / 10.0f));
        UE_LOG(LogTemp, Warning, TEXT("NUTRITION UPPED"));
        
    }
}
