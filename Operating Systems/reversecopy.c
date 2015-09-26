#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int source,dest,n;
	char buf;
	int filesize;
	int i;

	if (argc !=3)
	{
		fprintf(stderr,"Usage %s <source> <dest> \n",argv[0]);
		exit(-1);
	}
	if ((source = open(argv[1],400)) <0)	//1st
	{
		fprintf(stderr,"Cant Open Source");
		exit(-1);	
	}
	if ((dest = creat(argv[2],700)) < 0)		//2nd
	{
		fprintf(stderr,"Cant Open Dest");
		exit(-1);
	}
	filesize = lseek(source,0,SEEK_END);
	printf("Source file is of size %d\n",filesize);
	for (i = filesize - 1; i >= 0; i--)
	{
		lseek(source,i,SEEK_SET);
		n = read(source,&buf,1);
		if (n != 1)
		{
			printf("%d\n",n);
			fprintf(stderr, "Cannot read 1 byte\n");
			exit(-1);
		}
		n = write(dest,&buf,1);
		if (n != 1)
		{
			printf("%d\n",n);
			fprintf(stderr, "Cannot write 1 byte\n");
			exit(-1);
		}
	}
	write(STDOUT_FILENO,"DONE\n",5);
	// int x,y;
	// x = truncate(argv[1],0);
	// printf("%s truncated x = %d\n",argv[1],x);
	close(source);
	close(dest);
	return 0;
}