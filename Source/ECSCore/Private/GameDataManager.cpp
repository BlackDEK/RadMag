// Fill out your copyright notice in the Description page of Project Settings.


#include "GameDataManager.h"
#include "GameData.h"
#include "System.h"


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
    System->Execute(GameData);
    
}
