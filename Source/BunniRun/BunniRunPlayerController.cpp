// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BunniRun.h"
#include "BunniRunCharacter.h"
#include "BunniRunPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"

ABunniRunPlayerController::ABunniRunPlayerController()
{
	
}

void ABunniRunPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ABunniRunPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ABunniRunPlayerController::Move_XAxis);
    InputComponent->BindAxis("MoveRight", this, &ABunniRunPlayerController::Move_YAxis);

}



void ABunniRunPlayerController::Move_XAxis(float axisValue) {
    auto pawn = Cast<ABunniRunCharacter>(GetPawn());

    if (pawn) {
        pawn->Move_XAxis(axisValue);
    }
}



void ABunniRunPlayerController::Move_YAxis(float axisValue) {
    auto pawn = Cast<ABunniRunCharacter>(GetPawn());

    if (pawn) {
        pawn->Move_YAxis(axisValue);
    }
}
