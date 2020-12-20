// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "entity/registry.hpp"
#include "UObject/NoExportTypes.h"
#include "GameData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ECSCORE_API UGameData final : public UObject
{
    GENERATED_BODY()

public:
	// Удалить это!
    entt::entity SettingsId{entt::null};
    entt::registry World;
};
