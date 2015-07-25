#ifndef htops_h
#define htops_h
#include "hashtable.h"

void populateHashtable(char filename[]);
void printHT(int htsize, FILE *fp);
void insertHashtable(int htsize, int cust_id, char *item_code,int cost_item);
int findEntry(int htsize, int cust_id, char *item_code);
//int purchasedby(Hash_item ht, int htsize, int cust_id);
int hash1(char *key,int size);
int hast2(int key, int size);
void init();
#endif