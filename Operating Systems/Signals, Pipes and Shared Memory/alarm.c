#include <stdio.h>
void main()
{
	alarm(5);
	printf("Alarm Set, Looping Forever\n");
	while(1);
	printf("Should not be executed\n");
}