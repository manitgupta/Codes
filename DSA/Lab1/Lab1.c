#include "ParkingLot.h"
#include <stdio.h>
#include <stdlib.h>

/*
	Author : Manit Gupta
	Program : Lab-1 2015 DSA BITS Pilani
*/

int main()
{
	ParkingLotStack* Head = NULL;
	init(Head);
	
	ParkingLot p1;
	p1.c.regno = 123;
	p1.c.owner_name = "Manit";
	
	ParkingLot p2;
	p2.c.regno = 1234;
	p2.c.owner_name = "Maanya";
	
	Head = Enter_ParkingLot(Head,p1);
	Parking_Snapshot(Head);

	Is_Parked(Head,p1);
	
	Head = Enter_ParkingLot(Head,p2);
	Parking_Snapshot(Head);
	
	Is_Parked(Head,p2);
	
	Head = Exit_ParkingLot(Head);
	Parking_Snapshot(Head);

	Is_Parked(Head,p2);
	Parking_Snapshot(Head);	
	return 0;
}