// Fill out your copyright notice in the Description page of Project Settings.

#include "Systems/EditorSystems/GenerateWorldSystem.h"
#include "GameData.h"
#include "Handlers/DistrictHandler.h"
#include "Handlers/GameRulesHandler.h"

USystem* UGenerateWorldSystem::MakeSystemGenerateWorld(const FGenerateWorldContext& GenerateWorldContext, UObject* Outer)
{
	const auto SetSetting = MakeSystemSetSettings(GenerateWorldContext);
	const auto GenerateMap = MakeSystemGenerateMap();
	const auto LGenerateWorld = [SetSetting, GenerateMap](UGameData* GameData)
	{
		SetSetting(GameData);
		GenerateMap(GameData);
	};
	auto Command = NewObject<USystem>(Outer);
	Command->Init(LGenerateWorld);
	return Command;
}

TFunction<void(UGameData*)> UGenerateWorldSystem::MakeSystemSetSettings(const FGenerateWorldContext& GenerateWorldContext)
{
	const TFunction<void(UGameData*)> LSetSettings = [GenerateWorldContext](UGameData* GameData)
	{
		UGameRulesHandler::CreateGameRules(GenerateWorldContext,GameData);
	};
	return LSetSettings;
}

TFunction<void(UGameData*)> UGenerateWorldSystem::MakeSystemGenerateMap()
{
	const TFunction<void(UGameData*)> LGenerateMap = [](UGameData* GameData)
	{
		UDistrictHandler::CreateDistricts(GameData);
	};
	return LGenerateMap;
}
