#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
int i,wbuf[100],rbuf[100];
int A[2],B[2];
pipe(A);
printf("A[0] = %d\n",A[0]);
printf("A[1] = %d\n",A[1]);
printf("enter a string::\n");
gets(wbuf);
if(fork()==0)
{
//char rbuf[40];
printf("child process\n");
read(A[0],rbuf,40);
printf("child read message = %s\n",rbuf);
write(A[1],wbuf,40);
printf("child completes\n");
}
else
{
//char wbuf[100];
printf("Parent Process\n");
write(A[1], wbuf,100);
printf("parent process writes\n");
read(A[0],rbuf,100);
printf("parent read message = %s\n",wbuf);
wait(0);
}
}

