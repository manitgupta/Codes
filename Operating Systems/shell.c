#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXARG 20
#define MAXCMD 100

int make_args(int *argc_ptr, char *argv[],int max)
{
	static char cmd[MAXCMD];
	char *cmd_ptr;
	int i=0;
	fgets(cmd,sizeof(cmd),stdin);	//get the command from stdin to array of chars: cmd
	cmd_ptr = cmd;		//cmd_ptr points to same array as cmd.
	for (i = 0; i < max; ++i)
	{
		if((argv[i] = strtok(cmd_ptr," \t\n")) == NULL)	//tokenize by space, tab or new line
			break;
		cmd_ptr = NULL;
	}
	*argc_ptr = i; //no. of args = value of i.
	return 1;
}

int main()
{
	char *argv[MAXARG];
	int argc;
	int i=0;
	while(1)
	{
		printf("@ ");
		if(make_args(&argc,argv,MAXARG) && argc > 0)
		{
			int forkresult;
			if((forkresult=fork())!=0)
				wait(NULL);	//parent process, wait for child execution.
			else
				execvp(argv[0],argv);	//child process's context gets replaced by executing program.
		}
		else
			printf("Error making args\n");
	}
	return 0;
}