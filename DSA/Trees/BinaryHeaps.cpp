#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define _DEBUG

#define Inf 2147483647
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)
#define INT_MIN -99999999


struct Heap
{
	int *array;			//Array to store the heap elements
	int capacity;		//Size of the Heap
	int count;			//No. of Elements in Heap
	int heap_type;		// Type of the heap
};

typedef struct Heap heap;

heap* CreateHeap(int capacity, int heap_type)
{
	heap *h = (heap*)malloc(sizeof(heap));
	if(h == NULL)
	{
		printf("Memory Erro\n");
		exit(0);
	}
	h->capacity = capacity;
	h->heap_type = heap_type;
	h->count = 0;
	h->array = (int*)malloc(sizeof(int)*h->capacity);
	if(h->array == NULL)
	{
		printf("Memory Error\n");
		exit(0);
	}
	return h;
}

int Parent(heap* h, int i) //i = Index of child
{
	//Max(i) = h->count - 1
	if(i <0 && i >= h->count)
		return -1;
	else
		return (i-1)/2;
}

int LeftChild(heap* h, int i)	//i = Index of Parent
{
	int left = 2*i+1;
	if(left >= h->count)
		return -1;
	else
		return left;
}

int RigtChild(heap* h,int i)
{
	int right = 2*i+2;
	if(right >= h->count)
		return -1;
	else
		return right;
}

int GetMax(heap *h)
{
	if(h->count ==0)
		return -1;
	return h->array[0];
}

int main()
{
	return 0;
}