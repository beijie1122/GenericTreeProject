#include "TreeNode.h"

TreeNode::TreeNode()
{

}

TreeNode::TreeNode(int Element)
{
	this->Data = Element;
}

void TreeNode::PrintElement()
{
	std::cout << "The element of this node is: " << Data << "\n";
}

void TreeNode::LevelPrintTree(TreeNode* Root)
{
	std::queue<TreeNode*> PrintQueue;

	PrintQueue.push(Root);

	while (!PrintQueue.empty())
	{
		TreeNode* front = PrintQueue.front();
		PrintQueue.pop();

		std::cout << front->Data << ": ";

		for (size_t i = 0; i < front->ChildrenVector.size(); i++)
		{
			std::cout << front->ChildrenVector.at(i)->Data << ", ";
		}
		std::cout << "\n";

		for (size_t i = 0; i < front->ChildrenVector.size(); i++)
		{
			PrintQueue.push(front->ChildrenVector.at(i));
		}

	}
}

int TreeNode::CountNodes(TreeNode* Root)
{

	int Count = 1;

	if (Root != NULL)
	{
		
		for (size_t i = 0; i < Root->ChildrenVector.size(); i++)
		{
			Count += CountNodes(Root->ChildrenVector[i]);
		}

		return Count;
	}
	else
	{
		return 0;
	}



}

int TreeNode::NumberOfLevels(TreeNode* Root)
{
	int Levels = 0;

	if (Root != NULL)
	{
		for (size_t i = 0; i < Root->ChildrenVector.size(); i++)
		{
			Levels = std::max(Levels, NumberOfLevels(Root->ChildrenVector[i]));
		}
		
		return Levels + 1;
		
	}
	else
	{
		return -1;
	}
}

void TreeNode::PrintAtKLevel(TreeNode* Root, int Level)
{
	if (Root != NULL)
	{
		if (Level == 0)
		{
			std::cout << Root->Data << "\n";
			return;
		}
		for (size_t i = 0; i < Root->ChildrenVector.size(); i++)
		{
			PrintAtKLevel(Root->ChildrenVector.at(i), Level-1);
		}		
	}
	else
	{
		//Edge Case to avoid segmentation fault
		std::cout << "Your Tree Is Empty!\n";
		return;
	}


}

int TreeNode::CountLeafNodes(TreeNode* Root)
{
	int Count = 0;

	if (Root == NULL)
	{
		return -1;
	}
	else
	{
		if (Root->ChildrenVector.size() == 0)
		{
			Count = 1;
			return Count;
		}
		for (size_t i = 0; i < Root->ChildrenVector.size(); i++)
		{
			Count += CountLeafNodes(Root->ChildrenVector.at(i));
		}


		return Count;
	}
}

void TreeNode::PreOrderTraversal(TreeNode* Root)
{
	if (Root != NULL)
	{
		std::cout << Root->Data << " ";

		for (size_t i = 0; i < Root->ChildrenVector.size(); i++)
		{
			PreOrderTraversal(Root->ChildrenVector.at(i));
		}
	}
	else 
	{
		std::cout << "Tree is empty!\n";
	}
	




}

//Good for understanding the concept but bad in practice -- User must keep track of recursion 
TreeNode* TreeNode::TakeInput()
{
	int RootData;
	std::cout << "Enter Data: \n";
	std::cin >> RootData;
	int n;

	TreeNode* Root = new TreeNode(RootData);

	std::cout << "How Many Children will the root have? \n";
	std::cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		TreeNode* Child = TakeInput();
		Root->ChildrenVector.push_back(Child);
	}

	return Root;
}

TreeNode* TreeNode::LevelWiseTakeInput()
{
	int RootData;

	int ChildrenNumber;

	std::queue<TreeNode*> InputQueue;

	std::cout << "Input: \n";
	std::cin >> RootData;

	TreeNode* Root = new TreeNode(RootData);

	InputQueue.push(Root);

	while (!InputQueue.empty())
	{
		TreeNode* front = InputQueue.front();
		InputQueue.pop();

		std::cout << "How Many Children of the: " << front->Data << "\n";
		std::cin >> ChildrenNumber;
		
		for (size_t i = 0; i < ChildrenNumber; i++)
		{
			int ChildData;
			std::cout << "Enter a data value for this child: " << front->Data << "\n";
			std::cin >> ChildData;
			TreeNode* ChildNode = new TreeNode(ChildData);
			InputQueue.push(ChildNode);
			front->ChildrenVector.push_back(ChildNode);
		}

	}
	return Root;
}

TreeNode::~TreeNode()
{

}
