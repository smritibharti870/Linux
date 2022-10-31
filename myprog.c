#include<stdio.h>
#include<unistd.h>
int main()
{
int i;
printf("hello & welcome to linux process\n");
printf("before fork\n");
fork();
printf("after fork\n");
printf("bye\n");
while(1);
}
