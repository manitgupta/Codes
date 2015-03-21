#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "htops.h"

#define PRIME 107
#define SIZE 1000

Hash_item *Ht[SIZE];

void init()
{
	int i;
	for(i = 0; i < SIZE; i++)
	{
		Ht[i] = (Hash_item*)malloc(sizeof(Hash_item));
		int j;
		for( j = 0 ; j < CSIZE; j++)
		{
			Ht[i]->Hid[j] = (Hash_id*)malloc(sizeof(Hash_id));
			Ht[i]->Hid[j]->Head = NULL;
		}
	}
}

int hash1(char *key, int size)
{
	int sum=0,i=0;
	char c = key[0];
	while(c!='\0')
	{
		c = key[i++];
		sum+=(int)c;
	}
	return ((sum%PRIME)%size);
}

int hash2(int key, int size)
{
	int num,sum=0;
	while(key>0)
	{
		num = key%10;
		sum+=num;
		key/=10;
	}
	return (sum%CSIZE);
}
void insertHashtable(int htsize, int cust_id, char *item_code,int cost_item)
{
	int key1 = hash1(item_code,htsize);
	//printf("%d\n",key1);
	int key2 = hash2(cust_id,htsize);
	//printf("%d\n",key2);
	//Ht[key1]->Hid[key2] = (Hash_id*)malloc(sizeof(Hash_id));
	Item *temp;
	temp = (Item*)malloc(sizeof(Item));
	temp->item_code = (char*)malloc(sizeof(char)*10);
	strcpy(temp->item_code,item_code);
	temp->cust_id = cust_id;
	temp->cost_item = cost_item;
	//printf("%s\n",temp->item_code);
	temp->next = Ht[key1]->Hid[key2]->Head;
	Ht[key1]->Hid[key2]->Head = temp;
	//printf("%s\n",Ht[key1]->Hid[key2]->Head->item_code);
	//printf("%d %d %d %s %d\n",key1,key2,Ht[key1]->Hid[key2]->Head->cust_id,Ht[key1]->Hid[key2]->Head->item_code,Ht[key1]->Hid[key2]->Head->cost_item);
	//no error till here.
}

int findEntry(int htsize,int cust_id, char* item_code)
{
	int key1 = hash1(item_code,htsize);
	int key2 = hash2(cust_id,htsize);
	Item *temp = Ht[key1]->Hid[key2]->Head;

	if(temp!=NULL)
	{	
		while(temp!=NULL)
		{
			if(strcmp(temp->item_code,item_code) == 0 && temp->cust_id == cust_id)
			{ 
				return temp->cost_item;
			}
			else
			{
				temp = temp->next;
			}
		}
		return -1;
	}
	else
		return -1;
	
}

void populateHashtable(char filename[])
{
	FILE *fp;
	fp = fopen(filename,"r+");
	int cust_id,cost_item;
	char *item_code = (char*)malloc(sizeof(char)*10);
	while(!feof(fp))
	{	
		
		fscanf(fp, "%d %s %d",&cust_id,item_code,&cost_item);
		//printf("%d %s %d\n",cust_id,item_code,cost_item);
		//no error till here.
		insertHashtable(SIZE,cust_id,item_code,cost_item);
	}
	fclose(fp);
}
void printHT(int htsize, FILE *fp)
{
	int i,j;
	for(i = 0; i < htsize; i++)
	{
		for( j = 0; j < CSIZE; j++)
		{
				Item *temp = Ht[i]->Hid[j]->Head;
				if (temp!=NULL)
				{
					while(temp!=NULL)
					{
						fprintf(fp,"Key1= %d Key2=%d Cust_id=%d Item_Code=%s Cost_Item=%d\n",i,j,temp->cust_id,temp->item_code,temp->cost_item);
						temp = temp->next;
					}
				}
		}
	}
}