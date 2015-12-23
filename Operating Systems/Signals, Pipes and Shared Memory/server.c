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
	//get ID and allocate segment.
	printf("Starting ****SERVER****\n");
	shmid = shmget(memkey,100*sizeof(char),IPC_CREAT|0666);
	if (shmid < 0)
	{
		perror("SHMGET ****SERVER****\n");
		exit(1);
	}
	//attach
	shm  = shmat(shmid,NULL,0); //first available addresss in process space.
	if (*shm == -1)
	{
		perror("SHMAT ****SERVER***\n");
		exit(1);
	}
	//write into it.
	s = shm; //points to first loc of shared mem.
	for(c = 'a'; c <= 'z'; c++)
		*s++ = c;
	s = NULL; //last char should be NULL.
	while(*shm != '*')
		sleep(1); //keep sleeping while first char is not *, check if first char is * after every 1 sec.
	shmdt(shm);
	shmctl(shmid,IPC_RMID,NULL);
	printf("Exiting ****SERVER****\n");
	exit(0);
}