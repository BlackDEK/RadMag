// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Containers/StaticArray.h"

struct FChunkCountOX
{
	uint32 Value;	
};

struct FChunkCountOY
{
	uint32 Value;	
};

struct FChunkSize
{
	uint32 Value;	
};

struct FOuterToInner
{
	float Value;
};

struct FOuterRadius
{
	float Value;
};

struct FCorners
{
	TStaticArray<FVector, 7> Value;
};

struct FMaxBuildings
{
	static constexpr uint32 Value = 32;
};

struct FMaxResourcesInWorld
{
	static constexpr uint32 Value = 32;
};

struct FMaxResourcesInDistrict
{
	static constexpr uint32 Value = 8;
};

struct FMaxBuildingsInDistrict
{
	static constexpr uint32 Value = 8;
};

struct FMaxFactoryInput
{
	static constexpr uint32 Value = 8;
};

struct FMaxFactoryOutput
{
	static constexpr uint32 Value = 8;
};
