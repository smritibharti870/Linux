#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
int sd;
char wbuf[300];
struct sockaddr_in s1;
if((sd=socket(AF_INET,SOCK_STREAM,0))==-1)
{
  perror("socket");
}
s1.sin_family=AF_INET;
s1.sin_port= 9979;
s1.sin_addr.s_addr=inet_addr("10.75.58.32");
if(connect(sd,(struct sockaddr*)(&s1),sizeof(s1))==-1)
{
   perror("connect");
}
else
{
while(1)
{
printf("write a msg to server2\n");
gets(wbuf);
write(sd,wbuf,300);
}
close(sd);
}
}

