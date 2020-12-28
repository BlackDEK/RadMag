// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BasicInternalCommands.h"
#include "GameData.h"
#include "HexMetricsCommands.h"
#include "Entities/District.h"
#include "Entities/GameRules.h"

namespace InternalCreateCommands
{
	inline void CreateDistricts(UGameData* GameData)
	{
		auto& World = GameData->World;
		check(!World.valid(World.view<FDistrict>().front()));
		const auto Pair = BasicInternalCommands::Get<FGameRules>(GameData);
		check(Pair.Key);
		const auto MapRules = Pair.Value.MapRules;
		for (uint32 Y = 0; Y < MapRules.ChunkCountOY * MapRules.ChunkSize; Y++)
			for (uint32 X = 0; X < MapRules.ChunkCountOX * MapRules.ChunkSize; X++)
			{
				const auto DistrictId = World.create();
				auto& District = World.emplace<FDistrict>(DistrictId);
				District.BasicData.Id = DistrictId;
				District.BasicData.Name = FName("District_" + FString::FromInt(X) + "_" + FString::FromInt(Y));
				District.CubeCoordinate = HexMetricsCommands::ConvertToCubeCoordinate(FIntVector(X, Y, 0));
			}
	}
}
