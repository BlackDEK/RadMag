// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/BasicData.h"
#include "Components/EnttList.h"

#include "District.generated.h"

/** */
USTRUCT()
struct FDistrict
{
    GENERATED_BODY()

public:
	
    /** */
    UPROPERTY()
    FBasicData BasicData;
    	
    /** */
    UPROPERTY()
    FIntVector CubeCoordinate;

    /** */
    UPROPERTY()
    uint32 Biome;

    /** */
    UPROPERTY()
    uint32 Anomaly;

    /** */
    UPROPERTY()
    FEnttList Slots;
};