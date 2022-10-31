#include<stdio.h>
#include<sys/mman.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
int shm_fd,i;
sem_t *sem_fd;
char *ptr;
if((shm_fd=shm_open("/bharti17111",O_RDWR,0777))==-1)
{
perror("shm_open");
}
else
{
if((sem_fd=sem_open("/tataelxsi12345",O_RDWR)) == SEM_FAILED)
{
perror("sem_open");
}
else
{
printf("process2 trying to take a semaphore\n");
/*while(sem_trywait(sem_fd) == -1)
{
perror("sem_trywait");
printf("we will do something else\n");
sleep(1);
}*/
sem_wait(sem_fd);
printf("process2 takes a semaphore\n");
ptr=mmap(0,4096,PROT_READ,MAP_SHARED,shm_fd,0);
for(i=0;*(ptr+i)!='\0';i++)
{
printf("%c\n",*(ptr+i));
sleep(1);
}
printf("process2 finished reading\n");
sem_post(sem_fd);
printf("process2 release the semaphore\n");
}
}
}
