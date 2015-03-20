#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ParkingLot.h"

/*
	Author : Manit Gupta
	Program : Lab-2 2015 DSA BITS Pilani
	Merge Sort on Dynamically Allocated Struct Array.
*/


int TOP = 0;

#ifndef MAX
#define MAX 20
ParkingLot *p[MAX];
#endif

void Enter_ParkingLot(ParkingLot pl, int slots)
{
	if ( TOP >= slots)
	{
		printf("ParkingLot is Full!\n");
		return;
	}
	p[TOP] = (ParkingLot*) malloc(sizeof(ParkingLot));	//allocate mem to pointer element of pointer array
	p[TOP]->c.regno = pl.c.regno;
	p[TOP]->c.owner_name = (char*) malloc(50*sizeof(char));
	strcpy(p[TOP]->c.owner_name,pl.c.owner_name);
	TOP++;
}

void printCurrentlyParked()
{
	int i=0;
	printf("The Parking Lot is:\n");
	while (i < TOP)
	{
		printf("%d : %s\n",p[i]->c.regno,p[i]->c.owner_name);
		i++;
	}
}


void sortcars_merge(int l, int m, int r)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	ParkingLot Left[n1],Right[n2];
	for (i = 0; i < n1; ++i)
	{
		Left[i].c.regno = p[l+i]->c.regno;
		Left[i].c.owner_name = (char*) malloc(sizeof(char)*50);
		strcpy(Left[i].c.owner_name, p[l+i]->c.owner_name);
	}
	for (j = 0; j < n2; ++j)
	{
		Right[j].c.regno = p[m+1+j]->c.regno;
		Right[j].c.owner_name = (char*) malloc(sizeof(char)*50);
		strcpy(Right[j].c.owner_name, p[m+1+j]->c.owner_name);
	}
	i=0; j=0; k=l;
	while (i < n1 && j < n2)
	{
		if (Left[i].c.regno <= Right[j].c.regno)
		{
			p[k]->c.regno = Left[i].c.regno;
			strcpy(p[k]->c.owner_name, Left[i].c.owner_name);
			i++; k++;
		}
		else if (Left[i].c.regno > Right[j].c.regno)
		{
			p[k]->c.regno = Right[j].c.regno;
			strcpy(p[k]->c.owner_name, Right[j].c.owner_name);
			j++; k++;
		}
	}
	while ( i < n1)
	{
		p[k]->c.regno = Left[i].c.regno;
		strcpy(p[k]->c.owner_name, Left[i].c.owner_name);
		i++; k++;
	}
	while ( j < n2)
	{
		p[k]->c.regno = Right[j].c.regno;
		strcpy(p[k]->c.owner_name, Right[j].c.owner_name);
		j++; k++;
	}	
	
}

void sortcars_mergeSort(int l,int r) //Equivalent to the mergeSort function Used.
{
	if (l < r)
	{
		int m = (l+r)/2;
		//printf("m = %d\n",m);
		sortcars_mergeSort(l,m);
		sortcars_mergeSort(m+1,r);
		sortcars_merge(l,m,r);
	}
}


int main(int argc, char* argv[])
{
	int slots,i;
	if (argc == 2)
	{
		slots = atoi(argv[1]);
	}
	else if(argc > 2)
	{
		printf("Please specify no. of slots only!\n");
		exit(0);
	}
	else
	{
		printf("Too few Args!\n");
		exit(0);
	}
	printf("Enter %d Regno and OwnerName \n",slots);
	ParkingLot pl;
	pl.c.owner_name = (char*)malloc(sizeof(char)*50);	
	//printf("%d\n",TOP);
	
	//Enter_ParkingLot(pl,slots);
	for( i = 0; i < slots ; i++ )
	{
		scanf("%d%s",&pl.c.regno,pl.c.owner_name);
		Enter_ParkingLot(pl,slots);
	}
	

	//printCurrentlyParked();
	sortcars_mergeSort(0,slots-1);
	//printf("Sorted:\n");
	printCurrentlyParked();
	return 0;
}

