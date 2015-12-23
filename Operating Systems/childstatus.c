#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
void myhandler(int signo)
{
	printf("Signal interrupt recieved %d\n",signo);
	exit(signo);
}
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
		int i;
		// for(i=1;i<32;i++)
		// {	
		// 	signal(i,myhandler);
		// }
		printf("Hi coming from the child process %ld\n",(long)getpid());
		//printf("Will exit with code 42!\n");
		printf("Infinite Loop\n");
		for(;;);

		exit(42);
	}
	else
	{
		int i;
		for(i=1;i<32;i++)
		{
			signal(i,SIG_IGN);
		}
		signal(SIGCHLD,SIG_DFL);
		childpid = wait(&status);
		if (WIFSIGNALED(status))
		{
			printf("Interuppted by %d\n",WTERMSIG(status));
		}
		else
			printf("Child Exit Code was %d and it's ID was %d\n",WEXITSTATUS(status),childpid);
	}
	return 0;
}