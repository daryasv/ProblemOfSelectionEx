#pragma once
#include "Person.h"
#include "BinarySearchTree.h"
#include "MinHeap.h"
#include <string>
#include <sstream>



//compares the id's of person and return the person with the higest one
Person* compareId(Person per1, Person per2);

void swapPersons(Person personArr[], int index1, int index2);

Person* getInfo(int& moked, int& size);

int Partition(Person personArr[], int left, int rigth);

//implement using Selection algorithm leaned in the class (page 80)
const Person& RandSelection(Person personArr[], int n, int k, int& NumComp);

//implement using MinHeap : insert n items -> deleteMin k times (no need to put back in the heap)
const Person& selectHeap(Person personArr[], int n, int k, int& NumComp);

//implement using BinarySearchTree : insert items ona by one -> find the K item in it's size
const Person& BST(Person personArr[], int n, int k, int& NumComp);

void inorder(BSTreeNode* node, int k, int* counter, Person* person);

