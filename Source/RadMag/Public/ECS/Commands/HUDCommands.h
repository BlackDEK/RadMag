// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DistrictCommands.h"
#include "ECS/GameData.h"
#include "ECS/Entities/Entities.h"

namespace HUDCommands
{
	inline FText WorldInfoGetter(UGameData* GameData)
	{
		if (!BasicCommands::IsValidEntity<true, Entities::WorldInfo>(GameData)) return FText();
		const auto WorldInfo = BasicCommands::Get<true, Entities::WorldInfo, FWorldInfo>(GameData);
		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Entities: " + FString::FromInt(GameData->World.alive())));
		TextBuilder.AppendLine(FString("CurrentTurn: " + FString::FromInt(WorldInfo.CurrentTurn)));
		return TextBuilder.ToText();
	}

	inline FText DistrictInfoGetter(const FVector& Location, UGameData* GameData)
	{
		const auto Entity = DistrictCommands::GetDistrictId(Location, GameData);
		if (Entity == entt::null) return FText();
		const auto [BasicData, DistrictData] = BasicCommands::Get
			<false, Entities::District, FBasicData, FDistrictData>
			(GameData, Entity);
		
		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Id: " + FString::FromInt(static_cast<uint32>(BasicData.Id))));
		TextBuilder.AppendLine(FString("Name: " + BasicData.Name.ToString()));
		TextBuilder.AppendLine(FString(TEXT("CubeCoordinate: ") + DistrictData.CubeCoordinate.ToString()));
		return TextBuilder.ToText();
	}

	inline FText MapInfoGetter(UGameData* GameData)
	{
		if (!BasicCommands::IsValidEntity<true, Entities::GameRules>(GameData)) return FText();
		const auto MapRules = BasicCommands::Get<true, Entities::GameRules, FMapRules>(GameData);	
		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Length: " + FString::FromInt(MapRules.ChunkCountOX * MapRules.ChunkSize)));
		TextBuilder.AppendLine(FString("Height: " + FString::FromInt(MapRules.ChunkCountOY * MapRules.ChunkSize)));
		TextBuilder.AppendLine(FString(TEXT("ChunkSize: ") + FString::FromInt(MapRules.ChunkSize)));
		return TextBuilder.ToText();
	}
}
