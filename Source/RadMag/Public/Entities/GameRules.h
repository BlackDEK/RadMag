// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Containers/StaticArray.h"
#include "GameRules.generated.h"

/** */
USTRUCT()
struct FMapRules
{
	GENERATED_BODY()

	/** */
	UPROPERTY()
	uint32 ChunkCountOX;
	
	/** */
	UPROPERTY()
	uint32 ChunkCountOY;
	
	/** */
	UPROPERTY()
	uint32 ChunkSize;
};

/** */
USTRUCT()
struct FRenderRules
{
	GENERATED_BODY()
	
	/** */
	UPROPERTY()
	float OuterToInner;
	
	/** */
	UPROPERTY()
	float OuterRadius;
	
	/** */
	TStaticArray<FVector, 7> Corners;
};

/** */
USTRUCT()
struct FGameRules
{
	GENERATED_BODY()

public:
	
	/** */
	UPROPERTY()
	FMapRules MapRules;

	/** */
	UPROPERTY(Transient)
	FRenderRules RenderRules;
};
