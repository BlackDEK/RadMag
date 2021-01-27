// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TurnSystemListener.generated.h"

UINTERFACE(BlueprintType)
class UTurnSystemListener : public UInterface
{
	GENERATED_BODY()
};

class RADMAG_API ITurnSystemListener
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category = "|-- Info")
	void OnNextTurn();
};
