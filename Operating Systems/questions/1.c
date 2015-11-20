#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char *x = "abcdefgh";
	printf("size = %d\n",sizeof(x));
	return 0;
}