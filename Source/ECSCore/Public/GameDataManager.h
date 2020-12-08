// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameDataManager.generated.h"

class UGameData;

/**
 * 
 */
UCLASS(Blueprintable)
class ECSCORE_API UGameDataManager : public UObject
{
    GENERATED_BODY()

protected:

    UPROPERTY()
    UGameData* GameData;

public:

    UGameDataManager();
    
    UFUNCTION(BlueprintCallable)
    void CreateGameData();
    
    UFUNCTION(BlueprintCallable)
    void Execute(USystem* System);
};
