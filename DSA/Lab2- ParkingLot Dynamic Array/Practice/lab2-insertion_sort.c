#include<stdio.h>
#include<stdlib.h>
#include "ParkingLot.h"
#include<string.h>


#define MAX 100

int top = 0;        //Denotes no. of cars in parking lot.
parkinglot p[MAX]; //This is the parkinglot array.


void Enter_ParkingLot(parkinglot pl, int lots)
{
		 
		 if (top >= lots)
		 {
		 	printf("Parking Lot Full!");
		 	return;
		 }
		 else
		 {
			p[top] = pl;
			top++;
		 }
}

void printCurrentlyParked()
{
	int i = 0;
	printf("The parkingLot is: \n");
	for ( i = 0 ; i < top ; i++)
	{
		printf("%d , %s \n",p[i].c.regno,p[i].c.name);
	}
}

void sortCars() 
{
	int i,j;
	parkinglot temp;
	for( i=0; i<top ; i++ )
	{
      	temp.c.regno = p[i].c.regno;
		temp.parkid = p[i].parkid;
		strcpy(temp.c.name,p[i].c.name);
      	j=i-1;
      	while(temp.c.regno<p[j].c.regno && j>=0)
      	{
      		p[j+1].c.regno = p[j].c.regno;
			strcpy(p[j+1].c.name, p[j].c.name);
	 		p[j+1].parkid = p[j].parkid;
          	j=j-1;
      	}
      	p[j+1].c.regno = temp.c.regno;
		strcpy(p[j+1].c.name, temp.c.name);
	 	p[j+1].parkid = temp.parkid;
  }
}

void main()
{
	printf("Enter number of Lots:");
	int lots;
	scanf("%d",&lots);
	int i = 0;
	for( i = 0; i < lots ; i++ )
	{
		printf("Enter parkingId, Regno, and OwnerName \n");
		scanf("%d%d%s",&p[i].parkid,&p[i].c.regno,p[i].c.name);
		Enter_ParkingLot(p[i],lots);
	}
	sortCars();
	printCurrentlyParked();
}
	
	
