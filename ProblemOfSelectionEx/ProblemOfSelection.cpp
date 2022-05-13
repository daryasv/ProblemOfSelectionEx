#include <iostream>
using namespace std;
#include "ProblemOfSelection.h"

//????????
Person* compareId(Person &per1, Person &per2)
{
    if (per1.getId() >= per2.getId())
        return &per1;
    else
        return &per2;
}

void swapPersons(Person personArr[], int index1, int index2)
{
    Person temp = personArr[index1];
    personArr[index1] = personArr[index2];
    personArr[index2] = temp;
}


int partition(int arr[], int low, int high)
{
    // pivot
    int pivot = arr[high];

    // Index of smaller element
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller
        // than or equal to pivot
        if (arr[j] <= pivot) {

            // increment index of
            // smaller element
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    //srand(time(NULL));
    int random = low + rand() % (high - low);

    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}


//implement using Selection algorithm leaned in the class (page 80)
//Select(int A[], int left. int rigth)
// left = 0 || rigth = n || k = i
const Person& RandSelection(Person personArr[], int n, int k, int& NumComp)
{
    Person person;
    return person;
}

//implement using MinHeap : insert n items -> deleteMin k times (no need to put back in the heap)
const Person& selectHeap(Person personArr[], int n, int k, int& NumComp)
{
    //TODO: TEST

    MinHeap minHeap(personArr, n);
    Person person;

    for (int i = 0; i < k; i++)
    {
        person = minHeap.DeleteMin();
    }

    return person;
}

//implement using BinarySearchTree : insert items one by one -> find the K item in it's size
const Person& BST(Person personArr[], int n, int k, int& NumComp)
{
    //TODO: TEST

    BinarySearchTree bst;
    for (int i = 0; i < n; i++)
    {
        bst.Insert(personArr[i]);
    }
    int counter = 0;
    Person person;
    inorder(bst.getRoot(), k,&counter,&person);

    return person;
}

void inorder(BSTreeNode* node,int k,int* counter,Person* person)
{
    if (node == NULL) {
        return;
    }
    inorder(node->left,k,counter,person);
    (*counter)++;
    if ((*counter) == k) {
        (*person) = node->Data;
    }
    inorder(node->right,k,counter,person);
}

int main()
{
    int moked, size;
    Person* people = getInfo(moked, size);
    int counter = 0;
    selectHeap(people, size, moked, counter);
    //BST(people, size, moked, counter);
    
    //TODO:

    //A) Get input from user : 1. seed number for srand
    //                         2. number of persons (Array size)
    //                         3. Array of Persons
    //                         4. key (k) to search
    //B) for every input check for errors (less/more persons than entered, person with existing id, key -1 / >size)
    //   if input check failed print "invalid input" and exit the program with exit(1)

    //C) Find the K item in its size by using every one of the 3 following ways
    //   the function will return the concurrent Person (function output) + number on comparisons (output parameter)
    
    //1. implement using Selection algorithm leaned in the class (page 80)
    //const Person& RandSelection(Person[], int n, int k, int& NumComp);

    //2. implement using MinHeap : insert n items -> deleteMin k times (no need to put back in the heap)
    //const Person& selectHeap(Person[], int n, int k, int& NumComp);

    //3. implement using BinarySearchTree : insert items ona by one -> find the K item in its size
    //const Person& BST(Person[], int n, int k, int& NumComp);
}