// Fill out your copyright notice in the Description page of Project Settings.


#include "ECS/Systems/MapInfoGetter.h"
#include "ECS/GameData.h"
#include "ECS/Commands/HUDCommands.h"
#include "ECS/Systems/BasicSystemFactory.h"

USystem* UMapInfoGetter::MakeSystemMapInfoGetter(TScriptInterface<IAbstractWidget> Widget, UObject* Outer)
{
	const auto MapInfoGetter = [Widget](UGameData* GameData)
	{
		auto& World = GameData->World;
		const auto Text = Commands::MapInfoGetter(World);
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	return UBasicSystemFactory::CreateSystem(MapInfoGetter, Outer);
}
