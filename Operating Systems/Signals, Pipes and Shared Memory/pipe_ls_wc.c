#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	int pfd[2];
	pipe(pfd);
	int pid = fork();
	if (pid == 0)	//child, calls ls -l
	{
		close(1); //close normal STDOUT of child.
		dup(pfd[1]); //make STDOUT same as the pipe OUT.
		close(pfd[0]); //close reading end, since not required.
		execlp("ls","ls","-l",NULL);
	}
	else	//parent, calls wc
	{
		close(0); //close normal STDIN of parent.
		dup(pfd[0]);
		close(pfd[1]); //close writing end, since not required.
		execlp("wc","wc","-l",NULL);
	}
}