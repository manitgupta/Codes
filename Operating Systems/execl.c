#include <stdio.h>
#include <unistd.h>

void main()
{
	printf("Commencing exec function ls -l -a in 3 secs....\n");
	sleep(3); 
	execl("/bin/ls","ls","-l","-a",NULL);
	printf("EXEC Failed\n");
}