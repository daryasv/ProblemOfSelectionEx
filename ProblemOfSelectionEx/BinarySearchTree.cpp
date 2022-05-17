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
/*void BinarySearchTree::Insert(Person p)
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

	size++;
}
*/
void BinarySearchTree::Insert(Person* p, int& numComp){
	if (root == nullptr)
		root = new BSTreeNode(*p);
	else
		insertHelper(root, *p, numComp);
}

BSTreeNode* BinarySearchTree::insertHelper(BSTreeNode* node,Person& p, int& numComp){
	if (node == nullptr) {
        return new BSTreeNode(p);
    }
	numComp++;
    if (p.getId() < node->Data.getId()) {
        node->left = insertHelper(node->left, p,numComp);
    }
    else {
        node->right = insertHelper(node->right, p,numComp);
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
void BinarySearchTree::Delete(int id, int& NumComp)
{
	/*BSTreeNode* father, * node;
	father = findParent(root,root, id);
	node = Find(id);
	DeleteHelper(father, node);*/
	DeleteHelp(root, id, NumComp);
	size--;
}
BSTreeNode* BinarySearchTree::DeleteHelp(BSTreeNode* node, int id, int& NumComp)
{
	if (node == NULL)
		return node;
	NumComp++;
	if (id < node->Data.getId())
		node->left = DeleteHelp(node->left, id, NumComp);

	else if (id > node->Data.getId())
		node->right = DeleteHelp(node->right, id, NumComp);
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
		root->right = DeleteHelp(root->right, help->Data.getId(), NumComp);
	}
	return root;

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
		return findParent(node->left, node, id);
		return findParent(node->right, node, id);
	}
}
/*void BinarySearchTree::DeleteHelper(BSTreeNode* parent, BSTreeNode* node)
{
	if(node == NULL)

	if (node->left == nullptr)
	{

	}
	else if (node->right == nullptr)
	{

	}
}*/