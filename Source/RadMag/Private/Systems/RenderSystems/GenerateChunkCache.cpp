#include "Systems/RenderSystems/GenerateChunkCache.h"
#include "GameData.h"
#include "Entities/District.h"
#include "Handlers/DistrictHandler.h"
#include "Handlers/GameRulesHandler.h"
#include "Handlers/MathHandler.h"
#include "Systems/System.h"


USystem* UGenerateChunkCache::MakeSystemGenerateChunkCache(TScriptInterface<IAbstractMap> Map, UObject* Outer)
{
	const auto GenerateChunkCache = [Map](UGameData* GameData)
	{		
		const auto GameRules = UGameRulesHandler::GetGameRules(GameData);
		TArray<FDistrict> Districts;
		UDistrictHandler::GetAllDistrict(Districts, GameData);		
		TArray<FChunkCache> Cache;
		Cache.Init(FChunkCache(), GameRules.MapRules.ChunkCountOX * GameRules.MapRules.ChunkCountOY);
		
		for (decltype(auto) District : Districts)
		{
			const auto OffsetCoordinate = UMathHandler::ConvertToOffsetCoordinate(District.CubeCoordinate);
			const auto ChunkId = UMathHandler::ConvertToChunkIndex(OffsetCoordinate, GameData);

			const FVector Center = UMathHandler::ConvertToRealCoordinate(OffsetCoordinate, GameData);
			for (int32 Index = 0; Index < 6; Index++)
			{
				int32 VertexIndex = Cache[ChunkId].Vertices.Num();
				Cache[ChunkId].Vertices.Add(Center);
				Cache[ChunkId].Vertices.Add(Center + GameRules.RenderRules.Corners[Index]);
				Cache[ChunkId].Vertices.Add(Center + GameRules.RenderRules.Corners[Index + 1]);
				Cache[ChunkId].Triangles.Add(VertexIndex);
				Cache[ChunkId].Triangles.Add(VertexIndex + 1);
				Cache[ChunkId].Triangles.Add(VertexIndex + 2);
			}
			
		}

		IAbstractMap::Execute_OnGetChunkCache(Map.GetObject(), Cache);
	};
	auto System = NewObject<USystem>(Outer);
	System->Init(GenerateChunkCache);
	return System;
}
