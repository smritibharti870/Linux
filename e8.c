#include<stdio.h>
#include<fcntl.h>
#include<mqueue.h>
#include<stdlib.h>
#define MAXSIZE 10
#define SIZE 256
int main()
{
int mq_fd,prio;
struct mq_attr m1;
char buf[SIZE];
m1.mq_maxmsg=MAXSIZE;
m1.mq_msgsize=SIZE;
if((mq_fd=mq_open("/cri1234",O_WRONLY|O_CREAT,0777,&m1))==-1)
{
perror("mq_open");
exit(0);
}
else
{
printf("message queue description= %d\n",mq_fd);
printf("enter the priority= ");
scanf("%d",&prio);
__fpurge(stdin);
printf("enter message text: ");
fgets(buf,256,stdin);
mq_send(mq_fd,buf,SIZE,prio);
close(mq_fd);}
}
