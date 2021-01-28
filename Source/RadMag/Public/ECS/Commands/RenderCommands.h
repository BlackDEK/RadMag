// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HexMetricsCommands.h"
#include "RenderCommandsContexts.h"
#include "ECS/Entities/DistrictGroups.h"

namespace Commands
{
	inline void GenerateChunksCache(TArray<FChunkCache>& Caches, entt::registry& World)
	{
		const auto [ChunkCountOX, ChunkCountOY, ChunkSize, OuterToInner, OuterRadius, Corners]
		= Commands::GetGroupComponents<Groups::MapRules, Groups::RenderRules>(World);
		Caches.Init(FChunkCache(), ChunkCountOX.Value * ChunkCountOY.Value);

		auto DistrictView = Commands::GetView<Groups::District>(World);	
		for (auto District : DistrictView)
		{			
			const auto Position = DistrictView.get<FPosition>(District);
			const auto OffsetCoordinate = ConvertToOffsetCoordinate(Position.Value);
			const auto ChunkId = ConvertToChunkIndex(OffsetCoordinate, World);
			const FVector Center = ConvertToRealCoordinate(OffsetCoordinate, World);			
			for (int32 Index = 0; Index < 6; Index++)
			{
				int32 VertexIndex = Caches[ChunkId].Vertices.Num();
				Caches[ChunkId].Vertices.Add(Center);
				Caches[ChunkId].Vertices.Add(Center + Corners.Value[Index]);
				Caches[ChunkId].Vertices.Add(Center + Corners.Value[Index + 1]);
				Caches[ChunkId].Triangles.Add(VertexIndex);
				Caches[ChunkId].Triangles.Add(VertexIndex + 1);
				Caches[ChunkId].Triangles.Add(VertexIndex + 2);
			}			
		}
	}
}
