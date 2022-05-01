#include "MinHeap.h"
#include "Person.h"

MinHeap::MinHeap(int max)
{
	data = new Person[max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
}
MinHeap::MinHeap(Person A[], int size)
{
	heapSize = maxSize = size;
	data = A;
	allocated = 0;

	for (int i = size / 2 - 1; i >= 0; i--)
		FixHeap(i);
}


MinHeap::~MinHeap()
{
	if (allocated)
		delete[] data;
	data = NULL;
}
int MinHeap::Parent(int node)
{
	return (node - 1) / 2;
}
int MinHeap::Left(int node)
{
	return (2 * node + 1);
}
int MinHeap::Right(int node)
{
	return (2 * node + 2);
}
void MinHeap::FixHeap(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);

	if ((left < heapSize) && (data[left].getId() < data[node].getId()))
		min = left;
	else
		min = node;
	if ((right < heapSize) && (data[right].getId() < data[node].getId()))
		min = right;

	if (min != node)
	{
		Swap(data[node], data[min]);
		FixHeap(min);
	}
}
void Swap(Person node, Person min)
{
	Person temp = node;
	node = min;
	min = temp;
}
Person MinHeap::DeleteMin()
{
	if (heapSize < 1)
		return Person();
	Person min = data[0];
	heapSize--;
	data[0] = data[heapSize];
	FixHeap(0);
	return min;
}
void MinHeap::Insert(Person p)
{
	if (heapSize == maxSize)
		;//handle error
	int i = heapSize;
	heapSize++;

	while ((i < 0) && (data[Parent(i)].getId() > p.getId()))
	{
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = p;
}
Person MinHeap::Min()
{
	return data[0];
}
