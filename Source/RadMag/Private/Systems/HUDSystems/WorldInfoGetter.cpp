// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/HUDSystems/WorldInfoGetter.h"
#include "GameData.h"
#include "Systems/System.h"
#include "Entities/GameRules.h"
#include "Handlers/GameRulesHandler.h"

USystem* UWorldInfoGetter::MakeSystemWorldInfoGetter(TScriptInterface<IAbstractWidget> Widget, UObject* Outer)
{
	const LCommand WorldInfoGetter = [Widget](UGameData* GameData)
	{
		const auto MapRules = UGameRulesHandler::GetGameRules(GameData).MapRules;
		FTextBuilder TextBuilder;
		TextBuilder.AppendLine(FString("Entities: " + FString::FromInt(GameData->World.alive())));
		TextBuilder.AppendLine(FString("Length: " + FString::FromInt(MapRules.ChunkCountOX * MapRules.ChunkSize)));
		TextBuilder.AppendLine(FString("Height: " + FString::FromInt(MapRules.ChunkCountOY * MapRules.ChunkSize)));
		TextBuilder.AppendLine(FString(TEXT("ChunkSize: ") + FString::FromInt(MapRules.ChunkSize)));
		const auto Text = TextBuilder.ToText();
		IAbstractWidget::Execute_OnUpdateInfo(Widget.GetObject(), Text);
	};
	auto System = NewObject<USystem>(Outer);
	System->Init(WorldInfoGetter);
	return System;
}
