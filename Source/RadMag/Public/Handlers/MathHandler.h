// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Handler.h"
#include "MathHandler.generated.h"

/**
 * 
 */
UCLASS()
class RADMAG_API UMathHandler final : public UHandler
{
	GENERATED_BODY()

public:

	static FIntVector ConvertToCubeCoordinate(const FIntVector& OffsetCoordinate);

	static FIntVector ConvertToOffsetCoordinate(const FIntVector& CubeCoordinate);

	static FVector ConvertToRealCoordinate(const FIntVector& OffsetCoordinate, UGameData* GameData);

	static float GetInnerDiameter(UGameData* GameData);

	static FIntVector ConvertToCubeCoordinate(const FVector& RealCoordinate, UGameData* GameData);

	static uint32 ConvertToChunkIndex(const FIntVector OffsetCoordinate, UGameData* GameData);
};
