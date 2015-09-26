#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
	printf("Hello World\n");
	fflush(stdout);
	execl("/bin/echo","echo","Hey","People",NULL);

}