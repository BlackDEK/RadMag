// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Handler.h"
#include "Entities/GameRules.h"
#include "Systems/EditorSystems/EditorSystemsContexts.h"
#include "GameRulesHandler.generated.h"

class UGameData;
/**
 * 
 */
UCLASS()
class RADMAG_API UGameRulesHandler final : public UHandler
{
	GENERATED_BODY()

public:

	static void CreateGameRules(const FGenerateWorldContext& GenerateWorldContext, UGameData* GameData);

	static FGameRules GetGameRules(UGameData* GameData);
};

