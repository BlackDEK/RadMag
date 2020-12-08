// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "System.generated.h"

class UGameData;
using LCommand = TFunction<void(UGameData*)>;

/**
 * 
 */
UCLASS(BlueprintType)
class ECSCORE_API USystem final : public UObject
{
    GENERATED_BODY()

protected:

    UPROPERTY()
    bool bInit;

    LCommand ExecuteCommand;
    LCommand UndoCommand;

public:

    USystem()
    {
        ExecuteCommand = [](UGameData*)
        {
            check(false);
        };
        UndoCommand = [](UGameData*)
        {
            check(false);
        };
    }

    ~USystem() = default;

    void Init(LCommand SetExecuteCommand, LCommand SetUndoCommand = [](UGameData*) { check(false) })
    {
        check(!bInit);
        ExecuteCommand = SetExecuteCommand;
        UndoCommand = SetUndoCommand;
        bInit = true;
    }

    void Execute(UGameData* GameData) const
    {
        check(bInit);
        check(GameData);
        ExecuteCommand(GameData);
    }

    void Undo(UGameData* GameData) const
    {
        check(bInit);
        check(GameData);
        UndoCommand(GameData);
    }
};
