// Fill out your copyright notice in the Description page of Project Settings.

#include "Systems/GenerateWorldSystem.h"
#include "GameData.h"
#include "Commands/ExternalCommands/BasicExternalCommands.h"
#include "Commands/InternalCommands/InternalCreateCommands.h"
#include "Systems/System.h"

USystem* UGenerateWorldSystem::MakeSystemGenerateWorld(const FCreateGameRulesContext& GenerateWorldContext,
                                                       UObject* Outer)
{
	const auto LGenerateWorld = [GenerateWorldContext](UGameData* GameData)
	{
		BasicExternalCommands::CreateGameRules(GenerateWorldContext, GameData);
		InternalCreateCommands::CreateDistricts(GameData);
	};
	auto Command = NewObject<USystem>(Outer);
	Command->Init(LGenerateWorld);
	return Command;
}
