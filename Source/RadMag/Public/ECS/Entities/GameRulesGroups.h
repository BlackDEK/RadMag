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

    using CMapRules = entt::type_list<
        const entt::tag<entt::hashed_string("MapRules")>,
        const FChunkCountOX,
        const FChunkCountOY,
        const FChunkSize
    >::type;

    using RenderRules = entt::type_list<
        entt::tag<entt::hashed_string("RenderRules")>,
        FOuterToInner,
        FOuterRadius,
        FCorners
    >::type;

    using CRenderRules = entt::type_list<
        const entt::tag<entt::hashed_string("RenderRules")>,
        const FOuterToInner,
        const FOuterRadius,
        const FCorners
    >::type;

    using DistrictRules = entt::type_list<
        entt::tag<entt::hashed_string("DistrictRules")>,
        FMaxBuildingsInWorld,
        FMaxResourcesInWorld,
        FMaxResourcesInDistrict,
        FMaxBuildingsInDistrict,
        FMaxFactoryInput,
        FMaxFactoryOutput
    >::type;

    using CDistrictRules = entt::type_list<
        const entt::tag<entt::hashed_string("DistrictRules")>,
        const FMaxBuildingsInWorld,
        const FMaxResourcesInWorld,
        const FMaxResourcesInDistrict,
        const FMaxBuildingsInDistrict,
        const FMaxFactoryInput,
        const FMaxFactoryOutput
    >::type;
}
