// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "entt.hpp"
#include "Containers/StaticArray.h"
#include "GameRulesComponets.h"

struct FDistrictResources
{ 
    TStaticArray<TTuple<entt::entity, int32>, FMaxResourcesInDistrict::Value> Value;

    FDistrictResources()
    {
        for(decltype(auto) Element : Value)
            Element = MakeTuple(entt::null, 0);
    }
};

struct FCityBuildings
{    	
    TStaticArray<TTuple<entt::entity, int32>, FMaxBuildingsInDistrict::Value> Value;

    FCityBuildings()
    {
        for(decltype(auto) Element : Value)
            Element = MakeTuple(entt::null, 0);
    }
};

struct FFactoryInput
{    	
    TStaticArray<TTuple<entt::entity, int32>, FMaxFactoryInput::Value> Value;

    FFactoryInput()
    {
        for(decltype(auto) Element : Value)
            Element = MakeTuple(entt::null, 0);
    }
};

struct FFactoryOutput
{    	
    TStaticArray<TTuple<entt::entity, int32>, FMaxFactoryOutput::Value> Value;

    FFactoryOutput()
    {
        for(decltype(auto) Element : Value)
            Element = MakeTuple(entt::null, 0);
    }
};

struct FResourcesStorageInCity
{    	
    TStaticArray<TTuple<entt::entity, int32>, FMaxResourcesInWorld::Value> Value;

    FResourcesStorageInCity()
    {
        for(decltype(auto) Element : Value)
            Element = MakeTuple(entt::null, 0);
    }
};