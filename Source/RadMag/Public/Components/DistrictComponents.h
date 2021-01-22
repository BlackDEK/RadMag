// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "entt.hpp"
#include "Containers/StaticArray.h"
#include "GameRulesComponets.h"

struct FDistrictData
{    	
    FIntVector CubeCoordinate;
    TStaticArray<TPair<entt::entity, int32>, FDistrictRules::MaxResourcesInDistrict> Resources;    
};

struct FCityData
{    	
    TStaticArray<TPair<entt::entity, int32>, FDistrictRules::MaxBuildingsInDistrict> Buildings;    
};

struct FFactoryData
{    	
    TStaticArray<TPair<entt::entity, int32>, FDistrictRules::MaxFactoryInput> Input;
    TStaticArray<TPair<entt::entity, int32>, FDistrictRules::MaxFactoryOutput> Output;     
};

struct FMineData
{    	
    TStaticArray<TPair<entt::entity, int32>, FDistrictRules::MaxMineOutput> Output;    
};

struct FStorageData
{    	
    TStaticArray<TPair<entt::entity, int32>, FDistrictRules::MaxResources> Storage;    
};