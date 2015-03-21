#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "htops.h"
#include "hashtable.h"


int main(int argc, char* argv[])
{
	init();
	populateHashtable(argv[1]);
	FILE *fp;
	fp = fopen("output.txt","w+");
	printHT(1000,fp);
	int a = atoi(argv[3]);
	int cost_item = findEntry(1000,a,argv[2]);
	printf("Cost of ItemCode: %s and CustId: %d is: %d\n",argv[2],a,cost_item);
	return 0;
}