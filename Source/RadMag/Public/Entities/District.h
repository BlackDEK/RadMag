// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "BasicComponents.h"
#include "Entities/List.h"

/** */
struct FDistrictData
{
    FBasicData BasicData;
    FIntVector CubeCoordinate;
};

/** */
struct FBuilding
{
    FList HeadOfArray;
};