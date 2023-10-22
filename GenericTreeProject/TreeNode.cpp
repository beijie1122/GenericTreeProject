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

TreeNode::~TreeNode()
{

}
