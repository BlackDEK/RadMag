﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "ECS/Systems/DistrictInfoGetter.h"
#include "ECS/Commands/HUDCommands.h"
#include "ECS/Systems/BasicSystemFactory.h"
#include "ECS/Systems/System.h"
#include "ECS/Systems/Interfaces/AbstractWidget.h"

USystem* UDistrictInfoGetter::MakeSystemDistrictInfoGetter(TScriptInterface<IAbstractWidget> Widget,
                                                           const FVector& Location, UObject* Outer)
{
	const auto DistrictInfoGetter = [Widget, Location](UGameData* GameData)
	{
		const auto Text = HUDCommands::DistrictInfoGetter(Location, GameData);
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	return UBasicSystemFactory::CreateSystem(DistrictInfoGetter, Outer);
}