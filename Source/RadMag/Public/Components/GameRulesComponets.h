// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Containers/StaticArray.h"

struct FMapRules
{
	uint32 ChunkCountOX;
	uint32 ChunkCountOY;
	uint32 ChunkSize;
};

struct FRenderRules
{
	float OuterToInner;
	float OuterRadius;
	TStaticArray<FVector, 7> Corners;
};

struct FDistrictRules
{
	static constexpr uint32 MaxBuildings = 32;
	static constexpr uint32 MaxResources = 32;
	static constexpr uint32 MaxResourcesInDistrict = 8;
	static constexpr uint32 MaxBuildingsInDistrict = 8;
	static constexpr uint32 MaxFactoryInput = 8;
	static constexpr uint32 MaxFactoryOutput = 8;
	static constexpr uint32 MaxMineOutput = 8;
};
