// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/BasicSystemFactory.h"
#include "Systems/System.h"

USystem* UBasicSystemFactory::CreateSystem(TFunction<void(UGameData*)> Command, UObject* Outer)
{
	USystem* System;
	if(Outer)
		System = NewObject<USystem>(Outer);
	else
		System = NewObject<USystem>();

	System->Init(Command);
	return System;
}
