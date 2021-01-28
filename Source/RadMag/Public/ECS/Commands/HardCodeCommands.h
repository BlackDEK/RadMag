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
			const auto Entity = World.create();
			Commands::AddGroups<Groups::BasicType, Groups::Resource>(World, Entity);
			auto [EntityId, EntityName] = Commands::GetGroupComponents<Groups::BasicType>(World, Entity);
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
			const auto Farm = World.create();
			Commands::AddGroups<Groups::BasicType, Groups::Building, Groups::Mine>(World, Farm);
			auto [EntityId, EntityName, FactoryInput, FactoryOutput] = Commands::GetGroupComponents
				<Groups::BasicType, Groups::Mine>(World, Farm);
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
		auto BuildingsView = Commands::GetView<Groups::BasicType, Groups::Building>(World);		
		int32 Index = 0;
		auto DistrictView =
			Commands::GetView<Groups::BasicType, Groups::District>(World);
		std::for_each(DistrictView.begin(), DistrictView.end(),
		              [&World, &Index, BuildingsView](auto& District)
		              {
		              	if(Index % 8 != 0)
		              	{		              				              	
		              		Index++;
		              		return;
		              	}
		              	Commands::AddGroups<Groups::City>(World, District);

		              	auto& CityBuildings = World.get<FCityBuildings>(District);
		              	auto BuildingIndex = 0;
		              	for(auto Building : BuildingsView)
		              	{
		              		if(BuildingIndex > CityBuildings.Value.Num())
		              			break;

		              		CityBuildings.Value[BuildingIndex] =
		              			MakeTuple(BuildingsView.get<FEntityId>(Building).Value, 1);

		              		BuildingIndex++;
		              	}		              	
		              	Index++;
		              }
		);
	}

	inline void SetResources(entt::registry& World)
	{
		auto DistrictView = Commands::GetView<Groups::BasicType, Groups::District>(World);

		auto ResourcesView = Commands::GetView<Groups::BasicType, Groups::Resource>(World);

		for (auto District : DistrictView)
		{
			auto& DistrictResources = DistrictView.get<FDistrictResources>(District);

			std::size_t Index = 0;
			for (auto Resource : ResourcesView)
				if (Index < DistrictResources.Value.Num())
				{
					DistrictResources.Value[Index] = MakeTuple(Resource, 100);
					++Index;
				}
		}
	}
}
