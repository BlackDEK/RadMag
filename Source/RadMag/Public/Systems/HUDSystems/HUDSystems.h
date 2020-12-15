// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractWidget.h"
#include "UObject/NoExportTypes.h"
#include "HUDSystems.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class RADMAG_API UHUDSystems final : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static USystem* MakeSystemWorldInfoGetter(TScriptInterface<IAbstractWidget> Widget, UObject* Outer);

	UFUNCTION(BlueprintCallable)
	static USystem* MakeSystemDistrictInfoGetter(TScriptInterface<IAbstractWidget> Widget, const FVector& Location,
	                                             UObject* Outer);
};
