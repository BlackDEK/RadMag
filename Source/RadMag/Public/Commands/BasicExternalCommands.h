// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ExternalCommandsContexts.h"
#include "Commands/BasicInternalCommands.h"
#include "Entities/BasicEntities.h"

namespace BasicExternalCommands
{
	inline void CreateGameRules(const FCreateGameRulesContext& Context, UGameData* GameData)
	{
		auto GameRulesCreated = BasicInternalCommands::IsValidEntity
			<true, BasicEntities::GameRules>(GameData);
		check(!GameRulesCreated);
		
		const auto Entity = BasicInternalCommands::CreateEntity<BasicEntities::GameRules>(GameData);
		
		auto [MapRules, RenderRules] = BasicInternalCommands::Get
            <false, BasicEntities::GameRules, FMapRules, FRenderRules>(GameData, Entity);
		
		MapRules.ChunkCountOX = Context.ChunkCountOX;
		MapRules.ChunkCountOY = Context.ChunkCountOY;
		MapRules.ChunkSize = Context.ChunkSize;

		const auto OuterToInner = 0.866025404f;
		const auto OuterRadius = 10.f;
		const auto InnerRadius = OuterRadius * OuterToInner;
		
		RenderRules.OuterToInner = OuterToInner;
		RenderRules.OuterRadius = OuterRadius;

		RenderRules.Corners[0] = FVector(0.f, OuterRadius, 0.f);
		RenderRules.Corners[1] = FVector(InnerRadius, 0.5f * OuterRadius, 0.f);
		RenderRules.Corners[2] = FVector(InnerRadius, -0.5f * OuterRadius, 0.f);
		RenderRules.Corners[3] = FVector(0.f, -OuterRadius, 0.f);
		RenderRules.Corners[4] = FVector(-InnerRadius, -0.5f * OuterRadius, 0.f);
		RenderRules.Corners[5] = FVector(-InnerRadius, 0.5f * OuterRadius, 0.f);
		RenderRules.Corners[6] = FVector(0.f, OuterRadius, 0.f);
	}
}
