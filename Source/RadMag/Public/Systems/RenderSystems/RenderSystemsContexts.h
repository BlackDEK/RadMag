// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "RenderSystemsContexts.generated.h"

/**
* 
*/
USTRUCT(BlueprintType)
struct FChunkCache
{
	GENERATED_BODY()

	/** */
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector> Vertices;
	
	/** */
	UPROPERTY(BlueprintReadWrite)
	TArray<int32> Triangles;
	
	/** */
	UPROPERTY(BlueprintReadWrite)
	TArray<FLinearColor> VertexColors;
	
};