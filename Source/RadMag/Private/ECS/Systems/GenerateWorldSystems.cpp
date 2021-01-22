// Fill out your copyright notice in the Description page of Project Settings.

#include "ECS/Systems/GenerateWorldSystem.h"
#include "ECS/GameData.h"
#include "ECS/Commands/CreateCommands.h"
#include "ECS/Systems/BasicSystemFactory.h"

USystem* UGenerateWorldSystem::MakeSystemGenerateWorld(const FCreateGameRulesContext& GenerateWorldContext,
                                                       UObject* Outer)
{
	const auto GenerateWorldSystem = [GenerateWorldContext](UGameData* GameData)
	{
		CreateCommands::CreateGameRules(GenerateWorldContext, GameData);
		CreateCommands::CreateDistricts(GameData);
		CreateCommands::CreateWorldInfo(GameData);
	};
	return UBasicSystemFactory::CreateSystem(GenerateWorldSystem, Outer);
}
