﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "BasicInternalCommands.h"
#include "GameData.h"
#include "Entities/GameRules.h"

namespace HexMetricsCommands
{
	inline FIntVector ConvertToCubeCoordinate(const FIntVector& OffsetCoordinate)
	{
		const auto X = static_cast<int32>(OffsetCoordinate.X - (OffsetCoordinate.Y - (OffsetCoordinate.Y & 1)) / 2);
		const auto Z = static_cast<int32>(OffsetCoordinate.Y);
		const auto Y = static_cast<int32>(-X - Z);
		return FIntVector(X, Y, Z);
	}

	inline FIntVector ConvertToOffsetCoordinate(const FIntVector& CubeCoordinate)
	{
		const auto Col = static_cast<int32>(CubeCoordinate.X + (CubeCoordinate.Z - (CubeCoordinate.Z & 1)) / 2);
		const auto Row = static_cast<int32>(CubeCoordinate.Z);
		return FIntVector(Col, Row, 0);
	}	

	inline float GetInnerDiameter(UGameData* GameData)
	{
		auto Pair = BasicInternalCommands::Get<FGameRules>(GameData);
		check(Pair.Key());
		const auto RenderRules = Pair.Value.RenderRules;
		return 2.f * RenderRules.OuterRadius * RenderRules.OuterToInner;
	}

	inline FVector ConvertToRealCoordinate(const FIntVector& OffsetCoordinate, UGameData* GameData)
	{
		auto Pair = BasicInternalCommands::Get<FGameRules>(GameData);
		check(Pair.Key());
		const auto RenderRules = Pair.Value.RenderRules;
		const auto X = static_cast<float>((OffsetCoordinate.X + OffsetCoordinate.Y * 0.5f - OffsetCoordinate.Y / 2) *
			GetInnerDiameter(GameData));
		const auto Y = static_cast<float>(OffsetCoordinate.Y * (RenderRules.OuterRadius * 1.5f));
		const auto Z = 0.f;
		return FVector(X, Y, Z);
	}

	inline FIntVector ConvertToCubeCoordinate(const FVector& RealCoordinate, UGameData* GameData)
	{
		auto Pair = BasicInternalCommands::Get<FGameRules>(GameData);
		check(Pair.Key());
		const auto RenderRules = Pair.Value.RenderRules;
		float X = RealCoordinate.X / GetInnerDiameter(GameData);
		float Y = -X;
		const float Offset = RealCoordinate.Y / (RenderRules.OuterRadius * 3.0f);
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

	inline uint32 ConvertToChunkIndex(const FIntVector OffsetCoordinate, UGameData* GameData)
	{
		auto Pair = BasicInternalCommands::Get<FGameRules>(GameData);
		check(Pair.Key());
		const auto GameRules = Pair.Value;
		const int32 ChunkX = OffsetCoordinate.X / GameRules.MapRules.ChunkSize;
		const int32 ChunkY = OffsetCoordinate.Y / GameRules.MapRules.ChunkSize;
		return static_cast<uint32>(ChunkX + ChunkY * GameRules.MapRules.ChunkCountOX);
	}
}