// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "entt.hpp"

namespace Commands
{
	inline void CreateResourcesAndBuildings(entt::registry& World)
	{
		
		TMap<FName, entt::entity> Resources = {
			{"Wood", entt::null}, {"Food", entt::null},
			{"Metal", entt::null}, {"Tool", entt::null}
		};
		for (auto& Name : Resources)
		{
			const auto Entity = Commands::AddGroups
			<true, Groups::BasicType, Groups::Resource>(World);
			auto [ EntityId, EntityName ] = Commands::GetGroupComponents<false, Groups::BasicType>(World, Entity);
			EntityId.Value = Entity;
			EntityName.Value = Name.Key;
			Resources[Name.Key] = Entity;
		}

		//Список необходимых фабрик
		TArray<FName> Factory = {
			{"Farm"}, {"Mine"}, {"Sawmill"}, {"Workshop"},
		};

		TArray<FName> Storage = {
			{"Storage"}
        };

		{
			const auto Farm = Commands::AddGroups<true, Groups::BasicType, Groups::Building, Groups::Mine>(World);
			auto [EntityId, EntityName, FactoryInput, FactoryOutput] = Commands::GetGroupComponents
				<false, Groups::BasicType, Groups::Mine>(World, Farm);
			EntityId.Value = Farm;
			EntityName.Value = FName("Farm");
			FactoryOutput.Value[0] = MakeTuple(Resources["Food"], 2);
		}
		{
			/*
			const auto Storage = BasicCommands::CreateEntity<Types::Storage>(GameData);
			auto [BasicData, StorageData] = BasicCommands::Get
				<false, Types::Storage, FBasicData, FStorageData>(GameData, Storage);
			BasicData.Id = Storage;
			BasicData.Name = FName("Storage");
			*/
		}
	}

	inline void SetCities(entt::registry& World)
	{
		/*
		TArray<entt::entity> Districts;
		BasicCommands::GetAllIds<Types::District>(GameData, Districts);

		for (auto Index = 0; Index < Districts.Num(); Index++)
			if (Index % 2 == 0)
			{
				const auto Entity = BasicCommands::ExpandEntity
				<false, Types::DistrictWithCity>
				(GameData, Districts[Index]);
				
				const auto FarmBasicData = BasicCommands::Get<true, Types::Mine, FBasicData>(GameData);
				const auto StorageBasicData = BasicCommands::Get<true, Types::Storage, FBasicData>(GameData);

				decltype(auto) CityData = BasicCommands::Get
				<false, Types::DistrictWithCity, FCityData>
				(GameData, Entity);
				CityData.Buildings[0] = MakeTuple(FarmBasicData.Id, 1);
				CityData.Buildings[1] = MakeTuple(StorageBasicData.Id, 1);
			}
			*/
	}

	inline void SetResources(entt::registry& World)
	{		
		auto DistrictView = Commands::GetView<Groups::BasicType, Groups::District>(World);

		auto ResourcesView = Commands::GetView<Groups::BasicType, Groups::Resource>(World);

		for (auto District : DistrictView)
		{
			auto& DistrictResources = DistrictView.get<FDistrictResources>(District);

			std::size_t Index = 0;
			for(auto Resource : ResourcesView)
				if(Index < DistrictResources.Value.Num())
				{					
					DistrictResources.Value[Index] = MakeTuple(Resource, 100);
					++Index;
				}
		}
	}
}
