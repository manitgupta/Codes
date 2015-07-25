#include<stdio.h>
#include<stdlib.h>
#include "ParkingLot.h"
#include<string.h>


#define MAX 100

int top = 0;        //Denotes no. of cars in parking lot.
parkinglot p[MAX]; //This is the parkinglot temp.


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


void SortedCars(parkinglot *temp, int left, int right)
{
        int mid = (left+right)/2;
        if( left < right)
        {
                SortedCars(temp,left,mid);
                SortedCars(temp,mid+1,right);
                Merge(temp,left,mid,right);
        }
}

void Merge(parkinglot *temp, int left, int mid, int right)
{
        parkinglot temparray[right-left+1];
        int pos=0,lpos = left,rpos = mid + 1;
        while(lpos <= mid && rpos <= right)
        {
                if(temp[lpos].c.regno < temp[rpos].c.regno)
                {
                        temparray[pos++] = temp[lpos++];
                }
                else
                {
                        temparray[pos++] = temp[rpos++];
                }
        }
        while(lpos <= mid)  temparray[pos++] = temp[lpos++];
        while(rpos <= right)temparray[pos++] = temp[rpos++];
        int iter;
        for(iter = 0;iter < pos; iter++)
        {
                temp[iter+left] = temparray[iter];
        }
        return;
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
	SortedCars(p,0,lots-1);
	printCurrentlyParked();
}
	
	
