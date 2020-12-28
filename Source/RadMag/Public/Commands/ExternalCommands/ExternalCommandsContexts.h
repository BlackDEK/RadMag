// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ExternalCommandsContexts.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FCreateGameRulesContext
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