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

void TreeNode::LevelPrintTree()
{

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
			std::cout << "Enter a data value for this child: " << front->Data;
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
