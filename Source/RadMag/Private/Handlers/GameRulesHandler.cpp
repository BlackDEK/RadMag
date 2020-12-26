// Fill out your copyright notice in the Description page of Project Settings.

#include "Handlers/GameRulesHandler.h"
#include "Entities/GameRules.h"
#include "GameData.h"

void UGameRulesHandler::CreateGameRules(const FGenerateWorldContext& GenerateWorldContext, UGameData* GameData)
{
	auto& World = GameData->World;
	check(!World.valid(World.view<FGameRules>().front()));
	CreateEntity<FGameRules>(1, GameData);
	const auto GameRulesId = World.view<FGameRules>().front();
	auto& GameRules = World.get<FGameRules>(GameRulesId);
	
	GameRules.MapRules.ChunkCountOX = GenerateWorldContext.ChunkCountOX;
	GameRules.MapRules.ChunkCountOY = GenerateWorldContext.ChunkCountOY;
	GameRules.MapRules.ChunkSize = GenerateWorldContext.ChunkSize;

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

FGameRules UGameRulesHandler::GetGameRules(UGameData* GameData)
{
	auto& World = GameData->World;
	const auto GameRulesId = World.view<FGameRules>().front();
	return World.get<FGameRules>(GameRulesId);
}
