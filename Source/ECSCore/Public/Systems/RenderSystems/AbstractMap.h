﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AbstractMap.generated.h"

UINTERFACE(BlueprintType)
class ECSCORE_API UAbstractMap : public UInterface
{
    GENERATED_BODY()
};

class ECSCORE_API IAbstractMap
{
    GENERATED_BODY()
    
public:
    
    UFUNCTION(BlueprintNativeEvent, Category = "|-- Info")
    void OnGetChunkCounter(int32 ChunkCounter);
};
