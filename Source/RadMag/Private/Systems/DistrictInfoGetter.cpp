// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/DistrictInfoGetter.h"

#include "Commands/InternalCommands/HUDCommands.h"
#include "Systems/System.h"
#include "Systems/Interfaces/AbstractWidget.h"

USystem* UDistrictInfoGetter::MakeSystemDistrictInfoGetter(TScriptInterface<IAbstractWidget> Widget,
                                                           const FVector& Location, UObject* Outer)
{
	const auto Command = [Widget, Location](UGameData* GameData)
	{
		const auto Text = HUDCommands::DistrictInfoGetter(Location, GameData);
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	auto System = NewObject<USystem>(Outer);
	System->Init(Command);
	return System;
}
