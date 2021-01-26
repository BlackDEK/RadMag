// Fill out your copyright notice in the Description page of Project Settings.

#include "ECS/Systems/GenerateChunkCache.h"
#include "ECS/GameData.h"
#include "ECS/Commands/RenderCommands.h"
#include "ECS/Commands/RenderCommandsContexts.h"
#include "ECS/Systems/BasicSystemFactory.h"


USystem* UGenerateChunkCache::MakeSystemGenerateChunksCache(TScriptInterface<IAbstractMap> Map, UObject* Outer)
{
	const auto GenerateChunksCache = [Map](UGameData* GameData)
	{
		auto& World = GameData->World;
		TArray<FChunkCache> Caches;
		Commands::GenerateChunksCache(Caches, World);
		IAbstractMap::Execute_OnGetChunkCache(Map.GetObject(), Caches);
	};
	return UBasicSystemFactory::CreateSystem(GenerateChunksCache, Outer);
}
