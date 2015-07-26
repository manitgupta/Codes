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

//Heapify the element at Location i
void Heapify(heap *h, int i)
{
	//Percolate Down Method.
	int l,r,max,temp;
	l = LeftChild(h,i);
	r = RigtChild(h,i);
	//base case when both left and right child do not exist.
	if(l== -1 && r== -1)
		return;
	if(l!=-1 && h->array[l] > h->array[i])		//Find out which of [i],[r],[l] is maximum and find it's position.
		max = l;
	else
		max = i;
	if(r!=-1 && h->array[r] > h->array[max])
		max = r;
	//If left or right is greater, perform swap with [max]
	if(max!=i)
	{
		temp = h->array[max];
		h->array[max] = h->array[i];
		h->array[i] = temp;
	}
	//Recursively the max position element since, swapping may have distrubed the heap property at that position.
	Heapify(h,max);
}

int DeleteMax(heap *h)
{
	int temp;
	if(h->count == -1)		//handle edge case.
		return INT_MIN;
	//Copy value of root into a temp location.
	temp = h->array[0];			
	//Copy last nodes' value into the root.
	h->array[0] = h->array[h->count-1];
	//Remove the copied last node from the heap.		
	h->count == -1;
	//Call Heapify on the root to convert to heap. Since Heapify is called on root, the entire tree will be converted
	//to a heap.
	Heapify(h,0);
	//return deleted element
	return temp;		
}

void ResizeHeap(heap *h)
{
	int *array_old = h->array;
	h->array = (int*)malloc(sizeof(int)*h->capacity*2);
	if(h->array == NULL)
	{
		printf("Memory Error\n");
		return;
	}
	for (int i = 0; i < h->capacity; ++i)
	{
		printf("%d : %d\n",h->array[i],array_old[i]);
		h->array[i] = array_old[i];
	}
	h->capacity*=2;
	free(array_old);
}

void Insert(heap *h, int data)
{
	int i;
	//Check if the tree is full/has reached capacity.
	if(h->count == h->capacity)
		ResizeHeap(h);
	h->count++;
	// Insert new element at the last position.
	i = h->count-1;
	//Handle Base case when first element is inserted.
	if (i == 0)
	{
		h->array[i] = data;
		return;
	}
	//Percolate up technique, keep comparing inserted last element with it's parent until parent is greater.
	while(i>=0 && data > h->array[(i-1)/2])
	{
		h->array[i] = h->array[(i-1)/2];
		i  = (i-1)/2; 
	}
	h->array[i] = data;
}

void printHeap(heap *h)
{
	for (int i = 0; i < h->count; ++i)
	{
		printf(" %d",h->array[i]);
	}
	printf("\n");
}

void DestroyHeap(heap *h)
{
	if(h==NULL)
		return;
	free(h>array);
	free(h);
	//h= NULL;
}

int main()
{
	heap *h = CreateHeap(12,0);
	Insert(h,31);
	Insert(h,10);
	Insert(h,16);
	Insert(h,9);
	Insert(h,8);
	Insert(h,14);
	Insert(h,12);
	Insert(h,3);
	Insert(h,1);
	Insert(h,5);
	Insert(h,7);
	Insert(h,19);
	printHeap(h);
	
	// Heapify(h,1);
	// printHeap(h);
	return 0;
}