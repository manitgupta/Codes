#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
	char c;
	int shmid;
	key_t memkey = 5678;
	char *shm,*s;

	shmid = shmget(memkey,100*sizeof(char),0666); //no need for IPC_CREAT. We need just read and write permission.
	if (shmid < 0)
	{
		perror("SHMGET ****CLIENT****\n");
		exit(1);
	}
	//attach
	shm  = shmat(shmid,NULL,0); //first available addresss in process space.
	if (*shm == -1)
	{
		perror("SHMAT ****CLIENT***\n");
		exit(1);
	}
	for (s = shm; *s != NULL; s++)	
		putchar(*s);
	putchar('\n');
	/* Finally, change the first character of the
	* segment to '*', indicating we have read
	* the segment.
	*/
	*shm = '*';
	printf ("\n Its done from client.\n\n\n");
	shmdt(shmid);
	exit(0);
}