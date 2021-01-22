// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BasicInternalCommands.h"
#include "GameData.h"
#include "HexMetricsCommands.h"

namespace InternalCreateCommands
{
	inline void CreateDistricts(UGameData* GameData)
	{
		const auto HexCreated = BasicInternalCommands::IsValidEntity
			<true, Entities::District>(GameData);
		check(!HexCreated);

		const auto MapRules = BasicInternalCommands::Get<true, Entities::GameRules, FMapRules>(GameData);

		for (uint32 Y = 0; Y < MapRules.ChunkCountOY * MapRules.ChunkSize; Y++)
			for (uint32 X = 0; X < MapRules.ChunkCountOX * MapRules.ChunkSize; X++)
			{
				const auto Entity = BasicInternalCommands::CreateEntity<Entities::District>(GameData);
				auto [BasicData, DistrictData] = BasicInternalCommands::Get
				<false, Entities::District, FBasicData, FDistrictData>
				(GameData, Entity);
				
				BasicData.Id = Entity;
				BasicData.Name = FName("District_" + FString::FromInt(X) + "_" + FString::FromInt(Y));
				DistrictData.CubeCoordinate = HexMetricsCommands::ConvertToCubeCoordinate(FIntVector(X, Y, 0));
			}
	}

	inline void CreateWorldInfo(UGameData* GameData)
	{
		const auto WorldInfoCreated = BasicInternalCommands::IsValidEntity
            <true, Entities::WorldInfo>(GameData);
		check(!WorldInfoCreated);		
		
		const auto Entity = BasicInternalCommands::CreateEntity<Entities::WorldInfo>(GameData);
		decltype(auto) WorldInfo = BasicInternalCommands::Get
                    <false, Entities::WorldInfo, FWorldInfo>(GameData, Entity);
		WorldInfo.CurrentTurn = 0;		
	}
}
