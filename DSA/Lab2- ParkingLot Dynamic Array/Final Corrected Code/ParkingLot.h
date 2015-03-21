#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
	Author : Manit Gupta
	Program : Lab-2 2015 DSA BITS Pilani, data structures defined.
*/

typedef struct Car
{
	int regno;
	char* owner_name;
}Car;

typedef struct ParkingLot
{
	int parkid;
	struct Car c;
}ParkingLot;

