// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "core/type_traits.hpp"
#include "entt.hpp"
#include "ECS/Components/BasicComponents.h"
#include "ECS/Components/GameRulesComponets.h"

namespace Groups
{
    using MapRules = entt::type_list<
        entt::tag<entt::hashed_string("MapRules")>,
        FChunkCountOX,
        FChunkCountOY,
        FChunkSize
    >::type;

    using RenderRules = entt::type_list<
        entt::tag<entt::hashed_string("RenderRules")>,
        FOuterToInner,
        FOuterRadius,
        FCorners
    >::type;

    using DistrictRules = entt::type_list<
        entt::tag<entt::hashed_string("DistrictRules")>,
        FMaxBuildings,
        FMaxResourcesInWorld,
        FMaxResourcesInDistrict,
        FMaxBuildingsInDistrict,
        FMaxFactoryInput,
        FMaxFactoryOutput
    >::type;
}
