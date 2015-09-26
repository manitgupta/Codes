#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
void main()
{
	pid_t whichone, first, second ;
	int howmany, status ;
	if((first = fork()) == 0) /* Parent spawns 1st child */ 
	{
		printf("I am the first child, & my ID is %d\n", getpid());
		sleep(5);
		exit(0); 
	}
	else if(first == -1) 
	{
		perror("1st fork: something went wrong\n") ;
		exit(1);
	}
	else if((second = fork()) == 0) /* Parent spawns 2nd child */ 
	{
		printf("I am the second child, & my ID is %d\n", getpid( ));
		sleep(10);
		exit(0);
	}
	else if (second == -1)
	{
		perror ("2nd fork: something went wrong\n") ;
		exit(1);
	}
	printf("This is parent %d\n",getpid());
	howmany = 0;
	while(howmany < 2) /* Important!!! : This loop ensures that all the children exit before parent!!*/
	{
		whichone = wait(&status);	//returns the pid of exiting child's process.
		howmany++;
		if(whichone == first)
			printf("First child exited\n");
		else
			printf("Second child exited\n");
		if((status & 0xffff) == 0)
			printf("correctly\n");
		else
			printf("Incorrectly\n");
	}
	printf("My children are dead, might as well kill myself too!\n");
	exit(0);
}