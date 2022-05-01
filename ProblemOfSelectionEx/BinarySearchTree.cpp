#include "BinarySearchTree.h"

#include "Person.h"
BSTreeNode::BSTreeNode(Person p, BSTreeNode* Left, BSTreeNode* Right)
{
	Data = p;
	left = Left;
	right = Right;
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
		;//handle error
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
	newnode = new BSTreeNode(p, NULL, NULL);
	if (parent == NULL)
		root = newnode;
	else if (p.getId() < parent->Data.getId())
		parent->left = newnode;
	else
		parent->right = newnode;
}
void BinarySearchTree::Delete(int id)
{

}
Person BinarySearchTree::Min()
{

}
Person BinarySearchTree::Max()
{

}