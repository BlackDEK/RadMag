// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "EditorSystemsContexts.h"
#include "Systems/System.h"
#include "UObject/NoExportTypes.h"
#include "GenerateWorldSystem.generated.h"

class USystem;

/**
 * 
 */
UCLASS(BlueprintType)
class RADMAG_API UGenerateWorldSystem final : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static USystem* MakeSystemGenerateWorld(const FGenerateWorldContext& GenerateWorldContext, UObject* Outer);

private:
	
	static TFunction<void(UGameData*)> MakeSystemSetSettings(const FGenerateWorldContext& GenerateWorldContext);
	static TFunction<void(UGameData*)> MakeSystemGenerateMap();
	
};
