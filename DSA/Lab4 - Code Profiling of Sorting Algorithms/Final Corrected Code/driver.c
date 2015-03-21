#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
/*
	Author : Manit Gupta
	Program : Lab-4 2015 DSA BITS Pilani
	Driver Program for code profiling.
*/
#ifndef MAX
#define MAX 10000000
#endif

void file_read(char filename[], int N, int *a)
{
	FILE *fp;
	fp = fopen(filename,"r+");
	int i=0;
	while(i < N)
	{
		int num;
		fscanf(fp,"%d",&num);
		a[i++] = num;
	}
	fclose(fp);
}

void file_write(char filename[],int N, int *a)
{
	FILE *fp;
	fp = fopen(filename,"w+");
	int i=0;
	while(i < N)
	{
		fprintf(fp, "%d\n",a[i++]);
	}
	fclose(fp);
}


int main(int argc, char* argv[])
{
	int *arr,SIZE;
	if (argc == 2)
	{
		SIZE = atoi(argv[1]);	
	}
	else
	{
		printf("Insufficient No. of Args!\n");
		exit(0);
	}
	printf("The Size is: %d\n",SIZE);
	arr = (int*)malloc(sizeof(int)*SIZE);
	file_read("input.txt",SIZE,arr);
	//insertion_sort(arr,SIZE);
	mergesort(arr,0,SIZE-1);
	//quicksort(arr,0,SIZE-1);
	file_write("output.txt",SIZE,arr);
	return 0;
}