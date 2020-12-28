// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/WorldInfoGetter.h"
#include "GameData.h"
#include "Commands/InternalCommands/HUDCommands.h"
#include "Systems/System.h"

USystem* UWorldInfoGetter::MakeSystemWorldInfoGetter(TScriptInterface<IAbstractWidget> Widget, UObject* Outer)
{
	const auto Sender = [Widget](UGameData* GameData)
	{
		const auto Text = HUDCommands::WorldInfoGetter(GameData);
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	auto System = NewObject<USystem>(Outer);
	System->Init(Sender);
	return System;
}
