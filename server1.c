
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>

int main()
{
int sd,cd;
int count=0;
char buf[256];
struct sockaddr_in s1;
if((sd=socket(AF_INET,SOCK_STREAM,0))==-1)
{
perror("socket");
}
s1.sin_family=AF_INET;
s1.sin_port=9972;
s1.sin_addr.s_addr=inet_addr("10.75.58.32");
if(bind(sd,(struct sockaddr *)(&s1),sizeof(s1))==-1)
{
perror("bind");
}
listen(sd,50);
printf("Server is in listening mode\n");
while(1)
{
printf("Waiting for clients\n");
cd=accept(sd,0,0);
count++;
printf("client request accepted\n");
if(fork()==0)
{
while(1)
{
read(cd,buf,256);
printf("read data from client%d= %s\n",count,buf);
strcat(buf,"from smriti");
write(cd,buf,256);
}
}
else
{
close(cd);
}
}
close(sd);
}


