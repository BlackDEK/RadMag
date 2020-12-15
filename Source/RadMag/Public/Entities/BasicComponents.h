// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "entt.hpp"
#include "Containers/StaticArray.h"

/** */
struct FBasicData
{
    entt::entity Id;
    FName Name;
};

/** */
struct FHeadOfArray
{
    SIZE_T Children{0};
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