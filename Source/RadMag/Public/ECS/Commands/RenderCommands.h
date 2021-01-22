﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ECS/GameData.h"
#include "HexMetricsCommands.h"
#include "RenderCommandsContexts.h"

namespace RenderCommands
{
	inline void GenerateChunksCache(TArray<FChunkCache>& Caches, UGameData* GameData)
	{
		const auto [MapRules, RenderRules] = BasicCommands::Get
		<true, Entities::GameRules, FMapRules, FRenderRules>
		(GameData);
		
		TArray<entt::entity> Districts;
		BasicCommands::GetAllIds<Entities::District>(GameData, Districts);
		Caches.Init(FChunkCache(), MapRules.ChunkCountOX * MapRules.ChunkCountOY);		
		for (auto District : Districts)
		{
			const auto DistrictData = BasicCommands::Get
            <false, Entities::District, FDistrictData>
            (GameData, District);
			const auto OffsetCoordinate = HexMetricsCommands::ConvertToOffsetCoordinate(DistrictData.CubeCoordinate);
			const auto ChunkId = HexMetricsCommands::ConvertToChunkIndex(OffsetCoordinate, GameData);
			const FVector Center = HexMetricsCommands::ConvertToRealCoordinate(OffsetCoordinate, GameData);
			for (int32 Index = 0; Index < 6; Index++)
			{
				int32 VertexIndex = Caches[ChunkId].Vertices.Num();
				Caches[ChunkId].Vertices.Add(Center);
				Caches[ChunkId].Vertices.Add(Center + RenderRules.Corners[Index]);
				Caches[ChunkId].Vertices.Add(Center + RenderRules.Corners[Index + 1]);
				Caches[ChunkId].Triangles.Add(VertexIndex);
				Caches[ChunkId].Triangles.Add(VertexIndex + 1);
				Caches[ChunkId].Triangles.Add(VertexIndex + 2);
			}
			
		}
	}
}