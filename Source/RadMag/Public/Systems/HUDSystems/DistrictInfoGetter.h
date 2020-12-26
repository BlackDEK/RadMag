// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AbstractWidget.h"
#include "UObject/Object.h"
#include "DistrictInfoGetter.generated.h"

/**
 * 
 */
UCLASS()
class RADMAG_API UDistrictInfoGetter final : public UObject
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
    static USystem* MakeSystemDistrictInfoGetter(TScriptInterface<IAbstractWidget> Widget, const FVector& Location,
                                                 UObject* Outer);
};
