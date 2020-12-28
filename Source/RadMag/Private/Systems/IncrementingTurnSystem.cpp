// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/IncrementingTurnSystem.h"
#include "GameData.h"
#include "Commands/InternalCommands/TurnCommands.h"
#include "Systems/BasicSystemFactory.h"
#include "Systems/System.h"

USystem* UIncrementingTurnSystem::MakeSystemIncrementingTurn(UObject* Outer)
{
	const auto IncrementingTurn = [](UGameData* GameData)
	{
		TurnCommands::IncrementingTurn(GameData);
	};
	return UBasicSystemFactory::CreateSystem(IncrementingTurn, Outer);
}
