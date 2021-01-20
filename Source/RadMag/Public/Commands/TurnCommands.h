// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameData.h"
#include "Entities/WorldInfo.h"

namespace TurnCommands
{
	inline void IncrementingTurn(UGameData* GameData)
	{
		auto& World = GameData->World;
		const auto Id = World.view<FWorldInfo>().front();
		check(Id != entt::null);
		auto& WorldInfo = World.get<FWorldInfo>(Id);
		++WorldInfo.CurrentTurn;
	}
}
