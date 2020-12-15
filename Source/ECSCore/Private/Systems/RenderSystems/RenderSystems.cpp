#include "Systems/RenderSystems/RenderSystems.h"
#include "GameData.h"
#include "Entities/District.h"
#include "Systems/System.h"
#include "Systems/Utilities/CoordinateUtilities.h"

USystem* URenderSystems::MakeSystemPrepareRenderData(UObject* Outer)
{
	const auto SetSettings = MakeSystemSetRenderSettings();
	const LCommand PrepareRenderData = [SetSettings](UGameData* GameData)
	{
		SetSettings(GameData);
	};
	auto System = NewObject<USystem>(Outer);
	System->Init(PrepareRenderData);
	return System;
}

LCommand URenderSystems::MakeSystemSetRenderSettings()
{
	const LCommand LSetSettings = [](UGameData* GameData)
	{
		auto& World = GameData->World;
		auto& HexMetrics = World.emplace<FHexMetrics>(GameData->SettingsId);
		const auto OuterToInner = 0.866025404f;
		const auto OuterRadius = 10.f;
		const auto InnerRadius = OuterRadius * OuterToInner;

		HexMetrics.OuterToInner = OuterToInner;
		HexMetrics.OuterRadius = OuterRadius;

		HexMetrics.Corners[0] = FVector(0.f, OuterRadius, 0.f);
		HexMetrics.Corners[1] = FVector(InnerRadius, 0.5f * OuterRadius, 0.f);
		HexMetrics.Corners[2] = FVector(InnerRadius, -0.5f * OuterRadius, 0.f);
		HexMetrics.Corners[3] = FVector(0.f, -OuterRadius, 0.f);
		HexMetrics.Corners[4] = FVector(-InnerRadius, -0.5f * OuterRadius, 0.f);
		HexMetrics.Corners[5] = FVector(-InnerRadius, 0.5f * OuterRadius, 0.f);
		HexMetrics.Corners[6] = FVector(0.f, OuterRadius, 0.f);

		const auto& WorldSettings = World.get<FWorldSettings>(GameData->SettingsId);
		HexMetrics.ChunkSizeOX = WorldSettings.CommonDivisor;
		HexMetrics.ChunkSizeOY = WorldSettings.CommonDivisor;
		HexMetrics.ChunkCountOX = WorldSettings.Length / WorldSettings.CommonDivisor;
		HexMetrics.ChunkCountOY = WorldSettings.Height / WorldSettings.CommonDivisor;
	};

	return LSetSettings;
}


USystem* URenderSystems::MakeSystemGenerateChunkCache(TScriptInterface<IAbstractChunk> Chunk, UObject* Outer)
{
	const LCommand GenerateChunkCache = [Chunk](UGameData* GameData)
	{
		auto& World = GameData->World;
		const auto ChunkId = IAbstractChunk::Execute_GetId(Chunk.GetObject());

		TArray<FVector> Vertices;
		TArray<int32> Triangles;
		TArray<FLinearColor> VertexColors;

		const auto Districts = World.view<FDistrictData>();
		const auto HexMetrics = World.get<FHexMetrics>(GameData->SettingsId);

		SIZE_T HexCounter = 0;
		for (decltype(auto) District : Districts)
		{
			if (HexCounter == HexMetrics.ChunkSizeOX * HexMetrics.ChunkSizeOY) break;

			const auto CubeCoordinate = World.get<FDistrictData>(District).CubeCoordinate;
			const auto OffsetCoordinate = CoordinateUtilities::ConvertToOffsetCoordinate(CubeCoordinate);
			const auto HexChunkId = CoordinateUtilities::ConvertToChunkIndex(OffsetCoordinate, HexMetrics);
			if (HexChunkId != ChunkId) continue;

			const FVector Center = CoordinateUtilities::ConvertToRealCoordinate(OffsetCoordinate, HexMetrics);
			for (int32 Index = 0; Index < 6; Index++)
			{
				int32 VertexIndex = Vertices.Num();
				Vertices.Add(Center);
				Vertices.Add(Center + HexMetrics.Corners[Index]);
				Vertices.Add(Center + HexMetrics.Corners[Index + 1]);
				Triangles.Add(VertexIndex);
				Triangles.Add(VertexIndex + 1);
				Triangles.Add(VertexIndex + 2);
			}
			++HexCounter;
		}

		IAbstractChunk::Execute_OnCreateChunk(Chunk.GetObject(), Vertices, Triangles, VertexColors);
	};
	auto System = NewObject<USystem>(Outer);
	System->Init(GenerateChunkCache);
	return System;
}

USystem* URenderSystems::MakeSystemChunkCounter(TScriptInterface<IAbstractMap> Map, UObject* Outer)
{
	const LCommand ChunkCounter = [Map](UGameData* GameData)
	{
		auto& World = GameData->World;
		const auto HexMetrics = World.get<FHexMetrics>(GameData->SettingsId);		
		const int32 ChunkCounter = HexMetrics.ChunkCountOX * HexMetrics.ChunkSizeOY;
		IAbstractMap::Execute_OnGetChunkCounter(Map.GetObject(), ChunkCounter);
	};
	auto System = NewObject<USystem>(Outer);
	System->Init(ChunkCounter);
	return System;
}
