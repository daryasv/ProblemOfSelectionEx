#include <iostream>
using namespace std;
#include "ProblemOfSelection.h"

/*
//implement using Selection algorithm leaned in the class (page 80)
const Person& RandSelection(Person[], int n, int k, int& NumComp)
{
    //TODO
}

//implement using MinHeap : insert n items -> deleteMin k times (no need to put back in the heap)
const Person& selectHeap(Person[], int n, int k, int& NumComp)
{
    //TODO
}

//implement using BinarySearchTree : insert items ona by one -> find the K item in it's size
const Person& BST(Person[], int n, int k, int& NumComp)
{
    //TODO
}*/

int main()
{
    int moked;
    //TODO:

    //A) Get input from user : 1. number of persons (Array size)
    //                         2. Array of Persons
    //                         3. key (k) to search
    //B) for every input check for errors (less/more persons than entered, person with existing id, key -1 / >size)
    //   if input check failed print "invalid input" and exit the program with exit(1)

    //C) Find the K item in its size by using every one of the 3 following ways
    //   the function will return the concurrent Person (function output) + number on comparisons (output parameter)
    
    //1. implement using Selection algorithm leaned in the class (page 80)
    const Person& RandSelection(Person[], int n, int k, int& NumComp);

    //2. implement using MinHeap : insert n items -> deleteMin k times (no need to put back in the heap)
    const Person& selectHeap(Person[], int n, int k, int& NumComp);

    //3. implement using BinarySearchTree : insert items ona by one -> find the K item in its size
    const Person& BST(Person[], int n, int k, int& NumComp);
}