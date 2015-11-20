#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("infile.txt",O_RDONLY);
	int forkresult = fork();
	char buf[3] = "XY";
	read(fd, buf,2);
   	//read(fd, buf+1,1);
   	printf("%c%c\n",buf[0],buf[1]);
	if(forkresult!=0)
	{
		printf("fd for parent = %d\n",fd);
	}
	else
		printf("fd for child = %d\n",fd);
	close(fd);
	return 0;
}