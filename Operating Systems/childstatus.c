#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	int pid;
	int status=0;
	int childpid;
	printf("Hello World\n");
	pid = fork();
	if (pid == -1)
	{
		perror("bad fork, exit with code 1");
		exit(1);
	}
	if (pid == 0)//child
	{
		printf("Hi coming from the child process %ld\n",(long)getpid());
		printf("Will exit with code 42!\n");
		exit(42);
	}
	else
	{
		childpid = wait(&status);
		printf("Child Exit Code was %d and it's ID was %d\n",WEXITSTATUS(status),childpid);
	}
	return 0;
}