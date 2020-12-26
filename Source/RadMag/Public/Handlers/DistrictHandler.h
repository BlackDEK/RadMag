// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Handler.h"
#include "entt.hpp"
#include "Entities/District.h"

#include "DistrictHandler.generated.h"

/**
 * 
 */
UCLASS()
class RADMAG_API UDistrictHandler final : public UHandler
{
	GENERATED_BODY()

public:
	
	static void CreateDistricts(UGameData* GameData);

	static entt::entity GetDistrictId(const FVector& Location, UGameData* GameData);
	
	static FDistrict GetDistrict(const entt::entity& DistrictId, UGameData* GameData);
	
	static void GetAllDistrict(TArray<FDistrict>& Districts, UGameData* GameData);
};
