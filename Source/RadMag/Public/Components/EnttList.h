// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "entt.hpp"
#include "EnttList.generated.h"

/**
* Using uint32 because entt::entity don't connection with UPROPERTY()
* 
*/
USTRUCT()
struct FEnttList
{
    GENERATED_BODY()
	
	/** */
	UPROPERTY()
	uint32 Children{};
	
	/** */
	UPROPERTY()
	uint32 First{entt::null};
	
	/** */
	UPROPERTY()
	uint32 End{entt::null};
};

/**
* Using uint32 because entt::entity don't connection with UPROPERTY()
* 
*/
USTRUCT()
struct FEnttNode
{    
    GENERATED_BODY()
	
	/** */	
	UPROPERTY()
	uint32 Parent{entt::null};
	
	/** */
	UPROPERTY()
	uint32 Prev{entt::null};
	
	/** */
	UPROPERTY()
	uint32 Next{entt::null};
};