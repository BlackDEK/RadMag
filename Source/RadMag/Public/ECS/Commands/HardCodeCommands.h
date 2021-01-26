// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "entt.hpp"

//Рефактор!
namespace Commands
{
	inline void CreateResourcesAndBuildings(entt::registry& World)
	{
		/*
		TMap<FName, entt::entity> Resources = {
			{"Wood", entt::null}, {"Food", entt::null},
			{"Metal", entt::null}, {"Tool", entt::null}
		};
		for (auto& Name : Resources)
		{
			const auto Entity = BasicCommands::CreateEntity<Types::Resource>(GameData);
			decltype(auto) BasicData = BasicCommands::Get<false, Types::Resource, FBasicData>(GameData, Entity);
			BasicData.Id = Entity;
			BasicData.Name = Name.Key;
			Resources[Name.Key] = Entity;
		}

		//Список необходимых фабрик
		TArray<FName> Factory = {
			{"Farm"}, {"Mine"}, {"Sawmill"}, {"Workshop"},
		};

		{
			const auto Farm = BasicCommands::CreateEntity<Types::Mine>(GameData);
			auto [BasicData, FactoryData] = BasicCommands::Get
				<false, Types::Mine, FBasicData, FFactoryData>(GameData, Farm);
			BasicData.Id = Farm;
			BasicData.Name = FName("Farm");
			FactoryData.Output[0] = TPair<entt::entity, int32>(Resources["Food"], 2);
		}
		{
			const auto Storage = BasicCommands::CreateEntity<Types::Storage>(GameData);
			auto [BasicData, StorageData] = BasicCommands::Get
				<false, Types::Storage, FBasicData, FStorageData>(GameData, Storage);
			BasicData.Id = Storage;
			BasicData.Name = FName("Storage");
		}
		*/
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
		/*
		TArray<entt::entity> Districts;
		BasicCommands::GetAllIds<Types::District>(GameData, Districts);

		TArray<entt::entity> Resources;
		BasicCommands::GetAllIds<Types::Resource>(GameData, Resources);
		TArray<TPair<entt::entity, int32>> ResourcesForDistrict;
		for (auto Resource : Resources)
			ResourcesForDistrict.Add(TPair<entt::entity, int32>(Resource, 100));

		for (auto District : Districts)
		{
			decltype(auto) DistrictData = BasicCommands::Get
				<false, Types::District, FDistrictData>
				(GameData, District);

			for (auto Index = 0; Index < DistrictData.Resources.Num(); Index++)
			{
				if (ResourcesForDistrict.IsValidIndex(Index))
					DistrictData.Resources[Index] = ResourcesForDistrict[Index];
			}
		}
		*/
	}
}
