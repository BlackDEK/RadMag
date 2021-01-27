// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Interfaces/TurnSystemListener.h"
#include "UObject/Object.h"
#include "TurnSystemsFactory.generated.h"

/**
 * 
 */
UCLASS()
class RADMAG_API UTurnSystemsFactory final : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
    static USystem* MakeSystemNextTurn(TArray<TScriptInterface<ITurnSystemListener>> Listeners, UObject* Outer);	
};
