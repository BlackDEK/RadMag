// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BasicCommands.h"
#include "HexMetricsCommands.h"
#include "ECS/Entities/BasicGroups.h"
#include "ECS/Entities/DistrictGroups.h"
#include "ECS/Entities/GameRulesGroups.h"

namespace Commands
{
	inline void CreateGameRules(const FCreateGameRulesContext& Context, entt::registry& World)
	{
		check(!Commands::IsValidGroups<Groups::MapRules>(World));
		check(!Commands::IsValidGroups<Groups::RenderRules>(World));
		check(!Commands::IsValidGroups<Groups::DistrictRules>(World));


		const auto Entity = World.create();
		Commands::AddGroups
			<Groups::BasicType, Groups::MapRules, Groups::RenderRules, Groups::DistrictRules>
			(World, Entity);

		auto [EntityId, EntityName, ChunkCountOX, ChunkCountOY, ChunkSize, OuterToInner, OuterRadius, Corners] =
			Commands::GetGroupComponents<Groups::BasicType, Groups::MapRules, Groups::RenderRules>(World);

		EntityId.Value = Entity;
		EntityName.Value = FName(TEXT("GameRules"));

		ChunkCountOX.Value = Context.ChunkCountOX;
		ChunkCountOY.Value = Context.ChunkCountOY;
		ChunkSize.Value = Context.ChunkSize;

		const auto LocalOuterToInner = 0.866025404f;
		const auto LocalOuterRadius = 10.f;
		const auto InnerRadius = LocalOuterRadius * LocalOuterToInner;
		TStaticArray<FVector, 7> LocalCorners;
		LocalCorners[0] = FVector(0.f, LocalOuterRadius, 0.f);
		LocalCorners[1] = FVector(InnerRadius, 0.5f * LocalOuterRadius, 0.f);
		LocalCorners[2] = FVector(InnerRadius, -0.5f * LocalOuterRadius, 0.f);
		LocalCorners[3] = FVector(0.f, -LocalOuterRadius, 0.f);
		LocalCorners[4] = FVector(-InnerRadius, -0.5f * LocalOuterRadius, 0.f);
		LocalCorners[5] = FVector(-InnerRadius, 0.5f * LocalOuterRadius, 0.f);
		LocalCorners[6] = FVector(0.f, LocalOuterRadius, 0.f);

		OuterToInner.Value = LocalOuterToInner;
		OuterRadius.Value = LocalOuterRadius;
		Corners.Value = LocalCorners;
	}

	inline void CreateDistricts(entt::registry& World)
	{
		check(Commands::IsValidGroups<Groups::MapRules>(World));
		check(!Commands::IsValidGroups<Groups::District>(World));

		const auto [ChunkCountOX, ChunkCountOY, ChunkSize] =
			Commands::GetGroupComponents<Groups::MapRules>(World);

		for (uint32 Y = 0; Y < ChunkCountOY.Value * ChunkSize.Value; Y++)
			for (uint32 X = 0; X < ChunkCountOX.Value * ChunkSize.Value; X++)
			{
				const auto Entity = World.create();
				Commands::AddGroups<Groups::BasicType, Groups::District>(World, Entity);

				const auto [EntityId, EntityName, Position, DistrictResources] =
					Commands::GetGroupComponents<Groups::BasicType, Groups::District>(World, Entity);

				EntityId.Value = Entity;
				EntityName.Value = FName("District_" + FString::FromInt(X) + "_" + FString::FromInt(Y));
				Position.Value = ConvertToCubeCoordinate(FIntVector(X, Y, 0));
			}
	}

	inline void CreateWorldInfo(entt::registry& World)
	{
		check(!Commands::IsValidGroups<Groups::WorldInfo>(World));

		const auto Entity = World.create();
		Commands::AddGroups<Groups::BasicType, Groups::WorldInfo>(World, Entity);

		const auto [EntityId, EntityName, CurrentTurn] =
			Commands::GetGroupComponents<Groups::BasicType, Groups::WorldInfo>(World, Entity);

		EntityId.Value = Entity;
		EntityName.Value = FName(TEXT("WorldInfo"));
		CurrentTurn.Value = 0;
	}
}
