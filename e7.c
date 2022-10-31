#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<mqueue.h>
#include<string.h>
#define SIZE 256
void displaySignal(const char *signalname, int count)
{
    int mq_fd;
    char buf[SIZE];
    if((mq_fd=mq_open("/trafic12345", O_RDONLY|O_NONBLOCK))== -1)
    {
     perror("mq_open");
    }
    while(count >=0)
    {
        printf("%s=%d\n",signalname,count);
        sleep(1);
        count--;
        if(mq_receive(mq_fd,buf,SIZE,NULL)!= -1)
        {
            if(strcmp(buf,"red")== 0)
            {
                printf("Received Red signal\n");
                printf("Switching to red signal\n");
                displaySignal("red",30);
            }
            else if(strcmp(buf,"green")== 0)
            {
                printf("Received green signal\n");
                printf("Switching to green signal\n");
                displaySignal("green",30);
            }
            else if(strcmp(buf,"amber")== 0)
            {
                printf("Received amber signal\n");
                printf("Switching to amber signal\n");
                displaySignal("amber",30);
            }
            else
            {
                printf("unknown signal sent\n");
            }
        }
    }
}
int main()
{
    while(1)
    {
        displaySignal("red",60);
        displaySignal("green",40);
        displaySignal("amber",15);
    }
}
