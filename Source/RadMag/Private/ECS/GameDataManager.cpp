// Fill out your copyright notice in the Description page of Project Settings.


#include "ECS/GameDataManager.h"
#include "ECS/GameData.h"
#include "ECS/Systems/System.h"


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
