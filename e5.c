#include<stdio.h>
#include<fcntl.h>
#include<mqueue.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int num,k;
int mq_fd;
char buf[SIZE];
if((mq_fd=mq_open("/myqueue123",O_RDONLY|O_NONBLOCK))==-1)
{
perror("mq_open");
exit(0);
}
else
{
printf("Message Queue Descriptor = %d\n",mq_fd);
while(1)
{
if(mq_receive(mq_fd,buf,SIZE,&num) == -1)
{
perror("mq_receive");
printf("process will do something\n");
sleep(1)
}
else
{
printf("Read message from message queue\n");
printf("Read message priority =%d\n",mq_fd);
break;
}
}
