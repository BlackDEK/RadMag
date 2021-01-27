// Fill out your copyright notice in the Description page of Project Settings.


#include "ECS/Systems/DistrictInfoGetter.h"
#include "ECS/GameData.h"
#include "ECS/Commands/HUDCommands.h"
#include "ECS/Systems/BasicSystemFactory.h"
#include "ECS/Systems/System.h"
#include "ECS/Systems/Interfaces/AbstractWidget.h"

USystem* UDistrictInfoGetter::MakeSystemDistrictInfoGetter(TScriptInterface<IAbstractWidget> Widget,
                                                           const FVector& Location, UObject* Outer)
{
	const auto DistrictInfoGetter = [Widget, Location](UGameData* GameData)
	{
		auto& World = GameData->World;
		const auto Text = Commands::DistrictInfoGetter(Location, World);
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	return UBasicSystemFactory::CreateSystem(DistrictInfoGetter, Outer);
}
