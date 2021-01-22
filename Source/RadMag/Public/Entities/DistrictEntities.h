// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "core/type_traits.hpp"
#include "Components/BasicComponents.h"
#include "Components/DistrictComponents.h"
#include "entt.hpp"

namespace DistrictEntities
{
	using District = entt::type_list<
		entt::tag<entt::hashed_string("District")>,
		FBasicData,
		FDistrictData
	>::type;

	using DistrictWithCity = entt::type_list<
		entt::tag<entt::hashed_string("DistrictWithCity")>,
		FBasicData,
		FDistrictData,
		FCityData
	>::type;

	using Resource = entt::type_list<
		entt::tag<entt::hashed_string("Resource")>,
		FBasicData
	>::type;

	using Factory = entt::type_list<
		entt::tag<entt::hashed_string("Factory")>,
		FBasicData,
		FFactoryData
	>::type;

	using Storage = entt::type_list<
        entt::tag<entt::hashed_string("Storage")>,
        FBasicData,
        FStorageData
    >::type;

	using Mine = entt::type_list<
        entt::tag<entt::hashed_string("Mine")>,
        FBasicData,
        FMineData
    >::type;
};
