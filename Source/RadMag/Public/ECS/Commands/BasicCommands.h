﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCommands.h"

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
		auto View = Commands::GetView<Group...>(World);
		check(Entity != entt::null);
		for(auto ViewEntity : View)
			if(ViewEntity == Entity)
				return true;		
		return false;
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

	template <typename... Components>
    decltype(auto) GetComponents(entt::registry& World, entt::entity Entity)
	{
		auto View = World.view<Components...>();
		check(Entity != entt::null);
		return View.get(Entity);
	}
}
