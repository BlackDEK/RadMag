// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "entt.hpp"

struct FEntityId
{
    entt::entity Value;
};

struct FEntityName
{
    FName Value;
};

struct FPosition
{
    FIntVector Value;
};