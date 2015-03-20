#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int i,n,*ptr,sum=0;
	printf("Enter no. of elements:\n");
	scanf("%d",&n);
	ptr = (int*)malloc(sizeof(int)*n);		//allocate memory. We can also run a for loop for the length of the array and allocate memory to each.
	if(ptr==NULL)
	{
		printf("No memory Allocated!\n");
		exit(0);
	}
	printf("Enter elements of Array:\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d",&ptr[i]); // this can be done or (ptr+i) is also fine.
		sum+=*(ptr+i);
	}
	printf("Sum = %d\n",sum);
	return 0;
}