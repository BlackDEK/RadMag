// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "BasicInternalCommands.h"
#include "GameData.h"
#include "InternalCommandsContexts.h"
#include "Entities/GameRules.h"

namespace BasicExternalCommands
{
	template <typename T>
    inline void CreateGameRules(const FCreateGameRulesContext& Context, UGameData* GameData)
	{
		auto& World = GameData->World;
		check(!World.valid(World.view<FGameRules>().front()));
		BasicInternalCommands::CreateEntity<FGameRules>(1, GameData);
		const auto Id = World.view<FGameRules>().front();
		auto& GameRules = World.get<FGameRules>(Id);
	
		GameRules.MapRules.ChunkCountOX = Context.ChunkCountOX;
		GameRules.MapRules.ChunkCountOY = Context.ChunkCountOY;
		GameRules.MapRules.ChunkSize = Context.ChunkSize;

		const auto OuterToInner = 0.866025404f;
		const auto OuterRadius = 10.f;
		const auto InnerRadius = OuterRadius * OuterToInner;

		GameRules.RenderRules.OuterToInner = OuterToInner;
		GameRules.RenderRules.OuterRadius = OuterRadius;

		GameRules.RenderRules.Corners[0] = FVector(0.f, OuterRadius, 0.f);
		GameRules.RenderRules.Corners[1] = FVector(InnerRadius, 0.5f * OuterRadius, 0.f);
		GameRules.RenderRules.Corners[2] = FVector(InnerRadius, -0.5f * OuterRadius, 0.f);
		GameRules.RenderRules.Corners[3] = FVector(0.f, -OuterRadius, 0.f);
		GameRules.RenderRules.Corners[4] = FVector(-InnerRadius, -0.5f * OuterRadius, 0.f);
		GameRules.RenderRules.Corners[5] = FVector(-InnerRadius, 0.5f * OuterRadius, 0.f);
		GameRules.RenderRules.Corners[6] = FVector(0.f, OuterRadius, 0.f);
	}
}
