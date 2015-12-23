#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void main()
{
	int pfd[2];
	int nread;
	//create a pipe
	char text[50] = "Hello from Parent";
	if(pipe(pfd) == -1)
	{
		perror("Pipe Failed!\n");
		exit(1);
	}
	//Fork to create a child.
	int forkresult = fork();
	if (forkresult !=0)//parent, it is the writer thread.
	{
		close(pfd[0]);	//read end not required for parent.
		//strcpy(text,"Hello from Parent");
		write(pfd[1],text,strlen(text)+1);//write into pipe from the parent.
		close(pfd[1]);	//close writing end of parent 
	}
	//On forking, both the child and the parent get there own copies of the variables, hence text[50] is different for the parent
	//and for the child.
	else	//child thread
	{
		//sleep(2);
		close(pfd[1]); //writing end not required for child.
		//While loop to ensure that the child does not exit before the parent writes onto pipe.
		//Instead of while we can also use wait(NULL) in the parent thread.
		while((nread = read(pfd[0],text,1024))!=0);	//read into text.
		//read(pfd[0],text,1024);
		printf("Read from Pipe : %s\n",text);
		close(pfd[0]);
	}
}