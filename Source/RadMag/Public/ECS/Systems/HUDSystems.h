// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Interfaces/AbstractWidget.h"
#include "UObject/Object.h"
#include "HUDSystems.generated.h"

/**
* 
*/
UCLASS()
class RADMAG_API UHUDSystems final : public UObject
{
	GENERATED_BODY()

	public:

	UFUNCTION(BlueprintCallable)
    static USystem* MakeSystemCityInfoGetter
    (TScriptInterface<IAbstractWidget> Widget, const FVector& Location, UObject* Outer);
};