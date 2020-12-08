// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AbstractChunk.generated.h"

UINTERFACE(BlueprintType)
class ECSCORE_API UAbstractChunk : public UInterface
{
	GENERATED_BODY()
};

class ECSCORE_API IAbstractChunk
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category = "|-- Info")
	void OnCreateChunk(UPARAM(ref) TArray<FVector>& Vertices, UPARAM(ref) TArray<int32>& Triangles,
	                 UPARAM(ref) TArray<FLinearColor>& VertexColors);

	UFUNCTION(BlueprintNativeEvent, Category = "|-- Info")
	int32 GetId();
};
