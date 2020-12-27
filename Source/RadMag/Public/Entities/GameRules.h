// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Containers/StaticArray.h"

/** */
struct FMapRules
{
	/** */
	uint32 ChunkCountOX;
	
	/** */
	uint32 ChunkCountOY;
	
	/** */
	uint32 ChunkSize;
};

/** */
struct FRenderRules
{
	/** */
	float OuterToInner;
	
	/** */
	float OuterRadius;
	
	/** */
	TStaticArray<FVector, 7> Corners;
};

/** */
struct FGameRules
{	
	/** */
	FMapRules MapRules;

	/** */
	FRenderRules RenderRules;
};
