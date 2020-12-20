// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "System.generated.h"

class UGameData;
using LCommand = TFunction<void(UGameData*)>;

/**
 * 
 */
UCLASS(BlueprintType)
class ECSCORE_API USystem final : public UObject
{
	GENERATED_BODY()

protected:

	UPROPERTY()
	bool bInit;

	LCommand ExecuteCommand;

public:

	USystem()
	{
		ExecuteCommand = [](UGameData*)
		{
			check(false);
		};
	}

	~USystem() = default;

	void Init(LCommand SetExecuteCommand)
	{
		check(!bInit);
		ExecuteCommand = SetExecuteCommand;
		bInit = true;
	}

	void Execute(UGameData* GameData) const
	{
		check(bInit);
		check(GameData);
		ExecuteCommand(GameData);
	}

	bool IsInit() const { return bInit; }

	void Delete()
	{
		this->ConditionalBeginDestroy();
	}
};
