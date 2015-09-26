#include<sys/wait.h>
#include<stdio.h>

int main()
{
	pid_t childpid;
	fork();
	childpid = wait(NULL);
	if(childpid != -1)
		printf("Waited for child with pid %ld, process pid: %ld\n", (long)childpid,(long)getpid());
	else
		printf("No child to wait for, process pid: %ld\n",(long)getpid());
}