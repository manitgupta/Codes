#include <unistd.h>
#include <fcntl.h>

int main()
{
	int i=0;
	int fd;
	for (i = 0; i < 1024; ++i)
	{
		fd = open("input.txt",O_RDWR);
		if (fd == -1)
		{
			write(STDOUT_FILENO,"ERROR",6);
			break;
		}
	}
	//Error occurs at the point in loop when all 1024 file descriptors have been
	//allocated. Remember 3 are already reserved.
	return 0;		
}