#pragma once
#include "Person.h"
#include "BinarySearchTree.h"
#include <string>
#include <sstream>


Person* getInfo(int& moked);
//implement using Selection algorithm leaned in the class (page 80)
const Person& RandSelection(Person[], int n, int k, int& NumComp);

//implement using MinHeap : insert n items -> deleteMin k times (no need to put back in the heap)
const Person& selectHeap(Person[], int n, int k, int& NumComp);

//implement using BinarySearchTree : insert items ona by one -> find the K item in it's size
const Person& BST(Person[], int n, int k, int& NumComp);

