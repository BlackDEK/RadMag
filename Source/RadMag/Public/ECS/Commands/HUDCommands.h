// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCommands.h"
#include "DistrictCommands.h"
#include "entt.hpp"
#include "ECS/Entities/BasicGroups.h"
#include "ECS/Entities/GameRulesGroups.h"

namespace Commands
{	
	inline FText WorldInfoGetter(entt::registry& World)
	{	
		if (!Commands::IsValidGroups<Groups::WorldInfo>(World)) return FText();
		const auto [CurrentTurn] =
                    Commands::GetGroupComponents<Groups::WorldInfo>(World);
		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Entities: " + FString::FromInt(World.alive())));
		TextBuilder.AppendLine(FString("CurrentTurn: " + FString::FromInt(CurrentTurn.Value)));
		return TextBuilder.ToText();
		
	}

	inline FText DistrictInfoGetter(const FVector& Location, entt::registry& World)
	{
		const auto Entity = Commands::GetDistrictId(Location, World);
		if (Entity == entt::null) return FText();
		const auto& [EntityId, EntityName, Position, DistrictResources] = Commands::GetGroupComponents
            <Groups::BasicType, Groups::District>
            (World, Entity);

		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Id: " + FString::FromInt(static_cast<uint32>(EntityId.Value))));
		TextBuilder.AppendLine(FString("Name: " + EntityName.Value.ToString()));
		TextBuilder.AppendLine(FString(TEXT("CubeCoordinate: ") + Position.Value.ToString()));

		for (auto Resource : DistrictResources.Value)
		{			
			if (Resource.Key == entt::null)
				continue;
			const auto [ResourceId, ResourceName] = Commands::GetGroupComponents
                <false, Groups::BasicType>
                (World, Resource.Key);
			TextBuilder.AppendLine(FString(ResourceName.Value.ToString() + ": " + FString::FromInt(Resource.Value)));
		}

		return TextBuilder.ToText();
	}

	inline FText CityInfoGetter(const FVector& Location, entt::registry& World)
	{
		/*
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

	inline FText MapInfoGetter(entt::registry& World)
	{		
		if (!Commands::IsValidGroups<Groups::MapRules>(World)) return FText();
		auto [ChunkCountOX, ChunkCountOY, ChunkSize] =
            Commands::GetGroupComponents<Groups::MapRules>(World);
		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Length: " + FString::FromInt(ChunkCountOX.Value * ChunkSize.Value)));
		TextBuilder.AppendLine(FString("Height: " + FString::FromInt(ChunkCountOY.Value * ChunkSize.Value)));
		TextBuilder.AppendLine(FString(TEXT("ChunkSize: ") + FString::FromInt(ChunkSize.Value)));
		return TextBuilder.ToText();
	}
}
