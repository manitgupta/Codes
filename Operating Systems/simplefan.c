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
	n = atoi(argv[1]);
	for(i = 1; i < n; i++)
	{
		if((childpid = fork()) <= 0)	// When child process is executing, chlidpid gets 0 when a child is created from parent process's fork() call.
			break;	//child breaks out from loop and moves onto fprintf and exits after sleeping
	}	
	//wait(NULL);
	fprintf(stderr, "i: %d process ID: %ld parent ID: %ld child ID: %ld\n", i, (long)getpid(),(long) getppid(), (long)childpid);
	sleep(30);	//so that the parent process does not finish itself while children are being created.
	return 0;
}