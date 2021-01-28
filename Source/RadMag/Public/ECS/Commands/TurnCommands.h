// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BasicCommands.h"
#include "entt.hpp"
#include "ECS/Entities/BasicGroups.h"
#include "ECS/Entities/DistrictGroups.h"
#include "ECS/Commands/DistrictCommands.h"

namespace Commands
{
	inline void IncrementingTurn(entt::registry& World)
	{
		auto [CurrentTurn] =
			GetGroupComponents<Groups::WorldInfo>(World);
		++CurrentTurn.Value;
	}

	inline void WorkCycleStart(entt::registry& World)
	{
		auto CityView = GetView<Groups::City>(World);
		auto MineView = GetView<Groups::Mine>(World);

		std::for_each(CityView.begin(), CityView.end(),
		              [&World](auto& City)
		              {
			              auto [Buildings, Storage] =
				              GetGroupComponents<Groups::City>(World, City);

			              auto Building = ConvertToEntityArray(Buildings.Value);
			              auto Mines = GetOnlyHasGroup<Groups::Mine>
				              (World, Building);
			              std::for_each(Mines.begin(), Mines.end(),
			                            [&World, &Storage](auto& Mine)
			                            {
				                            Commands::AddResourcesInStorage(World, Storage.Value, Mine);
			                            }
			              );
		              }
		);
	}
}
