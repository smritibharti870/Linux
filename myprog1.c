#include<stdio.h>
#include<unistd.h>
int main()
{
int i;
printf("hello and welcome to linux process\n");
printf("before fork\n");
i=fork();
if(i==0)
{
printf("Child process\n");
printf("Child process ID in child process = %d\n",getpid());
printf("Parent process ID in child process = %d\n",getpid());
printf("End of child\n");
}
else
{
printf("Parent Process\n");
printf("child process ID in parent process = %d\n",i);
printf("parent process ID in parent process = %d\n",getpid());
}
while(1);
}
