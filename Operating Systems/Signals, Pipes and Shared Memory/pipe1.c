#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void main()
{
	int pfd[2];
	char buf[30];
	if(pipe(pfd)==-1)
	{
		perror("Error in creating pipe \n\n");
		exit(1);
	}
	printf("Writing to file des %d\n",pfd[1]);
	write(pfd[1],"Test",5);
	printf("Reading from file des %d\n",pfd[0]);
	read(pfd[0],buf,5);
	printf("Read: %s\n",buf);
}