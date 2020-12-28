// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData.h"

namespace BasicInternalCommands
{
	template <typename T>
	inline void CreateEntity(const uint32& Count, UGameData* GameData)
	{
		auto& World = GameData->World;
		for (uint32 Index = 0; Index < Count; Index++)
		{
			const auto Entity = World.create();
			World.emplace<T>(Entity);
		}
	}

	template <typename T>
	inline TPair<bool, T> Get(UGameData* GameData)
	{
		auto& World = GameData->World;
		const auto Id = World.view<T>().front();
		if (Id == entt::null)
			return TPair<bool, T>(false, T());
		const auto Entity = World.get<T>(Id);
		return TPair<bool, T>(true, Entity);
	}

	template <typename T>
	inline TPair<bool, T> Get(const entt::entity& Id, UGameData* GameData)
	{
		auto& World = GameData->World;
		if (World.valid(Id))
			return TPair<bool, T>(false, T());
		if (World.has<T>(Id))
			return TPair<bool, T>(false, T());
		const auto Entity = World.get<T>(Id);
		return TPair<bool, T>(true, Entity);
	}

	template <typename T>
	inline void GetAll(TArray<T>& Result, UGameData* GameData)
	{
		auto& World = GameData->World;
		const auto Ids = World.view<T>();
		if (Ids.front() == entt::null)
			return;
		for (auto Id : Ids)
			Result.Add(World.get<T>(Id));
	}

	template <typename T>
    inline entt::entity GetId(const FGuid& Guid, UGameData* GameData)
	{
		auto& World = GameData->World;
		const auto Ids = World.view<T>();
		if (Ids.front() == entt::null)
			return entt::null;
		for (auto Id : Ids)
			if(Guid == World.get<T>(Id).Guid)
				return Id;
		return entt::null;
	}
}
