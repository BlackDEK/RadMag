// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entities/Settings.h"

/** */
namespace CoordinateUtilities
{
	FORCEINLINE static FIntVector ConvertToCubeCoordinate(const FIntVector& OffsetCoordinate)
	{
		const auto X = static_cast<int32>(OffsetCoordinate.X - (OffsetCoordinate.Y - (OffsetCoordinate.Y & 1)) / 2);
		const auto Z = static_cast<int32>(OffsetCoordinate.Y);
		const auto Y = static_cast<int32>(-X - Z);
		return FIntVector(X, Y, Z);
	}

	FORCEINLINE static FIntVector ConvertToOffsetCoordinate(const FIntVector CubeCoordinate)
	{
		const auto Col = static_cast<int32>(CubeCoordinate.X + (CubeCoordinate.Z - (CubeCoordinate.Z&1)) / 2);
		const auto Row = static_cast<int32>(CubeCoordinate.Z);
		return FIntVector(Col, Row, 0);
	}

	FORCEINLINE static FVector ConvertToRealCoordinate(const FIntVector& OffsetCoordinate, const FHexMetrics& HexMetrics)
	{
		const auto X = static_cast<float>((OffsetCoordinate.X + OffsetCoordinate.Y * 0.5f - OffsetCoordinate.Y / 2) *
                (2.f * HexMetrics.OuterToInner * HexMetrics.OuterRadius));
		const auto Y = static_cast<float>(OffsetCoordinate.Y * (HexMetrics.OuterRadius * 1.5f));
		const auto Z = 0.f;
		return FVector(X, Y, Z);
	}

	FORCEINLINE static float GetInnerDiameter(const FHexMetrics& HexMetrics)
	{
		return 2.f * HexMetrics.OuterRadius * HexMetrics.OuterToInner;
	}

	FORCEINLINE static FIntVector ConvertToCubeCoordinate(const FVector& RealCoordinate, const FHexMetrics& HexMetrics)
	{
		float X = RealCoordinate.X / GetInnerDiameter(HexMetrics);
		float Y = -X;
		const float Offset = RealCoordinate.Y / (HexMetrics.OuterRadius * 3.0f);
		X -= Offset;
		Y -= Offset;
		int32 iX = FMath::RoundToInt(X);
		int32 iY = FMath::RoundToInt(Y);
		int32 iZ = FMath::RoundToInt(-X - Y);
		if (iX + iY + iZ != 0)
		{
			const float dX = FMath::RoundToInt(X - iX);
			const float dY = FMath::RoundToInt(Y - iY);
			const float dZ = FMath::RoundToInt(-X - Y - iZ);
			if (dX > dY && dX > dZ)
				iX = -iY - iZ;
			else if (dZ > dY)
				iZ = -iX - iY;
		}
		iY = -iX - iZ;

		return FIntVector(iX, iY, iZ);
	}

	FORCEINLINE static int32 ConvertToChunkIndex(const FIntVector OffsetCoordinate, const FHexMetrics& HexMetrics)
	{
		const int32 ChunkX = OffsetCoordinate.X / HexMetrics.ChunkSizeOX;
		const int32 ChunkY = OffsetCoordinate.Y / HexMetrics.ChunkSizeOY;
		return static_cast<int32>(ChunkX + ChunkY * HexMetrics.ChunkCountOX);
	}
}