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

	int CountNodes(TreeNode* Root);

	int NumberOfLevels(TreeNode* Root);

	void PrintAtKLevel(TreeNode* Root, int Level);

	int CountLeafNodes(TreeNode* Root);

	void PreOrderTraversal(TreeNode* Root);

	void PostOrderTraversal(TreeNode* Root);

	void DeleteTree(TreeNode* Root);

	TreeNode* TakeInput();

	TreeNode* LevelWiseTakeInput();

	~TreeNode();


};

