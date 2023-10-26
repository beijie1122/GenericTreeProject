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

void printVector(std::vector<int> A)
{
	for (size_t i = 0; i < A.size(); i++)
	{
		std::cout << A.at(i) << " ";
	}

	std::cout << "\nThe size of the vector is: " << A.size() << "\n";
}

void MergeSort(std::vector<int>& A, int const begin, int const end)
{
	if (begin >= end)
	{
		return;
	}

	int mid = begin + (end - begin) / 2;
	MergeSort(A, begin, mid);
	MergeSort(A, mid + 1, end);
	//Merge(A, begin, mid, end);
}

void Merge(std::vector<int>& A, int const Left, int const Mid, int const Right)
{
	int const SubArrayOne = Mid - Left + 1;
	int const SubArrayTwo = Right - Mid;

	auto* LeftVector = new int[SubArrayOne];
	auto* RightVector = new int[SubArrayTwo];
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

	NewTree->LevelPrintTree(NewTree);

	int Count = NewTree->CountNodes(NewTree);

	std::cout << "The amount of nodes in the tree is: " << Count << "\n";

	int TreeHeight = NewTree->NumberOfLevels(NewTree);

	std::cout << "The maximum height of the tree is: " << TreeHeight << "\n";

	NewTree->PrintAtKLevel(NewTree, 2);

	std::cout << "The Number of Leaf Nodes is: " << NewTree->CountLeafNodes(NewTree) << "\n";

	NewTree->PreOrderTraversal(NewTree);

	//std::vector<int> MergeVector{ 2, 5, 3 ,6, 10, 22, 15 };

	//printVector(MergeVector);

	return 0;
}