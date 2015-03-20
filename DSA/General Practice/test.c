#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	char a[30] = "Hello";
	char b[10] = "Jello";
	char *c;
	c = strcat(a,b);
	printf("%s\n",c);
	return 0;

}