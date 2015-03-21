#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ParkingLot.h"

/*
	Author : Manit Gupta
	Program : Lab-2 2015 DSA BITS Pilani
	Insertion Sort on Dynamically Allocated Struct Array.
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

void sortcars()
{
	int i,j;
	//printf("%d\n",TOP );
	for (j = 1; j < TOP; ++j)
	{
		ParkingLot* key;
		key = (ParkingLot*) malloc(sizeof(ParkingLot));
		key->c.regno = p[j]->c.regno;
		key->c.owner_name = (char*) malloc(sizeof(char)*50);
		strcpy(key->c.owner_name,p[j]->c.owner_name);

		i = j-1;
		while ( i>=0 && key->c.regno <= p[i]->c.regno)
		{
			p[i+1]->c.regno = p[i]->c.regno;
			strcpy(p[i+1]->c.owner_name,p[i]->c.owner_name);
			i--;
		}
		p[i+1]->c.regno = key->c.regno;
		strcpy(p[i+1]->c.owner_name,key->c.owner_name);
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
	sortcars();
	//printf("Sorted:\n");
	printCurrentlyParked();
	return 0;
}

