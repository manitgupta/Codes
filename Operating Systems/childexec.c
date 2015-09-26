#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main()
{
	long forkresult;
	printf("%ld process intiated..\n",(long)getpid());
	//sleep(1);
	printf("%ld is going to fork now...\n",(long)getpid());
	//sleep(1);
	forkresult = fork();
	if (forkresult !=0)
	{
		printf("%ld is the father. It's child process is: %ld\n",(long)getpid(),(long)forkresult);
		printf("Now I will wait for his execution and then terminate myself as well\n");
		wait(NULL);	//This ensures that it waits for it's child execution to complete
		//and then exit, without this, the parent may finish earlier than child and it
		//may become a zombie process.
	}
	else
	{
		printf("I am %ld, I am the new born child\n",(long)getpid());
		sleep(1);
		printf("I will execute ls -l -a command now!!\n");
		sleep(1);
		execlp("ls","ls","-l","-a",NULL);
		printf("Failed!\n");
	}
}