// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/HUDSystems/HUDSystems.h"
#include "GameData.h"
#include "Entities/Settings.h"
#include "Systems/System.h"
#include "Systems/Utilities/HexUtilities.h"

USystem* UHUDSystems::MakeSystemWorldInfoGetter(TScriptInterface<IAbstractWidget> Widget, UObject* Outer)
{
	const LCommand WorldInfoGetter = [Widget](UGameData* GameData)
	{
		const auto& World = GameData->World;
		const auto& WorldSettings = World.get<FWorldSettings>(GameData->SettingsId);
		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Length: " + FString::FromInt(WorldSettings.Length)));
		TextBuilder.AppendLine(FString("Height: " + FString::FromInt(WorldSettings.Height)));
		TextBuilder.AppendLine(FString(TEXT("CommonDivisor: ") + FString::FromInt(WorldSettings.CommonDivisor)));
		const auto Text = TextBuilder.ToText();
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	auto System = NewObject<USystem>(Outer);
	System->Init(WorldInfoGetter);
	return System;
}

USystem* UHUDSystems::MakeSystemDistrictInfoGetter(TScriptInterface<IAbstractWidget> Widget, const FVector& Location,
                                                   UObject* Outer)
{
	const LCommand DistrictInfoGetter = [Widget, Location](UGameData* GameData)
	{
		const auto& World = GameData->World;
		const auto& District = DistrictsUtilities::DistrictsHex(Location, GameData);
		if(District == entt::null) return;
	
		FTextBuilder TextBuilder;
		const auto& DistrictData = World.get<FDistrictData>(District);
		TextBuilder.AppendLine(FString("Id: " + FString::FromInt(static_cast<uint32>(DistrictData.BasicData.Id))));
		TextBuilder.AppendLine(FString("Name: " + DistrictData.BasicData.Name.ToString()));
		TextBuilder.AppendLine(FString(TEXT("CommonDivisor: ") + DistrictData.CubeCoordinate.ToString()));
		const auto Text = TextBuilder.ToText();
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	auto System = NewObject<USystem>(Outer);
	System->Init(DistrictInfoGetter);
	return System;
}
