#ifndef hashtable_h
#define hashtable_h


#define CSIZE 100


typedef struct Item
{
	int cust_id;
	char *item_code;
	int cost_item;
	struct Item *next;
}Item;

typedef struct Hash_id
{
	Item i;
	struct Item *Head;
}Hash_id;

typedef struct Hash_item
{
	int id;
	Hash_id *Hid[CSIZE];
}Hash_item;

#endif