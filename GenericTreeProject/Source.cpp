#include <iostream>
#include "TreeNode.h"

//Can print
void PrintTree(TreeNode* Root)
{
	if (Root != NULL)
	{
		std::cout << "The Data here is: " << Root->Data << ": ";
		for (size_t i = 0; i < Root->ChildrenVector.size(); i++)
		{
			std::cout << Root->ChildrenVector[i]->Data << " ,";
		}
		std::cout << "\n";

		for (size_t i = 0; i < Root->ChildrenVector.size(); i++)
		{
			PrintTree(Root->ChildrenVector[i]);
		}
	}
}

int main()
{
	//Creates the root of the Tree 
	TreeNode* Root = new TreeNode(1);

	//Creates children of the root but has not connected them to the tree yet 
	TreeNode* Node1 = new TreeNode(5);

	TreeNode* Node2 = new TreeNode(2);

	TreeNode* Node3 = new TreeNode(10);

	TreeNode* Node4 = new TreeNode(120);

	//Pushes the addresses of the children nodes to the Root vector 
	Root->ChildrenVector.push_back(Node1);
	Root->ChildrenVector.push_back(Node2);

	Root->ChildrenVector.at(0)->ChildrenVector.push_back(Node3);
	Root->ChildrenVector.at(0)->ChildrenVector.push_back(Node4);

	PrintTree(Root);

	for (size_t i = 0; i < Root->ChildrenVector.size(); i++)
	{
		Root->ChildrenVector.at(i)->PrintElement();

		Root->ChildrenVector.at(0)->ChildrenVector.at(i)->PrintElement();
	}

	TreeNode* NewTree = new TreeNode();

	NewTree = NewTree->LevelWiseTakeInput();

	for (size_t i = 0; i < NewTree->ChildrenVector.size(); i++)
	{
		std::cout << NewTree->ChildrenVector.at(i)->Data << "\n";
	}


	return 0;
}