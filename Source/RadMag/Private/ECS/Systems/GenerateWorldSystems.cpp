// Fill out your copyright notice in the Description page of Project Settings.

#include "ECS/Systems/GenerateWorldSystem.h"
#include "ECS/GameData.h"
#include "ECS/Commands/CreateCommands.h"
#include "ECS/Commands/HardCodeCommands.h"
#include "ECS/Systems/BasicSystemFactory.h"

USystem* UGenerateWorldSystem::MakeSystemGenerateWorld(const FCreateGameRulesContext& GenerateWorldContext,
                                                       UObject* Outer)
{
	const auto GenerateWorldSystem = [GenerateWorldContext](UGameData* GameData)
	{
		Commands::CreateGameRules(GenerateWorldContext, GameData);
		Commands::CreateDistricts(GameData);
		Commands::CreateWorldInfo(GameData);
		Commands::CreateResourcesAndBuildings(GameData);
		Commands::SetResources(GameData);
		Commands::SetCities(GameData);
	};
	return UBasicSystemFactory::CreateSystem(GenerateWorldSystem, Outer);
}
