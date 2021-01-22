// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "entity/registry.hpp"
#include "Interfaces/AbstractMap.h"
#include "UObject/NoExportTypes.h"

#include "GenerateChunkCache.generated.h"

/**
* 
*/
UCLASS(BlueprintType)
class RADMAG_API UGenerateChunkCache final : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static USystem* MakeSystemGenerateChunksCache(TScriptInterface<IAbstractMap> Map, UObject* Outer);
};
