// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BasicInternalCommands.h"
#include "GameData.h"
#include "Entities/Entities.h"

namespace TurnCommands
{
	inline void IncrementingTurn(UGameData* GameData)
	{
		decltype(auto) WorldInfo = BasicInternalCommands::Get<true, Entities::WorldInfo, FWorldInfo>(GameData);
		++WorldInfo.CurrentTurn;
	}
}
