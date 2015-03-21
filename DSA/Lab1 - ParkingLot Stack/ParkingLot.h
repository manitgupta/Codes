#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
	Author : Manit Gupta
	Program : Lab-1 2015 DSA BITS Pilani
*/

typedef struct Car
{
	int regno;
	char* owner_name;	
}Car;

typedef struct ParkingLot
{
	//char *parkId;
	struct Car c;
	//*parkId = strcat(atoi(C->regno),C->owner_name);
}ParkingLot;

typedef struct ParkingLotStack
{
	//int id;
	struct ParkingLot pl;
	struct ParkingLotStack *nextP;
}ParkingLotStack;


#ifndef PARK
#define PARK

int empty(ParkingLotStack *Head);
ParkingLotStack* Enter_ParkingLot(ParkingLotStack *Head,ParkingLot p);
ParkingLotStack* Exit_ParkingLot(ParkingLotStack *Head);
void Is_Parked(ParkingLotStack* Head,ParkingLot p);
void init(ParkingLotStack *Head);
void Parking_Snapshot(ParkingLotStack *Head);

#endif


void init(ParkingLotStack *Head)
{
	Head = NULL;
}

ParkingLotStack* Enter_ParkingLot(ParkingLotStack *Head,ParkingLot p)
{
	ParkingLotStack* temp;
	temp = (ParkingLotStack*) malloc(sizeof(ParkingLotStack));
	if (temp == NULL)
	{
		printf("Overflow!\n");
		exit(0);
	}
	temp->pl.c.regno = p.c.regno;
	temp->pl.c.owner_name = (char*)malloc(sizeof(char)*15);			//MOST IMPORTANT STEP. ALLOCATE MEMORY FOR STORING THE NAME
	strcpy(temp->pl.c.owner_name,p.c.owner_name);
	if (Head == NULL)
	{
		Head = temp;
		Head->nextP = NULL;
	}
	else
	{
		temp->nextP = Head;
		Head = temp;
	}
	return Head;
}

ParkingLotStack* Exit_ParkingLot(ParkingLotStack *Head)
{
	if(Head == NULL)
	{
		printf("Parking Lot Empty!\n");
	}
	else
	{
		printf("Popped ParkingLot is:\n");
		printf("%d : %s\n",Head->pl.c.regno,Head->pl.c.owner_name);
		Head = Head->nextP;
	}
	return Head;
}

void Is_Parked(ParkingLotStack *Head,ParkingLot p)
{
	ParkingLotStack *temp = Head;
	
	while(temp!=NULL)
	{
		if (temp->pl.c.regno == p.c.regno)
		{
			printf("The ParkingLot: %d is present in ParkingLot Stack\n",p.c.regno);
			break;
		}
		temp = temp->nextP;
	}
	if (temp == NULL)
	{
		printf("ParkingLot: %d not present!\n", p.c.regno);
	}
}
void Parking_Snapshot(ParkingLotStack *Head)
{
	ParkingLotStack *temp = Head;
	if(temp != NULL)
	{
		printf("The Current ParkingLot Has:\n");
		while(temp!=NULL)
		{
			printf("%d : %s\n",temp->pl.c.regno,temp->pl.c.owner_name);
			temp = temp->nextP;
		}
	}
	else
	{
		printf("The ParkingLot is Empty!\n");
	}
}

int empty(ParkingLotStack *Head)
{
	return Head == NULL ? 1:0;
}

