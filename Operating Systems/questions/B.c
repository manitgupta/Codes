 #include<stdio.h>
   #include<fcntl.h>
 
   int main()
   {     
       int fd, count;
       fd = open("infile.txt",O_RDONLY);
       count = write(fd,"Linux",5);
       if(count != 5)
           perror("write");
       return 0;
   }