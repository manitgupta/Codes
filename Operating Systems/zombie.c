#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main() 
{
	int pid;
	printf("%d:Parent Process\n",getpid());
	pid = fork(); /* Duplicate. Child and parent continue from here */
	if ( pid != 0 ) /* pid is non-zero, so I must be the parent */ 
	{
		while (1) /* Never terminate and never execute a wait ( ) */
		sleep (100) ; /* stop executing for 100 seconds */
	}
	else /* pid is zero, so I must be the child */ 
	{
		printf("I am the exiting child process %d, My parent was %d\n",getpid(),getppid());
		exit (42) ; /* exit with any number */
	}
}

/*Execute ./a.out in one terminal
Execute ps -a in the other simultaneously, a defunct process with SAME pid as the child 
can be seen until the above program is executing*/