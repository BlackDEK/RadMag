// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "core/type_traits.hpp"
#include "entt.hpp"
#include "Components/BasicComponents.h"
#include "Components/GameRulesComponets.h"
#include "Components/WorldInfoComponents.h"

namespace BasicEntities
{
	using WorldInfo = entt::type_list<
		entt::tag<entt::hashed_string("WorldInfo")>,
		FBasicData,
		FWorldInfo
	>::type;

	using GameRules = entt::type_list<
		entt::tag<entt::hashed_string("GameRules")>,
		FBasicData,
		FMapRules,
		FRenderRules,
		FDistrictRules
	>::type;
}
