// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCommands.h"
#include "entt.hpp"
#include "ECS/Entities/BasicGroups.h"
#include "ECS/Entities/GameRulesGroups.h"

//Рефактор
namespace Commands
{
	inline FText WorldInfoGetter(entt::registry& World)
	{	
		if (!Commands::IsValidGroups<Groups::WorldInfo>(World)) return FText();
		const auto [CurrentTurn] =
                    Commands::GetGroupComponents<true, Groups::WorldInfo>(World);
		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Entities: " + FString::FromInt(World.alive())));
		TextBuilder.AppendLine(FString("CurrentTurn: " + FString::FromInt(CurrentTurn.Value)));
		return TextBuilder.ToText();
		
	}

	inline FText DistrictInfoGetter(const FVector& Location, entt::registry& World)
	{
		/*
		const auto Entity = DistrictCommands::GetDistrictId(Location, GameData);
		if (Entity == entt::null) return FText();
		const auto [BasicData, DistrictData] = BasicCommands::Get
			<false, Types::District, FBasicData, FDistrictData>
			(GameData, Entity);

		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Id: " + FString::FromInt(static_cast<uint32>(BasicData.Id))));
		TextBuilder.AppendLine(FString("Name: " + BasicData.Name.ToString()));
		TextBuilder.AppendLine(FString(TEXT("CubeCoordinate: ") + DistrictData.CubeCoordinate.ToString()));

		for (auto Resource : DistrictData.Resources)
		{			
			if (Resource.Key == entt::null)
				continue;
			const auto ResourceBasicData = BasicCommands::Get
                <false, Types::Resource, FBasicData>
                (GameData, Resource.Key);
			TextBuilder.AppendLine(FString(ResourceBasicData.Name.ToString() + ": " + FString::FromInt(Resource.Value)));
		}

		if(BasicCommands::IsValidEntityType<false, Types::DistrictWithCity>(GameData, Entity))
		{
			const auto CityData = BasicCommands::Get
                <false, Types::DistrictWithCity, FCityData>
                (GameData, Entity);
			for (auto Building : CityData.Buildings)
			{			
				if (Building.Key == entt::null)
					break;

				if(BasicCommands::IsValidEntityType<false, Types::Mine>(GameData, Building.Key))
				{
					const auto BuildingBasicData = BasicCommands::Get
                    <false, Types::Mine, FBasicData>
                    (GameData, Building.Key);
					TextBuilder.AppendLine(FString(BuildingBasicData.Name.ToString() + ": " + FString::FromInt(Building.Value)));					
				}

				if(BasicCommands::IsValidEntityType<false, Types::Factory>(GameData, Building.Key))
				{
					const auto BuildingBasicData = BasicCommands::Get
                    <false, Types::Factory, FBasicData>
                    (GameData, Building.Key);
					TextBuilder.AppendLine(FString(BuildingBasicData.Name.ToString() + ": " + FString::FromInt(Building.Value)));					
				}

				if(BasicCommands::IsValidEntityType<false, Types::Storage>(GameData, Building.Key))
				{
					const auto BuildingBasicData = BasicCommands::Get
                    <false, Types::Storage, FBasicData>
                    (GameData, Building.Key);
					TextBuilder.AppendLine(FString(BuildingBasicData.Name.ToString() + ": " + FString::FromInt(Building.Value)));					
				}
			}			
		}

		return TextBuilder.ToText();
		*/
		
		return FText();
	}

	inline FText DistrictInfoGetter_New(const FVector& Location, entt::registry& World)
	{

		return FText();
	}

	inline FText MapInfoGetter(entt::registry& World)
	{
		
		if (!Commands::IsValidGroups<Groups::MapRules>(World)) return FText();
		auto [ChunkCountOX, ChunkCountOY, ChunkSize] =
            Commands::GetGroupComponents<true, Groups::MapRules>(World);
		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Length: " + FString::FromInt(ChunkCountOX.Value * ChunkSize.Value)));
		TextBuilder.AppendLine(FString("Height: " + FString::FromInt(ChunkCountOY.Value * ChunkSize.Value)));
		TextBuilder.AppendLine(FString(TEXT("ChunkSize: ") + FString::FromInt(ChunkSize.Value)));
		return TextBuilder.ToText();
	}
}
