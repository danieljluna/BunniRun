// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BunniRun.h"
#include "BunniRunGameMode.h"
#include "BunniRunPlayerController.h"
#include "BunniRunCharacter.h"

ABunniRunGameMode::ABunniRunGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABunniRunPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}