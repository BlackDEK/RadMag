// Fill out your copyright notice in the Description page of Project Settings.


#include "Handlers/DistrictHandler.h"
#include "GameData.h"
#include "Entities/District.h"
#include "Entities/GameRules.h"
#include "Handlers/GameRulesHandler.h"
#include "Handlers/MathHandler.h"

void UDistrictHandler::CreateDistricts(UGameData* GameData)
{
	auto& World = GameData->World;
	const auto MapRules = UGameRulesHandler::GetGameRules(GameData).MapRules;
	for (uint32 Y = 0; Y < MapRules.ChunkCountOY * MapRules.ChunkSize; Y++)
		for (uint32 X = 0; X < MapRules.ChunkCountOX * MapRules.ChunkSize; X++)
		{
			const auto DistrictId = World.create();
			auto& District = World.emplace<FDistrict>(DistrictId);
			District.BasicData.Id = static_cast<uint32>(DistrictId);
			District.BasicData.Name = FName("District_" + FString::FromInt(X) + "_" + FString::FromInt(Y));
			District.CubeCoordinate = UMathHandler::ConvertToCubeCoordinate(FIntVector(X, Y, 0));
		}
}

entt::entity UDistrictHandler::GetDistrictId(const FVector& Location, UGameData* GameData)
{
	auto& World = GameData->World;	
	const auto CubeCoordinate = UMathHandler::ConvertToCubeCoordinate(Location, GameData);
	const auto Districts = World.view<FDistrict>();
	for (auto& DistrictId : Districts)
	{
		if (World.get<FDistrict>(DistrictId).CubeCoordinate == CubeCoordinate)
			return DistrictId;
	}
	return entt::entity{entt::null};
}

FDistrict UDistrictHandler::GetDistrict(const entt::entity& DistrictId, UGameData* GameData)
{
	check(DistrictId != entt::null)

	auto& World = GameData->World;
	return World.get<FDistrict>(DistrictId);
}

void UDistrictHandler::GetAllDistrict(TArray<FDistrict>& Districts, UGameData* GameData)
{
	auto& World = GameData->World;
	const auto DistrictIds = World.view<FDistrict>();
	for (auto& DistrictId : DistrictIds)
	{
		Districts.Add(World.get<FDistrict>(DistrictId));
	}
}
