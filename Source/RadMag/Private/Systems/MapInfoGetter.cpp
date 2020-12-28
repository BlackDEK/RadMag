// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/MapInfoGetter.h"
#include "GameData.h"
#include "Commands/InternalCommands/HUDCommands.h"
#include "Systems/System.h"

USystem* UMapInfoGetter::MakeSystemMapInfoGetter(TScriptInterface<IAbstractWidget> Widget, UObject* Outer)
{
	const auto Command = [Widget](UGameData* GameData)
	{
		const auto Text = HUDCommands::MapInfoGetter(GameData);
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	auto System = NewObject<USystem>(Outer);
	System->Init(Command);
	return System;
}
