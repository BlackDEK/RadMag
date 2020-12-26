// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Handler.generated.h"

class UGameData;
/**
 * 
 */
UCLASS()
class RADMAG_API UHandler : public UObject
{
	GENERATED_BODY()

protected:

	template<typename T>
	static void CreateEntity(const uint32& Count, UGameData* GameData)
	{
		auto& World = GameData->World;
		for(uint32 Index = 0; Index < Count; Index++)
		{			
			const auto Entity = World.create();
			World.emplace<T>(Entity);			
		}
	}
};
