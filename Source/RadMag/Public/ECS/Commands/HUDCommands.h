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
		TextBuilder.AppendLine(FString("BaseInfo"));
		TextBuilder.AppendLine(FString("Id: " + FString::FromInt(static_cast<uint32>(EntityId.Value))));
		TextBuilder.AppendLine(FString("Name: " + EntityName.Value.ToString()));
		TextBuilder.AppendLine(FString(TEXT("CubeCoordinate: ") + Position.Value.ToString()));
		TextBuilder.AppendLine(FString(" "));
		TextBuilder.AppendLine(FString("Resources in district"));
		auto Operation = [&TextBuilder, &World] (const auto& Element)
		{
			if (Element.Key == entt::null)
				return;
			const auto [ResourceId, ResourceName] = Commands::GetGroupComponents
                <Groups::BasicType>
                (World, Element.Key);
			TextBuilder.AppendLine(FString(ResourceName.Value.ToString() + ": " + FString::FromInt(Element.Value)));
		};
		std::for_each(DistrictResources.Value.begin(), DistrictResources.Value.end(), Operation);
		
		return TextBuilder.ToText();
	}

	inline FText CityInfoGetter(const FVector& Location, entt::registry& World)
	{
		const auto Entity = Commands::GetDistrictId(Location, World);
		if (!Commands::IsValidGroups<Groups::City>(World, Entity)) return FText();
		const auto& [CityBuildings, ResourcesStorageInCity] = Commands::GetGroupComponents
            <Groups::City>
            (World, Entity);

		FTextBuilder TextBuilder;
		auto Operation = [&TextBuilder, &World] (const auto& Element)
		{
			if (Element.Key == entt::null)
				return;
			const auto [Id, Name] = Commands::GetGroupComponents
                <Groups::BasicType>
                (World, Element.Key);
			TextBuilder.AppendLine(FString(Name.Value.ToString()));
			TextBuilder.AppendLine(FString("Id: " + FString::FromInt(static_cast<int32>(Element.Key))));
			TextBuilder.AppendLine(FString("Count: " + FString::FromInt(Element.Value)));
		};
		
		TextBuilder.AppendLine(FString("Buildings in city"));
		std::for_each(CityBuildings.Value.begin(), CityBuildings.Value.end(), Operation);
		TextBuilder.AppendLine(FString(" "));
		TextBuilder.AppendLine(FString("Resource in city"));	
		std::for_each(ResourcesStorageInCity.Value.begin(), ResourcesStorageInCity.Value.end(), Operation);	
		
		return TextBuilder.ToText();
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
