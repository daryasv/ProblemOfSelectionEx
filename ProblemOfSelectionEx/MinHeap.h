#ifndef MINHEAP_H
#define MINHEAP_H
#include "Person.h"

class MinHeap
{
	Person* data;
	int maxSize;
	int heapSize;
	int allocated;
	void FixHeap(int node);
public:
	MinHeap(int max);
	MinHeap(Person A[], int size);
	~MinHeap();
	Person Min();
	Person DeleteMin();
	int Right(int node);
	int Left(int node);
	int Parent(int node);
	void Insert(Person p);
	void Swap(Person* node, Person* min);
};

#endif
