// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/HUDSystems/DistrictInfoGetter.h"


#include "Entities/District.h"
#include "entity/entity.hpp"
#include "Handlers/DistrictHandler.h"
#include "Systems/System.h"

USystem* UDistrictInfoGetter::MakeSystemDistrictInfoGetter(TScriptInterface<IAbstractWidget> Widget,
                                                           const FVector& Location, UObject* Outer)
{
	const LCommand DistrictInfoGetter = [Widget, Location](UGameData* GameData)
	{
		const auto& DistrictId = UDistrictHandler::GetDistrictId(Location, GameData);
		if(DistrictId == entt::null) return;
	
		FTextBuilder TextBuilder;
		const auto District = UDistrictHandler::GetDistrict(DistrictId, GameData);;
		TextBuilder.AppendLine(FString("Id: " + FString::FromInt(static_cast<uint32>(District.BasicData.Id))));
		TextBuilder.AppendLine(FString("Name: " + District.BasicData.Name.ToString()));
		TextBuilder.AppendLine(FString(TEXT("CubeCoordinate: ") + District.CubeCoordinate.ToString()));
		const auto Text = TextBuilder.ToText();
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	auto System = NewObject<USystem>(Outer);
	System->Init(DistrictInfoGetter);
	return System;
}
