// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCommands.h"
#include "Containers/StaticArray.h"

namespace RadMag
{
	template <typename... ComponentType>
	struct AddComponents
	{
		static decltype(auto) Execute(entt::registry& World, entt::entity Entity)
		{
			(World.emplace<ComponentType>(Entity), ...);
		}
	};

	template <typename... ComponentType>
    struct GetView
	{
		static decltype(auto) Execute(entt::registry& World, entt::entity Entity)
		{
			return World.view<ComponentType...>();
		}
	};
	
	template <typename... ComponentType>
	struct IsValid
	{
		static decltype(auto) Execute(entt::registry& World, entt::entity Entity)
		{
			return World.has<ComponentType...>(Entity);
		}
	};

	template <typename Group, template<typename...> class Functor, class T, T... Ints>
	static decltype(auto) IterateImpl(entt::registry& World, entt::entity Entity,
	                                  std::integer_sequence<T, Ints...>&& Seq)
	{
		return Functor<entt::type_list_element_t<Ints, Group>...>::Execute(World, Entity);
	}

	template <typename Group, template<typename...> class Functor>
	static decltype(auto) Iterate(entt::registry& World, entt::entity Entity)
	{
		return IterateImpl<Group, Functor>(World, Entity, std::make_index_sequence<Group::size>{});
	}
}

namespace Commands
{	
	template <typename... Group>
    void AddGroups(entt::registry& World, entt::entity Entity)
	{
		check(World.valid(Entity));
		(RadMag::Iterate<Group, RadMag::AddComponents>(World, Entity), ...);
	}

	template <typename... Group>
	decltype(auto) GetView(entt::registry& World)
	{
		return (RadMag::Iterate<Group, RadMag::GetView>(World, entt::null) | ...);
	}

	template <typename... Group>
    bool IsValidGroups(entt::registry& World)
	{
		auto View = Commands::GetView<Group...>(World);
		return View.front() != entt::null;
	}

	template <typename... Group>
    bool IsValidGroups(entt::registry& World, entt::entity Entity)
	{
		if(!World.valid(Entity))
			return false;

		return (RadMag::Iterate<Group, RadMag::IsValid>(World, Entity), ...);;
	}

	template <typename... Group>
    decltype(auto) GetGroupComponents(entt::registry& World)
	{
		auto View = Commands::GetView<Group...>(World);
		const auto Entity = View.front();
		check(Entity != entt::null);
		return View.get(Entity);
	}

	template <typename... Group>
	decltype(auto) GetGroupComponents(entt::registry& World, entt::entity Entity)
	{
		auto View = Commands::GetView<Group...>(World);
		check(Entity != entt::null);
		return View.get(Entity);
	}

	template <typename... Components>
    decltype(auto) GetComponents(entt::registry& World)
	{
		auto View = World.view<Components...>();
		const auto Entity = View.front();
		check(Entity != entt::null);
		return View.get(Entity);
	}
	
	template <typename... Group>
	decltype(auto) GetOnlyHasGroup(entt::registry& World, TArray<entt::entity>& Array)
	{
		for(auto Element : Array)
		{
			if(!IsValidGroups<Group...>(World, Element))
				Array.Remove(Element);
		}
		return Array;
	}

	template <typename... T, uint32 Size>
	decltype(auto) ConvertToEntityArray
	(const TStaticArray<TTuple<entt::entity, T...>, Size>& Array)
	{
		TArray<entt::entity> Result;
		for(auto Element : Array)
		{
			if(Element.Key != entt::null)
				Result.Add(Element.Key);
		}
		return Result;
	}

	/**
	 *Impl epic function for static array 
	 */
	template<typename... T, std::size_t Size>
	std::size_t Find(const TStaticArray<TTuple<entt::entity, T...>, Size>& Array, const entt::entity& Item)
	{
		for (auto Index = 0; Index < Array.Num(); Index++)
		{
			if(Array[Index].Key == Item)
				return Index;
		}
		return INDEX_NONE;
	}

	template<typename... T, std::size_t Size>
	void Add(TStaticArray<TTuple<entt::entity, T...>, Size>& Array, const TTuple<entt::entity, T...>& Item)
	{
		for(auto& Element : Array)
		{
			if(Element.Key == entt::null)
			{
				Element = Item;
				return;
			}
		}

		check(false);
	}
}
