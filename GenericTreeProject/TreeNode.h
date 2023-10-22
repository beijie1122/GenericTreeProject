#pragma once
#include <vector>
#include <iostream>

class TreeNode
{
public:
	int Data;
	std::vector<TreeNode*> ChildrenVector;

	TreeNode();

	TreeNode(int Element);

	void PrintElement();

	TreeNode* TakeInput();

	~TreeNode();


};

