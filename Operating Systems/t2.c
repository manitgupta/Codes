#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFERSIZE 4096

void err_sys(const char* x) 
{ 
    perror(x); 
    exit(1); 
}

int main()
{
	int n;
	char buf[BUFFERSIZE];
	while ((n = read(STDIN_FILENO,buf,BUFFERSIZE)) > 0)		//for continously accepting input
		if (write(STDOUT_FILENO,buf,n) != n)
			err_sys("write error");
	if (n<0)
		err_sys("read error");
	exit(0);
}