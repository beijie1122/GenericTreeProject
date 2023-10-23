#pragma once
#include <vector>
#include <iostream>
#include <queue>

class TreeNode
{
public:
	int Data;
	std::vector<TreeNode*> ChildrenVector;

	TreeNode();

	TreeNode(int Element);

	void PrintElement();

	void LevelPrintTree(TreeNode* Root);

	TreeNode* TakeInput();

	TreeNode* LevelWiseTakeInput();

	~TreeNode();


};

