// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameDataManager.generated.h"

class UGameData;

/**
 * 
 */
UCLASS(BlueprintType)
class RADMAG_API UGameDataManager final : public UObject
{
    GENERATED_BODY()

protected:

    UPROPERTY()
    UGameData* GameData;

    UPROPERTY()
    TArray<USystem*> TurnSystems;

public:

    UGameDataManager();
    
    UFUNCTION(BlueprintCallable)
    void CreateGameData();
    
    UFUNCTION(BlueprintCallable)
    void Execute(USystem* System);
    
    UFUNCTION(BlueprintCallable)
    void AddSystemInTurn(USystem* System);

    UFUNCTION(BlueprintCallable)
    void RemoveSystemInTurn(const int32& Index);

    UFUNCTION(BlueprintCallable)
    void NextTurn();
};
