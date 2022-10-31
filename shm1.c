#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<string.h>

int main()
{
int shm_fd;
char *ptr;
char buf[100];
if((shm_fd=shm_open("/mysmriti",O_RDWR|O_CREAT,0777))==-1)
{
perror("shm_open");
}
else
{
printf("shared memory descriptor = %d\n",shm_fd);
ftruncate(shm_fd,4096);
ptr=mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
while(1)
{
gets(buf);
strcpy(ptr,buf);
}
munmap(ptr,4096);
printf("message sent to shared memory\n");
}
}
