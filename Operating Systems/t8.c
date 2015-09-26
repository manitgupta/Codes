#include <unistd.h>
#include <stdio.h>

int main()
{
	int x;
	x = 0;
	fork();
	x = 1;
	printf("Hi! I am the Process %ld, my parent is %ld and value of x for me is %d\n",(long)getpid(),(long)getppid(),x);
	return 0;
}