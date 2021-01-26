// Fill out your copyright notice in the Description page of Project Settings.


#include "ECS/Systems/IncrementingTurnSystem.h"
#include "ECS/GameData.h"
#include "ECS/Commands/TurnCommands.h"
#include "ECS/Systems/BasicSystemFactory.h"
#include "ECS/Systems/System.h"

USystem* UIncrementingTurnSystem::MakeSystemIncrementingTurn(UObject* Outer)
{
	const auto IncrementingTurn = [](UGameData* GameData)
	{
		Commands::IncrementingTurn(GameData);
	};
	return UBasicSystemFactory::CreateSystem(IncrementingTurn, Outer);
}
