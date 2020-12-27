// Fill out your copyright notice in the Description page of Project Settings.


#include "GameDataManager.h"
#include "GameData.h"
#include "Systems/System.h"


UGameDataManager::UGameDataManager()
{
    GameData = nullptr;
}

void UGameDataManager::CreateGameData()
{
    GameData = NewObject<UGameData>(this);    
}

void UGameDataManager::Execute(USystem* System)
{
    check(System);
    check(GameData);
    System->Execute(GameData);    
}

void UGameDataManager::AddSystemInTurn(USystem* System)
{
    check(System);
    check(GameData);
    TurnSystems.Add(System);
}

void UGameDataManager::RemoveSystemInTurn(const int32& Index)
{
    check(TurnSystems.Contains(Index));
    check(GameData);
    TurnSystems.RemoveAt(Index);
}

void UGameDataManager::NextTurn()
{
    for(auto& Element : TurnSystems)
        Element->Execute(GameData);
}
