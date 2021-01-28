// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BasicCommands.h"
#include "entt.hpp"
#include "ECS/Entities/BasicGroups.h"

namespace Commands
{
	inline void IncrementingTurn(entt::registry& World)
	{
		auto [CurrentTurn] =
                    Commands::GetGroupComponents<Groups::WorldInfo>(World);
		++CurrentTurn.Value;
	}
	
	//Рефактор
	inline void AddResourceInStorage(entt::registry& World)
	{
		/*
		TArray<entt::entity> DistrictWithCity;
		BasicCommands::GetAllIds<Types::DistrictWithCity>(GameData,DistrictWithCity);
		for(auto District : DistrictWithCity)
		{
			auto [DistrictData, CityData] = BasicCommands::Get
                <false, Types::District, FDistrictData, FCityData>
                (GameData, District);
			for (auto Building : CityData.Buildings)
			{
				if (Building.Key == entt::null)
					break;

				if(BasicCommands::IsValidEntityType<false, Types::Mine>(GameData, Building.Key))
				{
					const auto BuildingBasicData = BasicCommands::Get
                    <false, Types::Mine, FBasicData>
                    (GameData, Building.Key);					
				}

				if(BasicCommands::IsValidEntityType<false, Types::Factory>(GameData, Building.Key))
				{
					const auto BuildingBasicData = BasicCommands::Get
                    <false, Types::Factory, FBasicData>
                    (GameData, Building.Key);					
				}

				if(BasicCommands::IsValidEntityType<false, Types::Storage>(GameData, Building.Key))
				{
					const auto BuildingBasicData = BasicCommands::Get
                    <false, Types::Storage, FBasicData>
                    (GameData, Building.Key);				
				}
			}
		}
		*/
	}
}
