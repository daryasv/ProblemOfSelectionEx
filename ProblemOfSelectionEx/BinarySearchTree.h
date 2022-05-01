#pragma once

//#ifndef BINSEARCHTREE_H
//#define BINSEARCHTREE_H
#include <string>
struct BSTreeNode
{
	Person Data;
	BSTreeNode* left, * right;
public:
	BSTreeNode(Person p, BSTreeNode* Left, BSTreeNode* Right);
};
class BinarySearchTree
{
	BSTreeNode* root;
public:
	BinarySearchTree() : root(NULL) {}
	~BinarySearchTree();
	BSTreeNode* Find(int key);
	void Insert(Person p);
	void Delete(int id);
	Person Min();
	Person Max();
};

//#endif