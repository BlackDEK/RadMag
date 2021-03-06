// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "core/type_traits.hpp"
#include "entt.hpp"
#include "ECS/Components/BasicComponents.h"
#include "ECS/Components/DistrictComponents.h"

namespace Groups
{
    using District = entt::type_list<
        entt::tag<entt::hashed_string("District")>,
        FPosition,
        FDistrictResources
    >::type;

    using City = entt::type_list<
        entt::tag<entt::hashed_string("City")>,
        FCityBuildings,
        FResourcesStorageInCity
    >::type;

    using Resource = entt::type_list<
        entt::tag<entt::hashed_string("Resource")>
    >::type;

    using Building = entt::type_list<
        entt::tag<entt::hashed_string("Building")>
    >::type;

    using Factory = entt::type_list<
        entt::tag<entt::hashed_string("Factory")>,
        FFactoryInput,
        FFactoryOutput
    >::type;

    using Mine = entt::type_list<
        entt::tag<entt::hashed_string("Mine")>,
        FFactoryInput,
        FFactoryOutput
    >::type;

}
