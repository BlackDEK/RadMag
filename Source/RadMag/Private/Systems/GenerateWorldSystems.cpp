// Fill out your copyright notice in the Description page of Project Settings.

#include "Systems/GenerateWorldSystem.h"
#include "GameData.h"
#include "Commands/ExternalCommands/BasicExternalCommands.h"
#include "Commands/InternalCommands/InternalCreateCommands.h"
#include "Systems/BasicSystemFactory.h"

USystem* UGenerateWorldSystem::MakeSystemGenerateWorld(const FCreateGameRulesContext& GenerateWorldContext,
                                                       UObject* Outer)
{
	const auto GenerateWorldSystem = [GenerateWorldContext](UGameData* GameData)
	{
		BasicExternalCommands::CreateGameRules(GenerateWorldContext, GameData);
		InternalCreateCommands::CreateDistricts(GameData);
		InternalCreateCommands::CreateWorldInfo(GameData);
	};
	return UBasicSystemFactory::CreateSystem(GenerateWorldSystem, Outer);
}
