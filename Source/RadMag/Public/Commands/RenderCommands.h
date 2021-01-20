// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData.h"
#include "HexMetricsCommands.h"
#include "RenderCommandsContexts.h"
#include "Commands/BasicExternalCommands.h"
#include "Entities/District.h"

namespace RenderCommands
{
	inline void GenerateChunksCache(TArray<FChunkCache>& Caches, UGameData* GameData)
	{
		const auto Pair = BasicInternalCommands::Get<FGameRules>(GameData);
		if(Pair.Key == false) return;
		const auto GameRules = Pair.Value;
		TArray<FDistrict> Districts;
		BasicInternalCommands::GetAll(Districts, GameData);
		Caches.Init(FChunkCache(), GameRules.MapRules.ChunkCountOX * GameRules.MapRules.ChunkCountOY);
		
		for (decltype(auto) District : Districts)
		{
			const auto OffsetCoordinate = HexMetricsCommands::ConvertToOffsetCoordinate(District.CubeCoordinate);
			const auto ChunkId = HexMetricsCommands::ConvertToChunkIndex(OffsetCoordinate, GameData);
			const FVector Center = HexMetricsCommands::ConvertToRealCoordinate(OffsetCoordinate, GameData);
			for (int32 Index = 0; Index < 6; Index++)
			{
				int32 VertexIndex = Caches[ChunkId].Vertices.Num();
				Caches[ChunkId].Vertices.Add(Center);
				Caches[ChunkId].Vertices.Add(Center + GameRules.RenderRules.Corners[Index]);
				Caches[ChunkId].Vertices.Add(Center + GameRules.RenderRules.Corners[Index + 1]);
				Caches[ChunkId].Triangles.Add(VertexIndex);
				Caches[ChunkId].Triangles.Add(VertexIndex + 1);
				Caches[ChunkId].Triangles.Add(VertexIndex + 2);
			}
			
		}
	}
}
