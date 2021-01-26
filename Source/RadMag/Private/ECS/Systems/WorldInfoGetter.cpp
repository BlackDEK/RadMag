// Fill out your copyright notice in the Description page of Project Settings.


#include "ECS/Systems/WorldInfoGetter.h"
#include "ECS/GameData.h"
#include "ECS/Commands/HUDCommands.h"
#include "ECS/Systems/BasicSystemFactory.h"

USystem* UWorldInfoGetter::MakeSystemWorldInfoGetter(TScriptInterface<IAbstractWidget> Widget, UObject* Outer)
{
	const auto WorldInfoGetter = [Widget](UGameData* GameData)
	{
		const auto Text = Commands::WorldInfoGetter(GameData);
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	return UBasicSystemFactory::CreateSystem(WorldInfoGetter, Outer);
}
