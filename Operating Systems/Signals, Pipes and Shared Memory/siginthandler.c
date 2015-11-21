#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sigint_handler(int signo)
{
	printf("Caught SIGINT : %d\n",signo);
	//pause();
	//exit(EXIT_SUCCESS);
}

int main()
{
	if(signal(SIGINT,sigint_handler)==SIG_ERR)
	{
		fprintf(stderr, "Cannot handle SigINT\n");
		exit(EXIT_FAILURE);
	}
	//for(;;)
	//	{
	//		printf("Going to sleep...\n");
	//		sleep(1);
	//	}
	// {
	// 	printf("Loop\n");
	// }
	for(;;)
		pause();
	//printf("Hello\n");
	
	return 0;
}