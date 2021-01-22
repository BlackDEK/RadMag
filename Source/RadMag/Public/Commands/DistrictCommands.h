// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicInternalCommands.h"
#include "GameData.h"
#include "HexMetricsCommands.h"
#include "Entities/Entities.h"

namespace DistrictCommands
{
	inline entt::entity GetDistrictId(const FVector& Location, UGameData* GameData)
	{
		const auto CubeCoordinate = HexMetricsCommands::ConvertToCubeCoordinate(Location, GameData);
		TArray<entt::entity> Ids;
		BasicInternalCommands::GetAllIds<Entities::District>(GameData, Ids);
		if (Ids.Num() == 0)
			return entt::null;

		entt::entity Result = entt::null;
		for (auto Id : Ids)
		{
			const auto District = BasicInternalCommands::Get
				<false, Entities::District, FDistrictData>
				(GameData, Id);

			if (District.CubeCoordinate == CubeCoordinate)
			{
				Result = Id;
				break;
			}
		}
		return Result;
	}
}
