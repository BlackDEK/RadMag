// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoordinateUtilities.h"
#include "GameData.h"
#include "Entities/District.h"
#include "Entities/Settings.h"

/** */
namespace DistrictsUtilities
{
	static FORCEINLINE entt::entity DistrictsHex(const FVector& Location, UGameData* GameData)
	{		
		auto& World = GameData->World;
		const auto& HexMetrics = World.get<FHexMetrics>(GameData->SettingsId);
		const auto CubeCoordinate = CoordinateUtilities::ConvertToCubeCoordinate(Location, HexMetrics);
		const auto Districts = World.view<FDistrictData>();
		for(auto& District : Districts)
		{
			if(World.get<FDistrictData>(District).CubeCoordinate == CubeCoordinate)
				return District;
		}
		return entt::entity{ entt::null };
	}
}