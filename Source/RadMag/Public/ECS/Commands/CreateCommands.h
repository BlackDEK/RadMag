// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BasicCommands.h"
#include "ECS/GameData.h"
#include "HexMetricsCommands.h"

namespace CreateCommands
{
	inline void CreateGameRules(const FCreateGameRulesContext& Context, UGameData* GameData)
	{
		auto GameRulesCreated = BasicCommands::IsValidEntity
            <true, Entities::GameRules>(GameData);
		check(!GameRulesCreated);
		
		const auto Entity = BasicCommands::CreateEntity<Entities::GameRules>(GameData);
		
		auto [MapRules, RenderRules] = BasicCommands::Get
            <false, Entities::GameRules, FMapRules, FRenderRules>(GameData, Entity);
		
		MapRules.ChunkCountOX = Context.ChunkCountOX;
		MapRules.ChunkCountOY = Context.ChunkCountOY;
		MapRules.ChunkSize = Context.ChunkSize;

		const auto OuterToInner = 0.866025404f;
		const auto OuterRadius = 10.f;
		const auto InnerRadius = OuterRadius * OuterToInner;
		
		RenderRules.OuterToInner = OuterToInner;
		RenderRules.OuterRadius = OuterRadius;

		RenderRules.Corners[0] = FVector(0.f, OuterRadius, 0.f);
		RenderRules.Corners[1] = FVector(InnerRadius, 0.5f * OuterRadius, 0.f);
		RenderRules.Corners[2] = FVector(InnerRadius, -0.5f * OuterRadius, 0.f);
		RenderRules.Corners[3] = FVector(0.f, -OuterRadius, 0.f);
		RenderRules.Corners[4] = FVector(-InnerRadius, -0.5f * OuterRadius, 0.f);
		RenderRules.Corners[5] = FVector(-InnerRadius, 0.5f * OuterRadius, 0.f);
		RenderRules.Corners[6] = FVector(0.f, OuterRadius, 0.f);
	}
	
	inline void CreateDistricts(UGameData* GameData)
	{
		const auto HexCreated = BasicCommands::IsValidEntity
			<true, Entities::District>(GameData);
		check(!HexCreated);

		const auto MapRules = BasicCommands::Get<true, Entities::GameRules, FMapRules>(GameData);

		for (uint32 Y = 0; Y < MapRules.ChunkCountOY * MapRules.ChunkSize; Y++)
			for (uint32 X = 0; X < MapRules.ChunkCountOX * MapRules.ChunkSize; X++)
			{
				const auto Entity = BasicCommands::CreateEntity<Entities::District>(GameData);
				auto [BasicData, DistrictData] = BasicCommands::Get
				<false, Entities::District, FBasicData, FDistrictData>
				(GameData, Entity);
				
				BasicData.Id = Entity;
				BasicData.Name = FName("District_" + FString::FromInt(X) + "_" + FString::FromInt(Y));
				DistrictData.CubeCoordinate = HexMetricsCommands::ConvertToCubeCoordinate(FIntVector(X, Y, 0));
			}
	}

	inline void CreateWorldInfo(UGameData* GameData)
	{
		const auto WorldInfoCreated = BasicCommands::IsValidEntity
            <true, Entities::WorldInfo>(GameData);
		check(!WorldInfoCreated);		
		
		const auto Entity = BasicCommands::CreateEntity<Entities::WorldInfo>(GameData);
		decltype(auto) WorldInfo = BasicCommands::Get
                    <false, Entities::WorldInfo, FWorldInfo>(GameData, Entity);
		WorldInfo.CurrentTurn = 0;		
	}
}
