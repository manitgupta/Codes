#include <dirent.h> 	
#include <stdio.h>
#include <string.h>
//PROGRAM TO MIMIC LS COMMAND
int main()
{
	struct dirent *direntp;	//pointer to dirent struct for traversal inside dir.
	DIR *dirp;	// open file, similar to FILE* fp;
	dirp = opendir("."); //Open current directory.	//dirp would be pointing to first entry in directory.
	while((direntp = readdir(dirp))!=NULL)	//NULL if unable to return pointer to dirent struct.
	{
		if (strcmp(direntp->d_name,".") && strcmp(direntp->d_name,".."))	//to exclude . and .. directories
			printf("%s\n",direntp->d_name);
	}
	closedir(dirp);
	return 0;
}