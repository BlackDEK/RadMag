// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Commands/InternalCommands/RenderCommandsContexts.h"
#include "UObject/Interface.h"
#include "AbstractMap.generated.h"

UINTERFACE(BlueprintType)
class RADMAG_API UAbstractMap : public UInterface
{
    GENERATED_BODY()
};

class RADMAG_API IAbstractMap
{
    GENERATED_BODY()
    
public:

    UFUNCTION(BlueprintNativeEvent, Category = "|-- Info")
    void OnGetChunkCache(UPARAM(ref) TArray<FChunkCache>& Cache);
};
