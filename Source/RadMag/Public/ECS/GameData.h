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
class RADMAG_API UGameData final : public UObject
{
    GENERATED_BODY()

public:
    entt::registry World;
};
