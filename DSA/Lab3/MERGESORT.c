#include <stdio.h>
#include <stdlib.h>

struct item {
 int number;
 struct item *next;
};
typedef struct item Node;

Node *addnode(int number,Node *next);

Node *mergesort(Node *head);

Node *merge(Node *head_one,Node *head_two);

void printlist(Node *nod)
{
	FILE* fp=fopen("output","w");
	while(nod!=NULL)
	{
		fprintf(fp,"%d\n",nod->number);
		nod=nod->next;
	}
	fprintf(fp,"\n");
}

 void main() {
 Node *head;
 Node *current;
 Node *next;

 head = NULL;
 FILE *fp=fopen("input","r");
 int count=7,val;
 while(count>0)
	{
		fscanf(fp,"%d\n",&val);
		head=addnode(val,head);
		count--;
	}
 head = mergesort(head);
 printlist(head);
}

Node *addnode(int number,Node *next) {
 	Node *tnode;
 	tnode = (Node*)malloc(sizeof(*tnode));

 	if(tnode != NULL) {
  	tnode->number = number;
 	 tnode->next = next;
 	}

 	return tnode;
}

Node *mergesort(Node *head) {
  Node *head_1;
  Node *head_2;

 if((head == NULL) || (head->next == NULL)) 
  return head;

 head_1 = head;
 head_2 = head->next;
 //to calculate last element
 while((head_2 != NULL) && (head_2->next != NULL)) {
   head = head->next;
   head_2 = head->next->next;
 }
 head_2 = head->next;
 head->next = NULL;
 //return merge(start,end)
 return merge(mergesort(head_1), mergesort(head_2));
}

 Node *merge(Node *head_1,Node *head_2) {
  Node *head_3;

 if(head_1 == NULL) 
  return head_2;

 if(head_2 == NULL) 
  return head_1;

 if(head_1->number < head_2->number) {
  head_3 = head_1;
  head_3->next = merge(head_1->next, head_2);
 } else {
  head_3 = head_2;
  head_3->next = merge(head_1, head_2->next);
 }

 return head_3;
}

