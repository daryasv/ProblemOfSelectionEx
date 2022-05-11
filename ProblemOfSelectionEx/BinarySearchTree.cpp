#include "BinarySearchTree.h"

BSTreeNode::BSTreeNode(Person p, BSTreeNode* Left, BSTreeNode* Right)
{
	Data = p;
	left = Left;
	right = Right;
}
BinarySearchTree::~BinarySearchTree()
{
	DtorHelper(root);
}
void BinarySearchTree::DtorHelper(BSTreeNode* root)
{
	if (root)
	{
		DtorHelper(root->left);
		DtorHelper(root->right);
		delete root;
	}
}
BSTreeNode* BinarySearchTree::Find(int key)
{
	BSTreeNode* temp = root;
	while (temp != NULL)
	{
		if (key == (temp->Data.getId()))
			return temp;
		else if (key < (temp->Data.getId()))
			temp = temp->left;
		else
			temp = temp->right;
	}
	return NULL;//not found
}
void BinarySearchTree::Insert(Person p)
{
	if (Find(p.getId()) != NULL)//check exists
	{
		cout << "invalid input";
		exit(1);
	}//handle error
	BSTreeNode* temp = root;
	BSTreeNode* parent = NULL;
	BSTreeNode* newnode;
	
	while (temp != NULL)
	{
		parent = temp;
		if (p.getId() < (temp->Data.getId()))
			temp = temp->left;
		else
			temp = temp->right;
	}
	newnode = new BSTreeNode(p);
	if (parent == NULL)
		root = newnode;
	else if (p.getId() < parent->Data.getId())
		parent->left = newnode;
	else
		parent->right = newnode;
}
void BinarySearchTree::makeEmpty()
{
	makeEmptyHelper(root);
	root = nullptr;
}
void BinarySearchTree::makeEmptyHelper(BSTreeNode* root)
{
	if (root == NULL)
		return;
	if (root->left != NULL)
		makeEmptyHelper(root->left);
	if (root->right != NULL)
		makeEmptyHelper(root->right);

	if (root->left == NULL && root->right == NULL)
	{
		delete root;
		return;
	}
}
bool BinarySearchTree::isEmpty()
{
	return root != nullptr ? false : true;
}
BSTreeNode* BinarySearchTree::Min()
{
	BSTreeNode* curr = root;
	while (curr->left != NULL)
	{
		curr = curr->left;
	}
	return curr;
}
BSTreeNode* BinarySearchTree::Max()
{
	BSTreeNode* curr = root;
	while (curr->right != NULL)
	{
		curr = curr->right;
	}
	return curr;
}