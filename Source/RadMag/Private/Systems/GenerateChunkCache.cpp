// Fill out your copyright notice in the Description page of Project Settings.

#include "Systems/GenerateChunkCache.h"
#include "GameData.h"
#include "Commands/InternalCommands/RenderCommands.h"
#include "Commands/InternalCommands/RenderCommandsContexts.h"
#include "Systems/System.h"


USystem* UGenerateChunkCache::MakeSystemGenerateChunksCache(TScriptInterface<IAbstractMap> Map, UObject* Outer)
{
	const auto Command = [Map](UGameData* GameData)
	{	
		TArray<FChunkCache> Caches;
		RenderCommands::GenerateChunksCache(Caches, GameData);
		IAbstractMap::Execute_OnGetChunkCache(Map.GetObject(), Caches);
	};
	auto System = NewObject<USystem>(Outer);
	System->Init(Command);
	return System;
}
