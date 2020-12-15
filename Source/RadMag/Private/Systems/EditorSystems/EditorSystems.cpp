// Fill out your copyright notice in the Description page of Project Settings.

#include "Systems/EditorSystems/EditorSystems.h"
#include "GameData.h"
#include "Entities/BasicComponents.h"
#include "Entities/District.h"
#include "Entities/ResourceData.h"
#include "Entities/Settings.h"
#include "Systems/Utilities/CoordinateUtilities.h"

USystem* UEditorSystems::MakeSystemGenerateWorld(const int32& Length, const int32& Height, const int32& CommonDivisor,
                                                 UObject* Outer)
{
	const auto SetSetting = MakeSystemSetSettings(Length, Height, CommonDivisor);
	const auto GenerateResources = MakeSystemGenerateResources();
	const auto GenerateMap = MakeSystemGenerateMap();

	const LCommand LGenerateWorld = [SetSetting, GenerateResources, GenerateMap](UGameData* GameData)
	{
		SetSetting(GameData);
		GenerateResources(GameData);
		GenerateMap(GameData);
	};
	auto Command = NewObject<USystem>(Outer);
	Command->Init(LGenerateWorld);
	return Command;
}

LCommand UEditorSystems::MakeSystemSetSettings(const int32& Length, const int32& Height, const int32& CommonDivisor)
{
	const LCommand LSetSettings = [Length, Height, CommonDivisor](UGameData* GameData)
	{
		auto& World = GameData->World;
		check(!World.valid(GameData->SettingsId));
		const auto Settings = World.create();
		GameData->SettingsId = Settings;
		auto& WorldSettings = World.emplace<FWorldSettings>(Settings);
		WorldSettings.Length = Length * CommonDivisor;
		WorldSettings.Height = Height * CommonDivisor;
		WorldSettings.CommonDivisor = CommonDivisor;
	};
	return LSetSettings;
}

LCommand UEditorSystems::MakeSystemGenerateResources()
{
	const LCommand LGenerateResources = [](UGameData* GameData)
	{
		auto& World = GameData->World;
		auto List = {"Food", "Metal", "Wood"};
		for (auto Element : List)
		{
			const auto Resource = World.create();
			auto& ResourceData = World.emplace<FResourceData>(Resource);
			ResourceData.BasicData.Id = Resource;
			ResourceData.BasicData.Name = FName(Element);
		}
	};

	return LGenerateResources;
}

LCommand UEditorSystems::MakeSystemGenerateMap()
{
	const auto CreateDistricts = MakeSystemCreateDistricts();
	const LCommand LGenerateMap = [CreateDistricts](UGameData* GameData)
	{
		CreateDistricts(GameData);
	};
	return LGenerateMap;
}

LCommand UEditorSystems::MakeSystemCreateDistricts()
{
	const LCommand LCreateDistricts = [](UGameData* GameData)
	{
		auto& World = GameData->World;
		const auto& WorldSettings = World.get<FWorldSettings>(GameData->SettingsId);
		for (uint32 Y = 0; Y < WorldSettings.Height; Y++)
			for (uint32 X = 0; X < WorldSettings.Length; X++)
			{
				const auto District = World.create();
				auto& DistrictData = World.emplace<FDistrictData>(District);
				DistrictData.BasicData.Id = District;
				DistrictData.BasicData.Name = FName(TEXT("District"));
				DistrictData.CubeCoordinate = CoordinateUtilities::ConvertToCubeCoordinate(FIntVector(X, Y, 0));
				World.emplace<FBuilding>(District);
			}
	};
	return LCreateDistricts;
}
