#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
	printf("Start of Test\n");
	int cnt=0;
	int pid;
	for(cnt=0;cnt<3;cnt++){
		pid=fork();
		printf("Now in process %d\n",getpid());
	}
	return 0;
}