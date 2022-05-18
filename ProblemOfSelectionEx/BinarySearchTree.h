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
	int NumComp;
	BSTreeNode* root;
	int size;
	void findInOrderRecursive(BSTreeNode* node, int k, int* counter, Person& person);
public:
	//?????
	BinarySearchTree() : root(nullptr) { size = 0; NumComp = 0; }
	~BinarySearchTree();
	void DtorHelper(BSTreeNode* root);
	int getSize() { return size; }
	void makeEmpty();
	void makeEmptyHelper(BSTreeNode* root);
	bool isEmpty();
	BSTreeNode* getRoot() { return root; }
	BSTreeNode* Find(int key);
	void Insert(Person* p);
	BSTreeNode* insertHelper(BSTreeNode* node, Person& p);
	void Delete(int id);
	BSTreeNode* DeleteHelp(BSTreeNode* node, int id);
	BSTreeNode* findParent(BSTreeNode* node, BSTreeNode* parent, int id);
	BSTreeNode* Min(BSTreeNode* node);
	BSTreeNode* Max();
	void findInOrder(int k, int* counter, Person& person);
	int getNumComp();
};
//functions to add:
//suck from the book
//pred
#endif