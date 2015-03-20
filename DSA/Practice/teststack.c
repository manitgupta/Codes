#include <stdio.h>
 
#include "stack.h"
 
/* Author : Manit Gupta
   Program : Driver Program for Stack Implementation using Linked Lists.
*/

int main()
{
    NODE* Head = NULL;
    int size, element;
    int counter = 0;
 
    printf("Enter the number of stack elements:");
    scanf("%d",&size);
 
    printf("--- Push elements into the linked stack ---\n");
 
    init(Head);
 
    while(counter < size)
    {
 
        printf("Enter a number to push into the stack:");
        scanf("%d",&element);
        Head = push(Head,element);
        display(Head);
        counter++;
    }
 
    printf("--- Pop elements from the linked stack --- \n");
    while(empty(Head) == 0)
    {
        Head = pop(Head,element);
        printf("Pop %d from stack\n",element);
        display(Head);
    }
 
    return 0;
}