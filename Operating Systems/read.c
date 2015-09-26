#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
   int fd;
   char buf[5] = "WXYZ";
   fd = open("infile.txt",O_RDONLY);
   read(fd, buf,2);
   read(fd, buf+2,2);
   close(fd);
   printf("%c%c%c%c\n",buf[0],buf[1],buf[2],buf[3]);
   return 0;
}