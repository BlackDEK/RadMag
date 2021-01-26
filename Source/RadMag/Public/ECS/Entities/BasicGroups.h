// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "core/type_traits.hpp"
#include "entt.hpp"
#include "ECS/Components/BasicComponents.h"
#include "ECS/Components/GameRulesComponets.h"
#include "ECS/Components/WorldInfoComponents.h"
#include "ECS/Components/DistrictComponents.h"

namespace Groups
{
	using BasicType = entt::type_list<
        entt::tag<entt::hashed_string("BasicType")>,
        FEntityId,
        FEntityName
    >::type;
	
	using WorldInfo = entt::type_list<
		entt::tag<entt::hashed_string("WorldInfo")>,
		FCurrentTurn
	>::type;	
}
