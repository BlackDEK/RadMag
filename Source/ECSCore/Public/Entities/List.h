// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Containers/StaticArray.h"
#include "entity/registry.hpp"

/** */
struct FList
{
	int32 Children{0};
	entt::entity First{entt::null};
	entt::entity End{entt::null};
};

/** */
struct FNode
{
	entt::entity Parent{entt::null};
	entt::entity Prev{entt::null};
	entt::entity Next{entt::null};
};