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

TreeNode::~TreeNode()
{

}
