﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AbstractWidget.generated.h"

UINTERFACE(BlueprintType)
class ECSCORE_API UAbstractWidget : public UInterface
{
    GENERATED_BODY()
};

class ECSCORE_API IAbstractWidget
{
    GENERATED_BODY()
    
public:
    
    UFUNCTION(BlueprintNativeEvent, Category = "|-- Info")
    void OnUpdateInfo(UPARAM(ref) const FText& OutText);
};
