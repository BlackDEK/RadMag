// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameData.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAddElement, "ECS.Entity.EnttList AddElement",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

namespace EnttListTest
{
	UGameData* CreateElements()
	{
		auto GameData = NewObject<UGameData>();
		const auto List = GameData->World.create();
		/*
		GameData->World.emplace<FTestList>(List);
		for (SIZE_T Index = 0; Index < 5; Index++)
		{
			const auto Node = GameData->World.create();
			GameData->World.emplace<FTestNode>(Node);
		}
		*/
	
		return GameData;
	}
}

bool FAddElement::RunTest(const FString& Parameters)
{
	/*
	auto GameData = EnttListTest::CreateElements();
	auto& World = GameData->World;
	auto OperatorsList = MakeUnique<TOperatorsList>();
	const auto ListId = GameData->World.view<FTestList>().front();
	auto Nodes = GameData->World.view<FTestNode>();
	TArray<entt::entity> TestArray;
	for (auto Element : Nodes)
	{
		OperatorsList->Add<FTestNode, FTestList>
		(
			Element,
			ListId,
			GameData
		);
		TestArray.Add(Element);
	}

	for(auto Index = 0; Index < TestArray.Num(); Index++)
	{
		const auto& Node = World.get<FTestNode>(TestArray[Index]).Node;
		entt::entity PrevNode{entt::null};
		entt::entity NextNode{entt::null};
		entt::entity Parent{ListId};

		if(Index > 0)
			PrevNode = TestArray[Index - 1];
		if(Index < TestArray.Num() - 1)
			NextNode = TestArray[Index + 1];

		if(Node.Parent != static_cast<uint32>(Parent))
			return false;

		if(Node.Prev != static_cast<uint32>(PrevNode))
			return false;
		
		if(Node.Next != static_cast<uint32>(NextNode))
			return false;
	}
	const auto& List = World.get<FTestList>(ListId).List;
	if(List.Children != TestArray.Num())
		return false;
	if(List.First != static_cast<uint64>(TestArray[0]))
		return false;		
	if(List.End != static_cast<uint64>(TestArray[TestArray.Num() - 1]))
		return false;

	*/
	return true;
}
