// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/WorldInfoGetter.h"
#include "GameData.h"
#include "Commands/HUDCommands.h"
#include "Systems/BasicSystemFactory.h"

USystem* UWorldInfoGetter::MakeSystemWorldInfoGetter(TScriptInterface<IAbstractWidget> Widget, UObject* Outer)
{
	const auto WorldInfoGetter = [Widget](UGameData* GameData)
	{
		const auto Text = HUDCommands::WorldInfoGetter(GameData);
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	return UBasicSystemFactory::CreateSystem(WorldInfoGetter, Outer);
}
