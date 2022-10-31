#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<mqueue.h>
#include<unistd.h>
#define SIZE 256
int main()
{
int mq_fd1,mq_fd2,i;
char rbuf[500];
char wbuf[500];
struct mq_attr m1;
m1.mq_maxmsg=10;
m1.mq_msgsize=SIZE;
if((mq_fd1=mq_open("/smriti1",O_RDONLY))==-1);
{
perror("mq_open");
}
if(( mq_fd2=mq_open("/smriti2",O_WRONLY|O_CREAT,0777,&m1))==-1);
{
perror("mq_open");
}
printf("mq_fd1 = %d\n",mq_fd1);
printf("mq_fd2 = %d\n",mq_fd2);
i=fork();
if(i==0)
{
while(1)
{
mq_receive(mq_fd1,rbuf,SIZE,NULL);
printf("%s\n",rbuf);
}
}
else
{
while(1)
{
gets(wbuf);
mq_send(mq_fd2,wbuf,SIZE,112);
}
} 
}
                                        



                                               close(mq_fd1);
                                                close(mq_fd2);
                                                                        


