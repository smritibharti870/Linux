#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<sys/time.h>
void print_time()
{
struct timeval tsc;
struct tm *ptm;
char time_string[40];
/*Obtain the time of day, and convert it to a tm struct. */
gettimeofday (&tsc, NULL);
printf("%ld\n",tsc.tv_sec);
ptm=localtime (&tsc.tv_sec);
strftime (time_string, sizeof (time_string), "%d-%m-%y %H::%M::%S",ptm);
printf("%s\n", time_string);
}
int main()
{
printf("timers\n");
while(1)
{
printf("in while loop\n");
print_time();
sleep(5);
}
}
