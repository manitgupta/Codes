#include <stdio.h>
#include <unistd.h>

void main()
{
	printf("Commencing exec function ls -l -a in 1 secs....\n");
	sleep(1); 
	//execl("/bin/ls","ls","-l","-a",NULL);
	execlp("ls","ls","-l","-a",NULL);
	printf("EXEC Failed\n");
}