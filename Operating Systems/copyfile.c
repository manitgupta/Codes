#include <stdio.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

#define BUFFERSIZE 4096
int main(int argc, char **argv)
{
	int read_bytes,n,fd,fd1;
	char buf[BUFFERSIZE];
	char *pathname = "some.txt";
	fd = open(pathname,O_RDONLY);
	if (fd == -1)
	{
		printf("Error Opening %s\n",pathname);
		return 1;
	}
	//while(1)
	//{
		read_bytes = read(fd,buf,BUFFERSIZE);	//read from file and stored in buf, number of chars read stored in read_bytes.
		//if(!read_bytes)
		//	break;
		if(read_bytes == -1)
		{
			printf("Error Reading %s\n",pathname);
			return 2;
		}
		//fd1 = open("new.txt",O_WRONLY|O_TRUNC|O_CREAT); //This executes creating a file for which we do not have permission
		fd1 = creat("new.txt",777);
		n = write(fd1,buf,read_bytes);		//write into file pointed by fd1 from buffer buf till read_bytes no. of chars.
		if(n == -1)
		{
			printf("Error writing to new.txt\n");
			return 3;
		}
	//}
	close(fd);
	close(fd1);
	return 0;
}