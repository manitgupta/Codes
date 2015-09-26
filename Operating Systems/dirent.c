#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Directory list is sorted order.
int main()
{
	struct dirent **namelist;
	int n;
	n = scandir(".",&namelist,NULL,alphasort);	//returns the no. of files in directory.
	if (n < 0)
		printf("scandir error\n");
	else
	{
		int i=0;
		while(i < n)
		{
			printf("%s\n",namelist[i++]->d_name);
		}
	}
	return 0;
}