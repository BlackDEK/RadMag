// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameData.h"

namespace RadMag
{
	template <typename EntityType, std::size_t Index>
	struct AddComponent : public AddComponent<EntityType, Index - 1>
	{
		static constexpr void Execute(UGameData* GameData, entt::entity Entity)
		{
			auto& World = GameData->World;
			using Type = entt::type_list_element_t<Index, EntityType>;
			World.emplace<Type>(Entity, Type());
			AddComponent<EntityType, Index - 1>::Execute(GameData, Entity);
		}
	};

	template <typename EntityType>
	struct AddComponent<EntityType, 0>
	{
		static constexpr void Execute(UGameData* GameData, entt::entity Entity)
		{
			auto& World = GameData->World;
			using Type = entt::type_list_element_t<0, EntityType>;
			World.emplace<Type>(Entity, Type());
		}
	};

}

namespace BasicInternalCommands
{
	template <typename EntityType>
	inline entt::entity CreateEntity(UGameData* GameData)
	{
		auto& World = GameData->World;
		const auto Entity = World.create();
		RadMag::AddComponent<EntityType, EntityType::size - 1>::Execute(GameData, Entity);
		return Entity;
	}

	template <bool GetFirst, typename EntityType>
	inline bool IsValidEntity(UGameData* GameData, entt::entity Id = entt::null)
	{
		auto& World = GameData->World;
		using FirstComponent = entt::type_list_element_t<0, EntityType>;
		if constexpr (GetFirst)
			Id = World.view<FirstComponent>().front();
		return World.valid(Id) && World.has<FirstComponent>(Id);
	}

	template <bool GetFirst, typename EntityType, typename... ComponentType>
	inline decltype(auto) Get(UGameData* GameData, entt::entity Entity = entt::null)
	{
		auto& World = GameData->World;
		if constexpr (GetFirst)
		{
			check(Entity == entt::null);			
			using FirstComponent = entt::type_list_element_t<0, EntityType>;
			Entity = World.view<FirstComponent>().front();
		}
		check(World.valid(Entity));
		check(World.has<ComponentType...>(Entity));

		return World.get<ComponentType...>(Entity);
	}

	template <typename EntityType>
	inline void GetAllIds(UGameData* GameData, TArray<entt::entity>& Result)
	{
		auto& World = GameData->World;
		using FirstComponent = entt::type_list_element_t<0, EntityType>;
		const auto Ids = World.view<FirstComponent>();
		if (Ids.front() == entt::null)
			return;
		for (auto Id : Ids)
			Result.Add(Id);
	}
}
