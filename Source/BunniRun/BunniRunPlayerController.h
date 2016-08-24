// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
#include "BunniRunPlayerController.generated.h"

UCLASS()
class ABunniRunPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABunniRunPlayerController();

protected:

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Input handlers for SetDestination action. */
    void Move_XAxis(float axisValue);
    void Move_YAxis(float axisValue);
};


