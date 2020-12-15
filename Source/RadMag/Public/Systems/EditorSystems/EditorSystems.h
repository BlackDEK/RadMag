// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "System.h"
#include "UObject/NoExportTypes.h"
#include "EditorSystems.generated.h"

class USystem;

/**
 * 
 */
UCLASS(BlueprintType)
class RADMAG_API UEditorSystems final : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static USystem* MakeSystemGenerateWorld(const int32& Length, const int32& Height, const int32& CommonDivisor, UObject* Outer);

private:
	
	static LCommand MakeSystemSetSettings(const int32& Length, const int32& Height, const int32& CommonDivisor);
	static LCommand MakeSystemGenerateResources();
	static LCommand MakeSystemGenerateMap();
	static LCommand MakeSystemCreateDistricts();
	
};
