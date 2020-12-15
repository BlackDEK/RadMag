// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AbstractChunk.h"
#include "AbstractMap.h"
#include "System.h"
#include "Entities/Settings.h"
#include "entity/registry.hpp"
#include "UObject/NoExportTypes.h"

#include "RenderSystems.generated.h"

/**
* 
*/
UCLASS(BlueprintType)
class RADMAG_API URenderSystems final : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static USystem* MakeSystemPrepareRenderData(UObject* Outer);

private:

	static LCommand MakeSystemSetRenderSettings();

public:

	UFUNCTION(BlueprintCallable)
	static USystem* MakeSystemGenerateChunkCache(TScriptInterface<IAbstractChunk> Chunk, UObject* Outer);

	UFUNCTION(BlueprintCallable)
	static USystem* MakeSystemChunkCounter(TScriptInterface<IAbstractMap> Map, UObject* Outer);
};
