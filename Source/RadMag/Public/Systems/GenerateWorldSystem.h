// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Commands/ExternalCommands/ExternalCommandsContexts.h"
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
	static USystem* MakeSystemGenerateWorld(const FCreateGameRulesContext& GenerateWorldContext, UObject* Outer);
	
};
