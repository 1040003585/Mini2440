#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>
int main(void)
{
   int fd;
   int i = 0;
   fd = open("/dev/leds",O_RDONLY);
   if(fd==-1)
   {
      perror("open failed");
      exit(1);
   }
   while(1)
   {
       ioctl(fd,0,0);
       ioctl(fd,0,1);
       ioctl(fd,0,2);
       ioctl(fd,0,3);
       sleep(1);
       ioctl(fd,1,0);
       ioctl(fd,1,1);
       ioctl(fd,1,2);
       ioctl(fd,1,3);
       sleep(1);
   }
   return 0;
}
