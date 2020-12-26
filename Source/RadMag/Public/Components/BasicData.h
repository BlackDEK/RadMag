// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "entt.hpp"
#include "BasicData.generated.h"

/** */
USTRUCT()
struct FBasicData
{
    GENERATED_BODY()
    
    /** */
    UPROPERTY()
    uint32 Id;
    
    /** */
    UPROPERTY()
    FName Name;
};