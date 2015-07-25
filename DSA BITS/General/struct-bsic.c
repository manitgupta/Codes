#include <stdio.h>
#include <string.h>


typedef struct 
{
	char title[50];
	char subject[100];
	char author[50];
	int book_id;
}Books;

void printBook(Books Book,int i)
{
   		printf("Book %d: %s %s  %s %d\n",i+1,Book.title,Book.author,Book.subject,Book.book_id);
}


int main()
{
	Books Book[2];

	strcpy( Book[0].title, "C Programming");
   	strcpy( Book[0].author, "Nuha Ali"); 
   	strcpy( Book[0].subject, "C Programming Tutorial");
   	Book[0].book_id = 6495407;

   	strcpy( Book[1].title, "Telecom Billing");
   	strcpy( Book[1].author, "Zara Ali");
   	strcpy( Book[1].subject, "Telecom Billing Tutorial");
   	Book[1].book_id = 6495700;

   	int i;
   	for (i = 0; i < 2; ++i)
   	{
   		printBook(Book[i],i);
   	}
	return 0;
}