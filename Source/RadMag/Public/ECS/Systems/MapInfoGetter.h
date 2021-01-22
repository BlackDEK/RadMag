// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Interfaces/AbstractWidget.h"
#include "UObject/NoExportTypes.h"
#include "MapInfoGetter.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class RADMAG_API UMapInfoGetter final : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static USystem* MakeSystemMapInfoGetter(TScriptInterface<IAbstractWidget> Widget, UObject* Outer);
};
