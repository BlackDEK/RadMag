// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractMap.h"
#include "Entities/GameRules.h"
#include "entity/registry.hpp"
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
	static USystem* MakeSystemGenerateChunkCache(TScriptInterface<IAbstractMap> Map, UObject* Outer);
};
