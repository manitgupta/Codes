#include <stdlib.h>     //rand, malloc
#include <stdio.h>      //print


struct listnode {

    struct listnode *next;
    int value;
};

int ListLength (struct listnode *list)
{
    struct listnode *temp = list;
    int i=0;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    return i;
}

struct listnode *SelectPivot(struct listnode *list)
{
    int k, n, i = 0;
    n = ListLength(list);
    struct listnode *pivot=list;
    ///k=rand()%n;  //
    k = 1;
    for (; i < k; ++i)
    {
        pivot=pivot->next;
    }
    return pivot;
}


struct listnode *Quicksort(struct listnode *list)
{
    // Return NULL list
    if (ListLength(list) <= 1) return list;
    struct listnode *less=NULL, *more=NULL, *next, *end, *temp=NULL;

    // Select a random pivot point
    struct listnode *pivot = SelectPivot(list);

    // Remove pivot from list
    while(list !=NULL)
    {
        next = list->next;

        if(list->value != pivot->value)
        {
            list->next=temp;
            temp = list;
        }
        list = next;
    }

    // Divide & Conq
    while(temp != NULL)
    {
        next = temp->next;
        if(temp->value < pivot->value)
        {
            temp->next = less;
            less = temp;
        }
        else 
        {
            temp->next = more;
            more = temp;    
        }
        temp = next;
    }

    // Recursive Calls
    less = Quicksort(less);
    more = Quicksort(more);

    // Merge
    if(less != NULL)
    {
        end = less;
        while(end->next != NULL){
            end=end->next;
            }
        pivot->next=more;
        end->next = pivot;
        return less;        
    }
    else{
        pivot->next = more;
        return pivot;   
    }

}
void printList(struct listnode *list, char* name)
{   
    struct listnode *node;
    node=list;
	FILE *f;
	f= fopen(name,"w");
	fprintf(f,"The Linked List : ");
    printf("\nList Values\n");
    while(node!=NULL)
    {
        printf("%d ", node->value);
        fprintf(f,"%d--->",node->value);
        node=node->next;
    }
}
struct listnode *createList(int lengthOfList)
{
	FILE *f;
	char num[999];
	f= fopen("input.txt","r");
	fscanf(f,"%s",num);
    int i; 
    struct listnode *node, *space;
    space =  (struct listnode *) malloc( lengthOfList*sizeof(struct listnode));
    for( i=0; i< lengthOfList; i++ )
    {  (space + i)->value = atoi(num);
       (space + i)->next = space + (i+1);
       fscanf(f,"%s",num);
    }

    (space+(lengthOfList-1))->next = NULL;
    node = space;

    return node;
}
int main()
{
    struct listnode *node;

    node = createList(24);

    printf("Unsorted List\n");
    printList(node,"UnsortedList.txt");

    printf("\nSorted List\n");
    node =  Quicksort(node);


    printf("\nList Count node %d\n", ListLength(node));
    printList(node,"SortedList.txt");

   /* Brass_test(node);*/
}
