#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
int main()
{
int cd,sd;
struct sockaddr_in s1;
char buff[200];
if((sd = socket(AF_INET,SOCK_STREAM,0)) == -1)
{
perror("socket");
}
s1.sin_family = AF_INET;
s1.sin_port = 9979;
s1.sin_addr.s_addr = inet_addr("10.75.58.32");
if(bind(sd,(struct sockaddr *)(&s1),sizeof(s1)) == -1)
{
perror("bind");
}
else
{
listen(sd,50);
printf("server is listening\n");
while(1)
{
if(fork()==0)
{
cd = accept(sd,0,0);
while(1)
{
read(cd,buff,200);
printf("%s is successfully booked!\n",buff);
sleep(1);
}}
else
{
close(cd);
}}
}}


