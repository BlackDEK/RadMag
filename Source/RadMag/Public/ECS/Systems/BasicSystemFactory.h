// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BasicSystemFactory.generated.h"

class UGameData;
/**
 * 
 */
UCLASS()
class RADMAG_API UBasicSystemFactory : public UObject
{
	GENERATED_BODY()

public:

	static USystem* CreateSystem(TFunction<void(UGameData*)> Command, UObject* Outer);
};
