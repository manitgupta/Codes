#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char* argv[]) 
{
	pid_t childpid = 0;
	int i, n;
	/*check for valid number of command line arguments*/
	if(argc != 2)
	{
		fprintf(stderr, "Usage %s processes\n", argv[0]);
		return 1;
	}
	n = atoi(argv[1]);	//convert entered number to int..
	for(i = 1; i < n; i++)
		if(childpid = fork())
			break;
	fprintf(stderr, "i: %d process ID: %ld parent ID: %ld child ID: %ld\n", i, (long)getpid(),(long) getppid(), (long)childpid);
	//sleep(30);
	wait(NULL);
	return 0;
}