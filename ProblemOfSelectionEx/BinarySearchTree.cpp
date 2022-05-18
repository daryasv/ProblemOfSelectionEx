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

void BinarySearchTree::Insert(Person* p){
	if (root == nullptr)
		root = new BSTreeNode(*p);
	else
		insertHelper(root, *p);
}

BSTreeNode* BinarySearchTree::insertHelper(BSTreeNode* node, Person& p) {
	if (node == nullptr) {
		return new BSTreeNode(p);
	}
	if (p.compareTo(node->Data, NumComp) < 0) {
		node->left = insertHelper(node->left, p);
	}
	else {
		node->right = insertHelper(node->right, p);
	}
	return node;
}

void BinarySearchTree::makeEmpty()
{
	makeEmptyHelper(root);
	root = nullptr;
	size = 0;
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
BSTreeNode* BinarySearchTree::Min(BSTreeNode *node)
{
	BSTreeNode* curr = node;
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
void BinarySearchTree::Delete(int id)
{
	/*BSTreeNode* father, * node;
	father = findParent(root,root, id);
	node = Find(id);
	DeleteHelper(father, node);*/
	DeleteHelp(root, id);
	size--;
}
BSTreeNode* BinarySearchTree::DeleteHelp(BSTreeNode* node, int id)
{
	if (node == NULL)
		return node;
	(NumComp)++;
	if (id < node->Data.getId())
		node->left = DeleteHelp(node->left, id);

	else if (id > node->Data.getId())
		node->right = DeleteHelp(node->right, id);
	else// id is where node is
	{
		if (node->right == NULL && node->left == NULL)//no children
		{
			delete node;//?
			return NULL;
		}
		else if (node->left == NULL) {//with one child
			BSTreeNode* temp = node->right;
			delete node;
			return temp;
		}
		else if (root->right == NULL) {
			BSTreeNode* temp = node->left;
			delete node;
			return temp;
		}
		//has 2 children
		BSTreeNode* help = Min(node->right);
		root->Data = help->Data;
		root->right = DeleteHelp(root->right, help->Data.getId());
	}
	return root;

}


void BinarySearchTree::findInOrder(int k, int* counter, Person& person)
{
	findInOrderRecursive(this->root,k, counter, person);
}

int BinarySearchTree::getNumComp()
{
	return this->NumComp;
}

void BinarySearchTree::findInOrderRecursive(BSTreeNode* node, int k, int* counter, Person& person)
{
	NumComp++;
	if (node == NULL) {
		return;
	}
	findInOrderRecursive(node->left, k, counter, person);
	(*counter)++;
	NumComp++;
	if ((*counter) == k) {
		person = node->Data;
		return;
	}
	findInOrderRecursive(node->right, k, counter, person);
}


BSTreeNode* BinarySearchTree::findParent(BSTreeNode* node, BSTreeNode* parent, int id)
{
	if (node == NULL)
		return NULL;
	if (node->Data.getId() == id)
	{
		return parent;
	}
	else
	{
		BSTreeNode* temp = findParent(node->left, node, id);
		if (temp == NULL) {
			return findParent(node->right, node, id);
		}
		else {
			return temp;
		}
	}
}
