// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/IncrementingTurnSystem.h"
#include "GameData.h"
#include "Commands/InternalCommands/TurnCommands.h"
#include "Systems/System.h"

USystem* UIncrementingTurnSystem::MakeSystemIncrementingTurn(UObject* Outer)
{
	const auto Command = [](UGameData* GameData)
	{
		TurnCommands::IncrementingTurn(GameData);
	};
	auto System = NewObject<USystem>(Outer);
	System->Init(Command);
	return System;
}
