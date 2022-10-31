#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<mqueue.h>
#define SIZE 256
int main()
{
int choice;
int mq_fd;
struct mq_attr m1;
m1.mq_maxmsg=10;
m1.mq_msgsize=SIZE;
if((mq_fd=mq_open("/trafic12345",O_WRONLY|O_CREAT,0777,&m1))==-1)
{
perror("mq_open");
}
else
{
while(1)
{
printf("1 : red\n2 : green\n3 : amber\n0 : exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
mq_send(mq_fd,"red",SIZE,123);
printf("red signal sent\n");
break;
case 2:
mq_send(mq_fd,"green",SIZE,123);
printf("green signal sent\n");
break;
case 3:
mq_send(mq_fd,"amber",SIZE,123);
printf("amber signal sent\n");
break;
case 0:
printf("exiting the application\n");
exit(0);
default:
printf("wrong choice\n");
printf("please check the menu and enter accordingly\n");
}//end of switch
}//end of while
}//end of else
}//end of main

