// Fill out your copyright notice in the Description page of Project Settings.


#include "ECS/Systems/HUDSystems.h"
#include "ECS/GameData.h"
#include "ECS/Commands/HUDCommands.h"
#include "ECS/Systems/BasicSystemFactory.h"

USystem* UHUDSystems::MakeSystemCityInfoGetter
(TScriptInterface<IAbstractWidget> Widget, const FVector& Location, UObject* Outer)
{
	const auto CityInfoGetter = [Widget, Location](UGameData* GameData)
	{
		auto& World = GameData->World;
		const auto Text = Commands::CityInfoGetter(Location, World);
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	return UBasicSystemFactory::CreateSystem(CityInfoGetter, Outer);
}
