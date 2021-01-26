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
		auto& World = GameData->World;
		Commands::CreateGameRules(GenerateWorldContext, World);
		Commands::CreateDistricts(World);
		Commands::CreateWorldInfo(World);
		Commands::CreateResourcesAndBuildings(World);
		Commands::SetResources(World);
		Commands::SetCities(World);
	};
	return UBasicSystemFactory::CreateSystem(GenerateWorldSystem, Outer);
}
