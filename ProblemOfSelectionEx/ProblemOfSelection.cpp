#include <iostream>
using namespace std;
#include "ProblemOfSelection.h"


void swapPersons(Person personArr[], int index1, int index2)
{
    Person temp = personArr[index1];
    personArr[index1] = personArr[index2];
    personArr[index2] = temp;
}


int partition(Person arr[], int left, int right,int& NumComp)
{
    // pivot
    int pivot = arr[left].getId();

    int pivotIndex = left;
    int nonPivotIndex = right;
    while (pivotIndex != nonPivotIndex) {
        NumComp++;
        if (pivotIndex < nonPivotIndex) {
            if (arr[nonPivotIndex].compareTo(pivot,NumComp) < 0) {
                swap(arr[pivotIndex], arr[nonPivotIndex]);
                swap(pivotIndex, nonPivotIndex);
                nonPivotIndex++;
            }
            else {
                nonPivotIndex--;
            }
        }
        else {//nonPivotIndex < pivotIndex
            if (arr[nonPivotIndex].compareTo(pivot,NumComp) > 0) {
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
int partitionRandom(Person arr[], int low, int high,int& NumComp)
{
    // Generate a random number in between
    // low .. high
    int random = low + rand() % (high - low);

    // Swap random to left
    swap(arr[random], arr[low]);

    return partition(arr, low, high, NumComp);
}

Person SelectRandom(Person A[], int left, int right, int i,int& NumComp) {
    int pivot;
    int leftPart;

    pivot = partitionRandom(A, left, right, NumComp);
    leftPart = pivot - left + 1;
    NumComp++;
    if (i == leftPart) {
        return A[pivot];
    }
    else if (i < leftPart) {
        return SelectRandom(A, left, pivot - 1, i, NumComp);
    }
    else {
        return SelectRandom(A, pivot + 1, right, i - leftPart, NumComp);
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
    *p = SelectRandom(temp, 0, n-1, k, NumComp);
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
    NumComp = minHeap.getNumComp();
    return *person;
}

//implement using BinarySearchTree : insert items one by one -> find the K item in it's size
const Person& BST(Person personArr[], int n, int k, int& NumComp)
{

    BinarySearchTree bst;
    for (int i = 0; i < n; i++)
    {
        bst.Insert(&personArr[i]);
    }
    int counter = 0;
    Person *person = new Person();
    bst.findInOrder(k, &counter, *person);
    NumComp = bst.getNumComp();
    //maybe print person here because person returns badly to main/ send person by ref to this function
    return *person;// Dtor deletes the node
}


int main()
{
    Person p;
    int moked, size,seed;
    Person* people = getInfo(moked, size, seed);
    int counter = 0;
    srand(seed);
    p = RandSelection(people, size, moked, counter);
    cout << "RandSelection: " << p.getId() << " " << p.getName() << " " << counter << " " << "comparisons" << endl;
    counter = 0;
    p = selectHeap(people, size, moked, counter);
    cout << "selectHeap: " << p.getId() << " " << p.getName() << " " << counter << " " << "comparisons" << endl;
    counter = 0;
    p = BST(people, size, moked, counter);
    cout << "BST: " << p.getId() << " " << p.getName() << " " << counter << " " << "comparisons" << endl;
}