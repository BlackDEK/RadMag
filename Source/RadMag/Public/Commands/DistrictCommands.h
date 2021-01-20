// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "BasicInternalCommands.h"
#include "GameData.h"
#include "HexMetricsCommands.h"
#include "Entities/District.h"

namespace DistrictCommands
{
	inline TPair<bool, FDistrict> GetDistrict(const FVector& Location, UGameData* GameData)
	{
		auto& World = GameData->World;
		const auto CubeCoordinate = HexMetricsCommands::ConvertToCubeCoordinate(Location, GameData);
		TArray<FDistrict> Districts;
		BasicInternalCommands::GetAll(Districts, GameData);
		entt::entity Id = entt::null;
		for (auto& District : Districts)
		{
			if (District.CubeCoordinate == CubeCoordinate)
			{
				Id = District.BasicData.Id;
				break;
			}
		}		
		if (!World.valid(Id))
			return TPair<bool, FDistrict>(false, FDistrict());
		const auto Entity = World.get<FDistrict>(Id);
		return TPair<bool, FDistrict>(true, Entity);
	}
}
