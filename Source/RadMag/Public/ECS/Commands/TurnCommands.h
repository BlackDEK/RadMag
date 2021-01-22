// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BasicCommands.h"
#include "ECS/GameData.h"
#include "ECS/Entities/Entities.h"

namespace TurnCommands
{
	inline void IncrementingTurn(UGameData* GameData)
	{
		decltype(auto) WorldInfo = BasicCommands::Get<true, Entities::WorldInfo, FWorldInfo>(GameData);
		++WorldInfo.CurrentTurn;
	}
}
