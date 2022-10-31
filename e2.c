#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
int main()
{
int i;
int A[2],B[2];
pipe(A);
printf("A[0] = %d\n",A[0]);
printf("A[1] = %d\n",A[1]);
if(fork()==0)
{
char rbuf[40];
printf("child process\n");
read(A[0],rbuf,40);
printf("child read message = %s\n",rbuf);
write(A[1],"Hello Parent",40);
printf("child completes\n");
}
else
{
char buf[40];
printf("Parent Process\n");
write(A[1], "Hello Child",40);
printf("parent process writes\n");
read(A[0],buf,40);
printf("parent read message = %s\n",buf);
wait(0);
}
}
