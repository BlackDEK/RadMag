// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "DistrictCommands.h"
#include "GameData.h"
#include "Entities/WorldInfo.h"

namespace HUDCommands
{
	inline FText WorldInfoGetter(UGameData* GameData)
	{
		const auto Pair = BasicInternalCommands::Get<FWorldInfo>(GameData);
		if(Pair.Key == false) return FText();
		const auto WorldInfo = Pair.Value;	
		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Entities: " + FString::FromInt(GameData->World.alive())));
		TextBuilder.AppendLine(FString("CurrentTurn: " + FString::FromInt(WorldInfo.CurrentTurn)));
		return TextBuilder.ToText();
	}

	inline FText DistrictInfoGetter(const FVector& Location, UGameData* GameData)
	{
		const auto Pair  = DistrictCommands::GetDistrict(Location, GameData);
		if(Pair.Key == false) return FText();
		const auto District = Pair.Value;	
		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Id: " + FString::FromInt(static_cast<uint32>(District.BasicData.Id))));
		TextBuilder.AppendLine(FString("Name: " + District.BasicData.Name.ToString()));
		TextBuilder.AppendLine(FString(TEXT("CubeCoordinate: ") + District.CubeCoordinate.ToString()));		
		return TextBuilder.ToText();
	}

	inline FText MapInfoGetter(UGameData* GameData)
	{
		const auto Pair = BasicInternalCommands::Get<FGameRules>(GameData);
		if(Pair.Key == false) return FText();
		const auto MapRules = Pair.Value.MapRules;	
		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Length: " + FString::FromInt(MapRules.ChunkCountOX * MapRules.ChunkSize)));
		TextBuilder.AppendLine(FString("Height: " + FString::FromInt(MapRules.ChunkCountOY * MapRules.ChunkSize)));
		TextBuilder.AppendLine(FString(TEXT("ChunkSize: ") + FString::FromInt(MapRules.ChunkSize)));
		return TextBuilder.ToText();
	}
}
