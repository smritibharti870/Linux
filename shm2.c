#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int shm_fd;
char *ptr;
if((shm_fd=shm_open("/mysmriti",O_RDWR,0777))==-1)
{
perror("shm_open");
}
else
{
printf("shared memory ID = %d\n",shm_fd);
ptr=mmap(0,4096,PROT_READ,MAP_SHARED,shm_fd,0);
printf("read data from shared memory = %s\n",ptr);
munmap(ptr,4096);
}
}
