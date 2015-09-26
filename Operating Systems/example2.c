#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
   int fd;
   char buf[3] = "XY";
   fd = open("infile.txt",O_RDONLY);
   fork();
   read(fd, buf,1);
   read(fd, buf+1,1);
   close(fd);
   printf("%c%c\n",buf[0],buf[1]);
   return 0;
}