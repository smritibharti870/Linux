#include<stdio.h>
#include<fcntl.h>
#include<mqueue.h>
#include<stdlib.h>
#include<unistd.h>
#define MAXSIZE 10
#define SIZE 256

int main()
{
int mq_fd;
struct mq_attr m1;
m1.mq_maxmsg=MAXSIZE;
m1.mq_msgsize=SIZE;
char buf[SIZE];
int prio;
if((mq_fd=mq_open("/myqueue123",O_WRONLY|O_CREAT,0777,&m1))==-1)
{
perror("mq_open");
exit(0);
}
else
{
printf("Message queue descriptor = %d\n",mq_fd);
printf("Enter Message priority :: ");
scanf("%d",&prio);
__fpurge(stdin);
printf("Enter Message Text :: ");
fgets(buf,256,stdin);
mq_send(mq_fd,buf,SIZE,prio);
close(mq_fd);
}
}
