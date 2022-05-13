#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include <string>
#include <stdlib.h>
#include "Person.h"
struct BSTreeNode
{
	Person Data;
	BSTreeNode* left, * right;
public:
	BSTreeNode(Person data) : Data(data), left(nullptr), right(nullptr) {};
	BSTreeNode(Person p, BSTreeNode* Left, BSTreeNode* Right);
};
class BinarySearchTree
{
	BSTreeNode* root;
public:
	BinarySearchTree() : root(nullptr) {}
	~BinarySearchTree();
	void DtorHelper(BSTreeNode* root);
	void makeEmpty();
	void makeEmptyHelper(BSTreeNode* root);
	bool isEmpty();
	BSTreeNode* getRoot() { return root; }

	BSTreeNode* Find(int key);
	void Insert(Person p);
	void Delete(int id);
	BSTreeNode* DeleteHelp(BSTreeNode* node, int id);
	//void DeleteHelper(BSTreeNode* parent, BSTreeNode* node);//&numComp
	BSTreeNode* findParent(BSTreeNode* node, BSTreeNode* parent, int id);

	BSTreeNode* Min(BSTreeNode* node);
	BSTreeNode* Max();

};
//functions to add:
//suck from the book
//pred
#endif