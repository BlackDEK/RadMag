// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HexMetricsCommands.h"
#include "ECS/Entities/DistrictGroups.h"

namespace Commands
{
	inline entt::entity GetDistrictId(const FVector& Location, entt::registry& World)
	{
		const auto FindPosition = ConvertToCubeCoordinate(Location, World);

		entt::entity Result = entt::null;
		auto DistrictView = Commands::GetView<Groups::BasicType, Groups::District>(World);	
		for (auto District : DistrictView)
		{			
			const auto [EntityId, PositionComponent] = DistrictView.get
			<FEntityId, FPosition>(District);
			if (PositionComponent.Value == FindPosition)
			{
				Result = EntityId.Value;
				break;
			}					
		}
		return Result;
	}
}
