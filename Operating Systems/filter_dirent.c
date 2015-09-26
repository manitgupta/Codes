#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//List only .c files

int filter(const struct dirent *entry)
{
	const char *name = entry->d_name;
	if(name[strlen(name)-1] == 'c' && name[strlen(name)-2] == '.')
		return 1;
	else
		return 0;
}

int main()
{
	struct dirent **namelist;
	int n;
	n = scandir(".",&namelist,filter,alphasort);	//returns the no. of files in directory.
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