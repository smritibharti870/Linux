#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<mqueue.h>
#include<stdlib.h>
#define SIZE 256
int main()
{
int mq_fd1, mq_fd2, i;
char wbuf[256], rbuf[256];
struct mq_attr m1;
m1.mq_maxmsg=10;
m1.mq_msgsize=SIZE;
if((mq_fd1=mq_open("/smriti1",O_WRONLY|O_CREAT, 0777,&m1))==-1)
{
perror("mq_open");
}
if((mq_fd2=mq_open("/smriti2",O_RDONLY))==-1)
{
perror("mq_open");
}
printf("mq_fd1=%d\n",mq_fd1);
printf("mq_fd2=%d\n",mq_fd2);
i=fork();
if(i==0)
{
while(1)
{
gets(wbuf);
mq_send(mq_fd1,wbuf,SIZE,123);
}
}
else
{
while(1)
{
mq_receive(mq_fd2,rbuf,SIZE,NULL);
printf("%s\n",rbuf);
}
}
close(mq_fd1);
close(mq_fd2);
}
