// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/MapInfoGetter.h"
#include "GameData.h"
#include "Commands/InternalCommands/HUDCommands.h"
#include "Systems/BasicSystemFactory.h"

USystem* UMapInfoGetter::MakeSystemMapInfoGetter(TScriptInterface<IAbstractWidget> Widget, UObject* Outer)
{
	const auto MapInfoGetter = [Widget](UGameData* GameData)
	{
		const auto Text = HUDCommands::MapInfoGetter(GameData);
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	return UBasicSystemFactory::CreateSystem(MapInfoGetter, Outer);
}
