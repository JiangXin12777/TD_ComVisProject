// Copyright Epic Games, Inc. All Rights Reserved.

#include "ComVisProjectGameMode.h"
#include "ComVisProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AComVisProjectGameMode::AComVisProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
