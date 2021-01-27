// Fill out your copyright notice in the Description page of Project Settings.


#include "ECS/Systems/TurnSystemsFactory.h"
#include "ECS/GameData.h"
#include "ECS/Commands/TurnCommands.h"
#include "ECS/Systems/BasicSystemFactory.h"

USystem* UTurnSystemsFactory::MakeSystemNextTurn(TArray<TScriptInterface<ITurnSystemListener>> Listeners, UObject* Outer)
{
	const auto NextTurn = [Listeners](UGameData* GameData)
	{		
		auto& World = GameData->World;
		Commands::IncrementingTurn(World);
		for(auto Listener : Listeners)
		{			
			ITurnSystemListener::Execute_OnNextTurn(Listener.GetObject());
		}
	};
	return UBasicSystemFactory::CreateSystem(NextTurn, Outer);
}
