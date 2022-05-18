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


int partition(Person arr[], int left, int right)
{
    // pivot
    int pivot = arr[left].getId();

    int pivotIndex = left;
    int nonPivotIndex = right;

    while (pivotIndex != nonPivotIndex) {
        if (pivotIndex < nonPivotIndex) {
            if (arr[nonPivotIndex].getId() < pivot) {
                swap(arr[pivotIndex], arr[nonPivotIndex]);
                swap(pivotIndex, nonPivotIndex);
                nonPivotIndex++;
            }
            else {
                nonPivotIndex--;
            }
        }
        else {//nonPivotIndex < pivotIndex
            if (arr[nonPivotIndex].getId() > pivot) {
                swap(arr[pivotIndex], arr[nonPivotIndex]);
                swap(pivotIndex, nonPivotIndex);
                nonPivotIndex--;
            }
            else {
                nonPivotIndex++;
            }
        }
    }
    return pivotIndex;
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(Person arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    //srand(time(NULL));
    int random = low + 537 % (high - low);//rand()

    // Swap random to left
    swap(arr[random], arr[low]);

    return partition(arr, low, high);
}

Person SelectRandom(Person A[], int left, int right, int i) {
    int pivot;
    int leftPart;

    pivot = partition_r(A, left, right);
    leftPart = pivot - left + 1;
    if (i == leftPart) {
        return A[pivot];
    }
    if (i < leftPart) {
        return SelectRandom(A, left, pivot - 1, i);
    }
    else {
        return SelectRandom(A, pivot + 1, right, i - leftPart);
    }
}

//implement using Selection algorithm leaned in the class (page 80)
//Select(int A[], int left. int rigth)
// left = 0 || rigth = n || k = i
const Person& RandSelection(Person personArr[], int n, int k, int& NumComp)
{
    Person* p = new Person();
    Person* temp = new Person[n];
    //copy to new array and send
    for (int i = 0; i < n; i++)
    {
        temp[i] = personArr[i];
    }
    *p = SelectRandom(temp, 0, n-1, k);
    delete[]temp;
    return *p;
}



//implement using MinHeap : insert n items -> deleteMin k times (no need to put back in the heap)
const Person& selectHeap(Person personArr[], int n, int k, int& NumComp)
{

    MinHeap minHeap(personArr, n);
    Person* person = new Person();

    for (int i = 0; i < k; i++)
    {
        *person = minHeap.DeleteMin();
    }

    return *person;
}

//implement using BinarySearchTree : insert items one by one -> find the K item in it's size
const Person& BST(Person personArr[], int n, int k, int& NumComp)
{

    BinarySearchTree bst;
    for (int i = 0; i < n; i++)
    {
        bst.Insert(&personArr[i], NumComp);
    }
    int counter = 0;
    Person *person = new Person();
    bst.findInOrder(k, &counter, *person, NumComp);
    //maybe print person here because person returns badly to main/ send person by ref to this function
    return *person;// Dtor deletes the node
}


int main()
{
    Person p;
    int moked, size;
    Person* people = getInfo(moked, size);
    int counter = 0;
    p = RandSelection(people, size, moked, counter);
    cout << "RandSelection: " << p.getId() << " " << p.getName() << " " << counter << " " << "comparisons" << endl;
    counter = 0;
    p = selectHeap(people, size, moked, counter);
    cout << "selectHeap: " << p.getId() << " " << p.getName() << " " << counter << " " << "comparisons" << endl;
    counter = 0;
    p = BST(people, size, moked, counter);
    cout << "BST: " << p.getId() << " " << p.getName() << " " << counter << " " << "comparisons" << endl;

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