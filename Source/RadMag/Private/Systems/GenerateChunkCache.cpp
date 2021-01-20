// Fill out your copyright notice in the Description page of Project Settings.

#include "Systems/GenerateChunkCache.h"
#include "GameData.h"
#include "Commands/RenderCommands.h"
#include "Commands/RenderCommandsContexts.h"
#include "Systems/BasicSystemFactory.h"
#include "Systems/System.h"


USystem* UGenerateChunkCache::MakeSystemGenerateChunksCache(TScriptInterface<IAbstractMap> Map, UObject* Outer)
{
	const auto GenerateChunksCache = [Map](UGameData* GameData)
	{	
		TArray<FChunkCache> Caches;
		RenderCommands::GenerateChunksCache(Caches, GameData);
		IAbstractMap::Execute_OnGetChunkCache(Map.GetObject(), Caches);
	};
	return UBasicSystemFactory::CreateSystem(GenerateChunksCache, Outer);
}
