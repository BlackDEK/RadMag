// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorSystemsContexts.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FGenerateWorldContext
{
	GENERATED_BODY()

	/** */
	UPROPERTY(BlueprintReadWrite)
	int32 ChunkCountOX;
	
	/** */
	UPROPERTY(BlueprintReadWrite)
	int32 ChunkCountOY;
	
	/** */
	UPROPERTY(BlueprintReadWrite)
	int32 ChunkSize;
	
};