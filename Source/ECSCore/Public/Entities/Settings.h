// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Containers/StaticArray.h"

/** */
struct FWorldSettings
{
	uint32 Length = 1;
	uint32 Height = 1;
	uint32 CommonDivisor = 1;
};

/** */
struct FHexMetrics
{
	float OuterToInner;
	float OuterRadius;
	TStaticArray<FVector, 7> Corners;
	uint32 ChunkSizeOX;
	uint32 ChunkSizeOY;
	uint32 ChunkCountOX;
	uint32 ChunkCountOY;
};