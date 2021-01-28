// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HexMetricsCommands.h"
#include "ECS/Entities/DistrictGroups.h"
#include "entt.hpp"

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

	template<typename StorageType>
	decltype(auto) AddResourcesInStorage(entt::registry& World, StorageType& Storage, entt::entity Mine)
	{
		const auto& FactoryOutput = World.get<FFactoryOutput>(Mine).Value;
		
		for(auto Resource : FactoryOutput)
		{
			const auto Index = Find(Storage, Resource.Key);
			if(Index == INDEX_NONE)
			{
				Add(Storage, Resource);
				continue;
			}

			Storage[Index].Value += Resource.Value;
		}		
	}
}
